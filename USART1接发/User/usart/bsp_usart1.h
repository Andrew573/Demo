#ifndef __USART1_H
#define	__USART1_H


#include "stm32f10x.h"
#include "stm32f10x_dma.h"
#include <stdio.h>


#define             macUSART_BAUD_RATE                       9600

#define             macUSARTx                                USART1
#define             macUSART_APBxClock_FUN                   RCC_APB2PeriphClockCmd
#define             macUSART_CLK                             RCC_APB2Periph_USART1
#define             macUSART_GPIO_APBxClock_FUN              RCC_APB2PeriphClockCmd
#define             macUSART_GPIO_CLK                        (RCC_APB2Periph_GPIOA | RCC_APB2Periph_AFIO)     
#define             macUSART_TX_PORT                         GPIOA   
#define             macUSART_TX_PIN                          GPIO_Pin_9
#define             macUSART_RX_PORT                         GPIOA   
#define             macUSART_RX_PIN                          GPIO_Pin_10
#define             macUSART_IRQ                             USART1_IRQn
#define             macUSART_INT_FUN                         USART1_IRQHandler

#define  			macUSART_TX_DMA_CHANNEL					 DMA1_Channel5


extern __IO uint32_t USART_RxValue;

void USARTx_Config(void);
void NVIC_Configuration(void);
void Usart_SendStr_length( USART_TypeDef * pUSARTx, uint8_t *str,uint32_t strlen );
void Usart_SendString( USART_TypeDef * pUSARTx, uint8_t *str);
int fputc(int ch, FILE *f);
int fgetc(FILE *f);

void USARRx_DMA_Config(void);


#endif /* __USART1_H */
