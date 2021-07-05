/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   28 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _DMA_INTERFACE_H_
#define _DMA_INTERFACE_H_

#define DMA_INT_GLOBAL          0
#define DMA_INT_TRNS_ERR        1
#define DMA_INT_HALF_TRNS       2
#define DMA_INT_TRNS_COMPLT     3

void MDMA_voidInitDMA(void);
void MDMA_voidConfigChannel(u8 copy_u8ChID, u32 *copy_pu32PeriphAddr, u32 *copy_pu32MemAddr, u16 copy_u16NumOfData);
void MDMA_voidEnableChannel(u8 copy_u8ChID);
void MDMA_voidDisableChannel(u8 copy_u8ChID);
void MDMA_voidClearINTFlag(u8 copy_u8ChID,u8 copy_u8InterruptID);
u8   MDMA_u8GetINTFlag(u8 copy_u8ChID,u8 copy_u8InterruptID);

#endif // _DMA_INTERFACE_H_