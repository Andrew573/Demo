#include "stm32f10x.h"
#include "stdio.h"
#include "string.h"
#include "bsp_usart1.h"

uint8_t Rxflag=0;
uint8_t ucTemp;
/**
  * @brief  主函数
  * @param  无
  * @retval 无
  */
int main(void)
{	
	uint8_t ucaRxBuf[256];
	uint16_t usRxCount;
	
	USARTx_Config();
	NVIC_Configuration();
	printf("这是一个串口中断接收回显实验\n" );
	printf("输入数据并以回车键结束\n" );
	usRxCount = 0;
	
	while(1)
	{
		
		
		if(Rxflag)
		{
			if (usRxCount < sizeof(ucaRxBuf))
			{
				ucaRxBuf[usRxCount++] = ucTemp;
			}
			else
			{
				usRxCount = 0;
			}
			
			/* 遇到换行字符，认为接收到一个命令 */
			if (ucTemp == 0x0A)	/* 换行字符 */
			{		
				printf("com1:%s", ucaRxBuf);
				//Usart_SendString();
				usRxCount = 0;
			}
			Rxflag=0;
		}
	}
}

/******************************************************************************/
/*                 STM32F10x Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f10x_xx.s).                                            */
/******************************************************************************/
void macUSART_INT_FUN(void)
{
	if(USART_GetITStatus( macUSARTx, USART_IT_RXNE ) != RESET)
	{		
	  Rxflag=1;		
		ucTemp = USART_ReceiveData( macUSARTx );
	} 
	 
}
/*********************************************END OF FILE**********************/
