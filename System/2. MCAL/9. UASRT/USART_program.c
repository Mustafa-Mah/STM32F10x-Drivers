/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   06 April 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "USART_interface.h"
#include "USART_private.h"
#include "USART_config.h"

void MUSART_voidInit(void)
{
    USART1->CR[0] = 0;
    USART1->CR[1] = 0;
    USART1->CR[2] = 0;

    USART2->CR[0] = 0;
    USART2->CR[1] = 0;
    USART2->CR[2] = 0;

    USART3->CR[0] = 0;
    USART3->CR[1] = 0;
    USART3->CR[2] = 0;

	/*	USART1	setup	*/
    USART1->CR[0] |= (USART1_SEND_BREAK << 0) || (USART1_RECEIVER_WAKEUP << 1) || (USART1_RECEIVER_EN << 2) ||
					 (USART1_TRANSMITTER_EN << 3) || (USART1_IDLEIE << 4) || (USART1_RXNEIE << 5) ||
					 (USART1_TCIE << 6) || (USART1_TXEIE << 7) || (USART1_PEIE << 8) ||
					 (USART1_PARITY_SEL << 9) || (USART1_PARITY_CONTROL_EN << 10) || (USART1_WAKEUP_METHOD << 11) ||
					 (USART1_WORD_LENGTH << 12);

	USART1->CR[1] |= (USART1_NODE_ADDRESS << 0) || (USART1_LBDL << 5) || (USART1_LBDIE << 6) || (USART1_LBCL << 8) ||
					 (USART1_CLOCK_PHASE << 9) || (USART1_CLOCK_POLARITY << 10) || (USART1_CLKEN << 11) ||
					 (USART1_STOP << 12) || (USART1_LINEN << 14);

	USART1->CR[2] |= (USART1_ERR_IE << 0) || (USART1_IRDA_EN << 1) || (USART1_IRDA_LP << 2) ||
					 (USART1_HALF_DUPLEX << 3) || (USART1_NACK << 4) || (USART1_SMARTCARD_EN << 5) ||
					 (USART1_DMA_RECEIVER << 6) || (USART1_DMA_TRANSMITTER << 7) || (USART1_RTSE << 8) ||
					 (USART1_CTSE << 9) || (USART1_CTSIE << 10) ;

	/*	USART2	setup	*/
	USART2->CR[0] |= (USART2_SEND_BREAK << 0) || (USART2_RECEIVER_WAKEUP << 1) || (USART2_RECEIVER_EN << 2) ||
					 (USART2_TRANSMITTER_EN << 3) || (USART2_IDLEIE << 4) || (USART2_RXNEIE << 5) ||
					 (USART2_TCIE << 6) || (USART2_TXEIE << 7) || (USART2_PEIE << 8) ||
					 (USART2_PARITY_SEL << 9) || (USART2_PARITY_CONTROL_EN << 10) || (USART2_WAKEUP_METHOD << 11) ||
					 (USART2_WORD_LENGTH << 12);

	USART2->CR[1] |= (USART2_NODE_ADDRESS << 0) || (USART2_LBDL << 5) || (USART2_LBDIE << 6) || (USART2_LBCL << 8) ||
					 (USART2_CLOCK_PHASE << 9) || (USART2_CLOCK_POLARITY << 10) || (USART2_CLKEN << 11) ||
					 (USART2_STOP << 12) || (USART2_LINEN << 14);

	USART2->CR[2] |= (USART2_ERR_IE << 0) || (USART2_IRDA_EN << 1) || (USART2_IRDA_LP << 2) ||
					 (USART2_HALF_DUPLEX << 3) || (USART2_NACK << 4) || (USART2_SMARTCARD_EN << 5) ||
					 (USART2_DMA_RECEIVER << 6) || (USART2_DMA_TRANSMITTER << 7) || (USART2_RTSE << 8) ||
					 (USART2_CTSE << 9) || (USART2_CTSIE << 10) ;
	
	/*	USART3	setup	*/
	USART3->CR[0] |= (USART3_SEND_BREAK << 0) || (USART3_RECEIVER_WAKEUP << 1) || (USART3_RECEIVER_EN << 2) ||
					 (USART3_TRANSMITTER_EN << 3) || (USART3_IDLEIE << 4) || (USART3_RXNEIE << 5) ||
					 (USART3_TCIE << 6) || (USART3_TXEIE << 7) || (USART3_PEIE << 8) ||
					 (USART3_PARITY_SEL << 9) || (USART3_PARITY_CONTROL_EN << 10) || (USART3_WAKEUP_METHOD << 11) ||
					 (USART3_WORD_LENGTH << 12);

	USART3->CR[1] |= (USART3_NODE_ADDRESS << 0) || (USART3_LBDL << 5) || (USART3_LBDIE << 6) || (USART3_LBCL << 8) ||
					 (USART3_CLOCK_PHASE << 9) || (USART3_CLOCK_POLARITY << 10) || (USART3_CLKEN << 11) ||
					 (USART3_STOP << 12) || (USART3_LINEN << 14);

	USART3->CR[2] |= (USART3_ERR_IE << 0) || (USART3_IRDA_EN << 1) || (USART3_IRDA_LP << 2) ||
					 (USART3_HALF_DUPLEX << 3) || (USART3_NACK << 4) || (USART3_SMARTCARD_EN << 5) ||
					 (USART3_DMA_RECEIVER << 6) || (USART3_DMA_TRANSMITTER << 7) || (USART3_RTSE << 8) ||
					 (USART3_CTSE << 9) || (USART3_CTSIE << 10) ;
}

