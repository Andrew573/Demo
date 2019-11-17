#include "stm32f10x.h"
#include "stdio.h"
#include "string.h"
#include "bsp_usart1.h"
#include "oled.h"

//uint8_t Rxflag=0;
//uint8_t ucTemp;

void init()
{
	OLED_GPIO_Configuration();
	LCD_Init();
	LCD_Print(0,0, "rubber:",TYPE16X16,TYPE8X16);
	LCD_Print(0,16, "Lm:",TYPE16X16,TYPE8X16);
	LCD_Print(64,16, "Rm:",TYPE16X16,TYPE8X16);
	
	USARRx_DMA_Config();
}

int main(void)
{	
	uint8_t ucaRxBuf[256];
	uint16_t usRxCount;
	
	USARTx_Config();
	NVIC_Configuration();
	printf("这是一个串口中断接收回显实验\n" );
	printf("输入数据并以回车键结束\n" );
	usRxCount = 0;
	
	init();
	
	while(1)
	{
		LCD_Print(0,32, (u8 *)&USART_RxValue,TYPE16X16,TYPE8X16);
//		
//		if(Rxflag)
//		{
//			if (usRxCount < sizeof(ucaRxBuf))
//			{
//				ucaRxBuf[usRxCount++] = ucTemp;
//			}
//			else
//			{
//				usRxCount = 0;
//			}
//			
//			/* 遇到换行字符，认为接收到一个命令 */
//			if (ucTemp == 0x0A)	/* 换行字符 */
//			{		
//				printf("com1:%s", ucaRxBuf);
//				LCD_Print(0,32, ucaRxBuf,TYPE16X16,TYPE8X16);
//				usRxCount = 0;
//			}
//			Rxflag=0;
//		}
	}
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/
//void macUSART_INT_FUN(void)
//{
//	if(USART_GetITStatus( macUSARTx, USART_IT_RXNE ) != RESET)
//	{		
//	  Rxflag=1;		
//		ucTemp = USART_ReceiveData( macUSARTx );
//	} 
//	 
//}
/*********************************************END OF FILE**********************/
