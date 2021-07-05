/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   30 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _SPI_INTERFACE_H_
#define _SPI_INTERFACE_H_

#define SPI_1                   1
#define SPI_2                   2

void MSPI_voidInit(void);
u32  MSPI_u32SendReceiveDataSync(u8 copy_u8SPI_ID, u16 copy_u16DataToSend);
void MSPI_voidSendReceiveDataAsync(u8 copy_u8SPI_ID, u16 copy_u16DataToSend, void (*copy_ptr)(u16));
void MSPI_voidEnableSPIx(u8 copy_u8SPI_ID);
void MSPI_voidDisableSPIx(u8 copy_u8SPI_ID);

#endif // _SPI_INTERFACE_H_