#include "stm32f10x.h"
#include "stdio.h"
#include "string.h"
#include "bsp_usart1.h"

uint8_t Rxflag=0;
uint8_t ucTemp;
/**
  * @brief  ������
  * @param  ��
  * @retval ��
  */
int main(void)
{	
	uint8_t ucaRxBuf[256];
	uint16_t usRxCount;
	
	USARTx_Config();
	NVIC_Configuration();
	printf("����һ�������жϽ��ջ���ʵ��\n" );
	printf("�������ݲ��Իس�������\n" );
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
			
			/* ���������ַ�����Ϊ���յ�һ������ */
			if (ucTemp == 0x0A)	/* �����ַ� */
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
