/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   06 April 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _USART_INTERFACE_H_
#define _USART_INTERFACE_H_

#define USART_1                 1
#define USART_2                 2
#define USART_3                 3

void MUSART_voidInit(void);
void MUSART_voidEnableUSARTx(u8 copy_u8USART_ID);
void MUSART_voidDisableUSARTx(u8 copy_u8USART_ID);
void MUSART_voidSetBaudRate(u8 copy_u8USART_ID, u8 copy_u8Fraction, u16 copy_u16Mantissa);
void MUSART_voidSendDataSync(u8 copy_u8USART_ID, const u8 *copy_pu8Data);
u8   MUSART_u8ReceiveDataSync(u8 copy_u8USART_ID);

#endif // _USART_INTERFACE_H_