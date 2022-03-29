/********************************** (C) COPYRIGHT *******************************
 * File Name          : main.c
 * Author             : WCH
 * Version            : V1.1
 * Date               : 2020/08/06
 * Description        : 外设从机应用主函数及任务系统初始化
 *******************************************************************************/

/******************************************************************************/
/* 头文件包含 */
#include "CONFIG.h"
#include "CH57x_common.h"
#include "HAL.h"
#include "gattprofile.h"
#include "peripheral.h"


#define MAXTASKS 3
volatile unsigned short timers[MAXTASKS];
#define _SS static unsigned char _lc=0; switch(_lc){default:
#define _EE ;}; _lc=0; return 65535;

#define WaitX(tickets)  do { _lc=(__LINE__%255)+1; return (tickets) ;case (__LINE__%255)+1:;} while(0)
#define WaitUntil(A)    do { while(!(A)) WaitX(1);} while(0)
#define WaitUtilT(A,TimeOut)  do { static unsigned short _count=(TimeOut); do { WaitX(1); _count--; } while((!(A))&&(_count>0));} while(0)

#define RunTask(TaskName,TaskID)    {if (timers[TaskID]==0) { unsigned short d=TaskName(); while(timers[TaskID]!=d) timers[TaskID]=d;}}
#define RunTaskA(TaskName,TaskID)   {if (timers[TaskID]==0) {unsigned short d=TaskName(); while(timers[TaskID]!=d) timers[TaskID]=d; continue;}}

#define CallSub(SubTaskName) do {unsigned short currdt; _lc=(__LINE__%255)+1; return 0; case (__LINE__%255)+1:  currdt=SubTaskName(); if(currdt!=65535) return currdt;} while(0)
#define InitTasks() do {unsigned char i; for(i=MAXTASKS;i>0 ;i--) timers[i-1]=0; } while(0)
#define UpdateTimers() do{unsigned char i; for(i=MAXTASKS;i>0 ;i--){if((timers[i-1]!=0)&&(timers[i-1]!=65535)) timers[i-1]--;}} while(0)

__attribute__((aligned(4)))  u32 MEM_BUF[BLE_MEMHEAP_SIZE / 4];

#if (defined (BLE_MAC)) && (BLE_MAC == TRUE)
u8C MacAddr[6] = {0x84,0xC2,0xE4,0x03,0x02,0x02};
#endif

extern void app_uart_process(void);
extern void app_uart_init(void);

