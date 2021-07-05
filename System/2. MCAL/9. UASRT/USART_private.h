/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   06 April 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _USART_PRIVATE_H_
#define _USART_PRIVATE_H_

#define TIMEOUT                 3000

void (*USART1_CallBack)(u16);
void (*USART2_CallBack)(u16);
void (*USART3_CallBack)(u16);

typedef struct
{
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 BRR;
    volatile u32 CR[3];
    volatile u32 GTPR;
} USART_t;

#define USART1                  ((volatile USART_t *)0x40013800)
#define USART2                  ((volatile USART_t *)0x40004400)
#define USART3                  ((volatile USART_t *)0x40004800)

void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
void USART3_IRQHandler(void);

#endif // _USART_PRIVATE_H_