void MUSART_voidEnableUSARTx(u8 copy_u8USART_ID)
{
    switch (copy_u8USART_ID)
    {
        case USART_1:
            SET_BIT(USART1->CR[0], 13);
            break;
        case USART_2:
            SET_BIT(USART3->CR[0], 13);
            break;
        case USART_3:
            SET_BIT(USART3->CR[0], 13);
            break;    
        default:
            break;
    }
}

void MUSART_voidDisableUSARTx(u8 copy_u8USART_ID)
{
    switch (copy_u8USART_ID)
    {
        case USART_1:
            CLR_BIT(USART1->CR[0], 13);
            break;
        case USART_2:
            CLR_BIT(USART2->CR[0], 13);
            break;
        case USART_3:
            CLR_BIT(USART3->CR[0], 13);
            break;    
        default:
            break;
    }
}

void MUSART_voidSetBaudRate(u8 copy_u8USART_ID, u8 copy_u8Fraction, u16 copy_u16Mantissa)
{
    switch (copy_u8USART_ID)
    {
        case USART_1:
            /*  Clearing Baud Rate reg              */
            USART1->BRR = 0;
            /*  Applying 4 bits fraction            */
            USART1->BRR = copy_u8Fraction;
            /*  Clearing Mantisa bits               */
            USART1->BRR &= ~(0xFFF0);
            /*  Applying Mantisa bits               */
            USART1->BRR |= copy_u16Mantissa << 4;
            break;
        case USART_2:
            /*  Clearing Baud Rate reg              */
            USART2->BRR = 0;
            /*  Applying 4 bits fraction            */
            USART2->BRR = copy_u8Fraction;
            /*  Clearing Mantisa bits               */
            USART2->BRR &= ~(0xFFF0);
            /*  Applying Mantisa bits               */
            USART2->BRR |= copy_u16Mantissa << 4;
            break;
        case USART_3:
            /*  Clearing Baud Rate reg              */
            USART3->BRR = 0;
            /*  Applying 4 bits fraction            */
            USART3->BRR = copy_u8Fraction;
            /*  Clearing Mantisa bits               */
            USART3->BRR &= ~(0xFFF0);
            /*  Applying Mantisa bits               */
            USART3->BRR |= copy_u16Mantissa << 4;
            break;    
        default:
            break;
    }
}

void MUSART_voidSendDataSync(u8 copy_u8USART_ID, const u8 *copy_pu8Data)
{
    u16 local_u16Itr = 0;

    switch (copy_u8USART_ID)
    {
        case USART_1:
            while(copy_pu8Data[local_u16Itr] != '\0')
            {
                USART1->DR = (u32)(copy_pu8Data[local_u16Itr]);
                while (GET_BIT(USART1->SR, 6) == 0);
                local_u16Itr++;
            }
            break;
        case USART_2:
            while(copy_pu8Data[local_u16Itr] != '\0')
            {
                USART2->DR = (u32)(copy_pu8Data[local_u16Itr]);
                while (GET_BIT(USART2->SR, 6) == 0);
                local_u16Itr++;
            }
            break;
        case USART_3:
            while(copy_pu8Data[local_u16Itr] != '\0')
            {
                USART3->DR = (u32)(copy_pu8Data[local_u16Itr]);
                while (GET_BIT(USART3->SR, 6) == 0);
                local_u16Itr++;
            }
            break;    
        default:
            break;
    }
}

u8   MUSART_u8ReceiveDataSync(u8 copy_u8USART_ID)
{
    u8  local_u8Result;
    u16 local_u16Timeout = 0;

    switch (copy_u8USART_ID)
    {
        case USART_1:
            while (GET_BIT(USART1->SR, 5) == 0)
            {
                local_u16Timeout++;
                if (local_u16Timeout == TIMEOUT)
                {
                    local_u8Result = 255;
                    break;
                }
            }
            if (local_u16Timeout < TIMEOUT)
            {
                local_u8Result = USART1->DR;
            }
            break;
        case USART_2:
            while (GET_BIT(USART2->SR, 5) == 0)
            {
                local_u16Timeout++;
                if (local_u16Timeout == TIMEOUT)
                {
                    local_u8Result = 255;
                    break;
                }
            }
            if (local_u16Timeout < TIMEOUT)
            {
                local_u8Result = USART2->DR;
            }
            break;
        case USART_3:
            while (GET_BIT(USART3->SR, 5) == 0)
            {
                local_u16Timeout++;
                if (local_u16Timeout == TIMEOUT)
                {
                    local_u8Result = 255;
                    break;
                }
            }
            if (local_u16Timeout < TIMEOUT)
            {
                local_u8Result = USART3->DR;
            }
            break;   
        default:
            break;
    }
    return local_u8Result;
}

void USART1_IRQHandler(void)
{
    USART1_CallBack((u16)USART1->DR);
}

void USART2_IRQHandler(void)
{
    USART2_CallBack((u16)USART2->DR);
}

void USART3_IRQHandler(void)
{
    USART3_CallBack((u16)USART3->DR);
}