/*******************************************************************************
 * Function Name  : Main_Circulation
 * Description    : 主循环
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
#define LED0_PIN GPIO_Pin_9
#define LED1_PIN GPIO_Pin_15

signed short RoughCalib_Value = 0;    // ADC粗调偏差值
UINT16 abcBuff[400];
volatile UINT8 adclen;


int pwmTotal=100;
int pwmValue;

unsigned short  task0(){
  static int i;
_SS
  while(1){
      GPIOB_ModeCfg( LED0_PIN, GPIO_ModeOut_PP_5mA);
      WaitX(1000);//1s

      GPIOB_ModeCfg( LED0_PIN, GPIO_ModeOut_PP_5mA);
      GPIOB_ResetBits(LED0_PIN);//set to low

      WaitX(2000);//2s
      GPIOB_SetBits(LED1_PIN);
  }
_EE
}

#define BLE_BUFF_MAX_LEN                        27
#define UART_TO_BLE_SEND_EVT                              0x0010

extern uint8_t to_test_buffer[];
extern uint8 Peripheral_TaskID;
extern void sendadc();
//extern app_drv_fifo_result_t app_drv_fifo_read(app_drv_fifo_t *fifo, uint8_t *data, uint16_t *p_read_length);
//extern static app_drv_fifo_t app_uart_rx_fifo;
unsigned short  task1(){
 static int i;
 static int wlen;
 static char send_buffer[50];
_SS

ADC_ChannelCfg( 0 );
while(1){
    for( i = 0; i < 50; i++ )
    {
        WaitX(10);
      //  abcBuff[i] = ADC_ExcutSingleConver() + RoughCalib_Value;      // 连续采样20次
    }
    int sum=0;
    for( i = 0; i < 50; i++ )
    {
      //PRINT( "%d \n", abcBuff[i] ); // 注意：由于ADC内部偏差的存在，当采样电压在所选增益范围极限附近的时候，可能会出现数据溢出的现象

        //app_drv_fifo_write(&app_uart_tx_fifo,to_test_buffer,&read_length);
        //read_length = 0;
        //tmos_start_task( Peripheral_TaskID, UART_TO_BLE_SEND_EVT,2);
        //app_drv_fifo_read(&app_uart_rx_fifo,to_test_buffer,&wlen);
         //WaitX(5000);
        sum+=abcBuff[i];
    }
    sprintf(to_test_buffer,"AIN0=%d\r\n",((sum/50)-920)/2);
    wlen = strlen(to_test_buffer);

    //sendadc();
    WaitX(5000);
  }
_EE
}


extern int OPEN_KEY,CLOSE_KEY;

unsigned short outbit1(){
_SS
    GPIOB_SetBits(LED1_PIN);//set to low
    WaitX(12);//1.2ms
    GPIOB_ResetBits(LED1_PIN);//set to low
    WaitX(4);//0.4ms
_EE
}

unsigned short outbit0(){
_SS
    GPIOB_SetBits(LED1_PIN);//set to low
    WaitX(4);//0.4ms
    GPIOB_ResetBits(LED1_PIN);//set to low
    WaitX(12);//1.2ms
_EE
}

uint32_t keybits,i1,idlecount,outpp_flag;
unsigned short task2(){
    static int i;
_SS
   while(1){
    WaitX(1);
    if((OPEN_KEY+CLOSE_KEY)==0){
        GPIOB_InverseBits( LED1_PIN );
        WaitX(1);
        if(idlecount++>500){
            GPIOB_ModeCfg( LED1_PIN, GPIO_ModeIN_PU);
        }
    }
    if(OPEN_KEY==1){
        OPEN_KEY=0;
        idlecount = 0;
        GPIOB_ModeCfg( LED1_PIN, GPIO_ModeOut_PP_5mA);
        mDelayuS(200);
        //WaitX(2);
        GPIOB_ResetBits(LED1_PIN);//set to low
        WaitX(110);//11ms
        keybits=0x11634a08;
        i1=1;
        for(i=30;i>=0;i--){
            if((keybits&(i1<<i))==0) CallSub(outbit0);
            else CallSub(outbit1);
        }
        WaitX(10);//1ms
    }
    if(CLOSE_KEY==1){
        CLOSE_KEY=0;
        idlecount = 0;
        GPIOB_ModeCfg( LED1_PIN, GPIO_ModeOut_PP_5mA);
        mDelayuS(200);
        //WaitX(2);
        GPIOB_ResetBits(LED1_PIN);//set to low
        WaitX(110);//8ms
        keybits=0x11634908;
        i1=1;
        for(i=30;i>=0;i--){
            if((keybits&(i1<<i))==0) CallSub(outbit0);
            else CallSub(outbit1);
        }
        WaitX(10);//2ms
    }
  }
_EE
}


__attribute__((section(".highcode")))
void Main_Circulation() {
    while (1) {
        TMOS_SystemProcess();
        app_uart_process();

        DelayUs(10);
        //UpdateTimers();
        //RunTask(task0,0);
        //if(outpp_flag==1) GPIOA_ModeCfg( LED0_PIN, GPIO_ModeOut_PP_5mA);
        //else GPIOA_ModeCfg( LED0_PIN, GPIO_ModeIN_Floating);
    }
}




/*******************************************************************************
 * Function Name  : main
 * Description    : 主函数
 * Input          : None
 * Output         : None
 * Return         : None
 *******************************************************************************/
int main(void) {

    //PWR_DCDCCfg( ENABLE );
    SetSysClock(CLK_SOURCE_PLL_60MHz);

    /* 配置GPIO */
    GPIOB_ModeCfg( LED1_PIN, GPIO_ModeIN_PU);

    ADC_InterTSSampInit();
    RoughCalib_Value = ADC_DataCalib_Rough(); // 用于计算ADC内部偏差，记录到变量 RoughCalib_Value中，注意这个变量需要定义为有符号变量

    InitTasks(); //初始化任务，实际上是给timers清零


    //GPIOB_SetBits( GPIO_Pin_15 );
    //GPIOB_ModeCfg( GPIO_Pin_15, GPIO_ModeOut_PP_5mA );

    TMR0_TimerInit( FREQ_SYS / 10000 );                  // 设置定时时间 100us
    TMR0_ITCfg( ENABLE, TMR0_3_IT_CYC_END );          // 开启中断
    PFIC_EnableIRQ( TMR0_IRQn );

#ifdef DEBUG
    GPIOA_SetBits(bTXD1);
    GPIOA_ModeCfg(bTXD1, GPIO_ModeOut_PP_5mA);
    UART1_DefInit();
#endif   
    PRINT("%s\n", VER_LIB);
    CH57X_BLEInit();
    HAL_Init();
    GAPRole_PeripheralInit();
    Peripheral_Init();
    //RF_Init();
    app_uart_init();
    Main_Circulation();
}



__attribute__((interrupt("WCH-Interrupt-fast")))
__attribute__((section(".highcode")))
void TMR0_IRQHandler( void )        // TMR0 定时中断
{
  if ( TMR0_GetITFlag( TMR0_3_IT_CYC_END ) )
  {
    TMR0_ClearITFlag( TMR0_3_IT_CYC_END );      // 清除中断标志

    //GPIOB_InverseBits( GPIO_Pin_15 );

    UpdateTimers();
    //RunTask(task0,0);
    //RunTask(task1,1);
    RunTask(task2,2);
  }
}
/******************************** endfile @ main ******************************/
