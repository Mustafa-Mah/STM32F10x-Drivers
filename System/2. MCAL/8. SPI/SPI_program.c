/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   30 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void MSPI_voidInit(void)
{
    // Clearing config regs
    SPI1->CR1 = 0;
    SPI1->CR2 = 0;
    SPI2->CR1 = 0;
    SPI2->CR2 = 0;

    // Applying config bits for SPI1
    SPI1->CR1 |= (SPI1_CLK_PHA << 0) | (SPI1_CLK_POL << 1) | (SPI1_MSTR_SEL << 2) | (SPI1_BAUD_RATE << 3) |
                 (SPI1_LSB_FIRST << 7) | (SPI1_INTERNAL_SLAVE_SEL << 8) | (SPI1_SW_SLAVE_SEL << 9) |
                 (SPI1_RX_ONLY << 10) | (SPI1_DATA_FRAME_FORMAT << 11) | (SPI1_CRC_NEXT << 12) |
                 (SPI1_CRC_HW_EN << 13) | (SPI1_BI_DIR_OUT_EN << 14) | (SPI1_BI_DIR_MODE << 15);

    SPI1->CR2 |= (SPI1_RX_DMA_EN << 0) | (SPI1_TX_DMA_EN << 1) | (SPI1_SS_OUTPUT_EN << 2) |
                 (SPI1_ERR_INT_EN << 5) | (SPI1_RX_NOT_EMPTY_INT_EN << 6) | (SPI1_TX_EMPTY_INT_EN << 7);
    
    // Applying config bits for SPI2
    SPI2->CR1 |= (SPI2_CLK_PHA << 0) | (SPI2_CLK_POL << 1) | (SPI2_MSTR_SEL << 2) | (SPI2_BAUD_RATE << 3) |
                 (SPI2_LSB_FIRST << 7) | (SPI2_INTERNAL_SLAVE_SEL << 8) | (SPI2_SW_SLAVE_SEL << 9) |
                 (SPI2_RX_ONLY << 10) | (SPI2_DATA_FRAME_FORMAT << 11) | (SPI2_CRC_NEXT << 12) |
                 (SPI2_CRC_HW_EN << 13) | (SPI2_BI_DIR_OUT_EN << 14) | (SPI2_BI_DIR_MODE << 15);

    SPI2->CR2 |= (SPI2_RX_DMA_EN << 0) | (SPI2_TX_DMA_EN << 1) | (SPI2_SS_OUTPUT_EN << 2) |
                 (SPI2_ERR_INT_EN << 5) | (SPI2_RX_NOT_EMPTY_INT_EN << 6) | (SPI2_TX_EMPTY_INT_EN << 7);
}

u32 MSPI_u32SendReceiveDataSync(u8 copy_u8SPI_ID, u16 copy_u16DataToSend)
{
    u32 local_u8DataReceived;
    switch (copy_u8SPI_ID)
    {
        case SPI_1:
            // Copying data to data register
            SPI1->DR = copy_u16DataToSend;
            // Waiting for SPI to finish sending/receiving
            while (GET_BIT(SPI1->SR, 7) == 1);
            // Getting Received Data
            local_u8DataReceived = SPI1->DR;
            break;
        case SPI_2:
            // Copying data to data register
            SPI2->DR = copy_u16DataToSend;
            // Waiting for SPI to finish sending/receiving
            while (GET_BIT(SPI2->SR, 7) == 1);
            // Getting Received Data
            local_u8DataReceived = SPI2->DR;
            break;    
        default:
            local_u8DataReceived = 0;
            break;
    }
    return local_u8DataReceived;
}

void MSPI_voidSendReceiveDataAsync(u8 copy_u8SPI_ID, u16 copy_u16DataToSend, void (*copy_ptr)(u16))
{
    switch (copy_u8SPI_ID)
    {
        case SPI_1:
            SPI1->DR = copy_u16DataToSend;
            SPI1_CallBack = copy_ptr;
            break;
        case SPI_2:
            SPI2->DR = copy_u16DataToSend;
            SPI2_CallBack = copy_ptr;
            break;
        default:
            break;
    }
}

void MSPI_voidEnableSPIx(u8 copy_u8SPI_ID)
{
    switch (copy_u8SPI_ID)
    {
        case SPI_1:
            SET_BIT(SPI1->CR1, 6);
            break;
        case SPI_2:
            SET_BIT(SPI2->CR1, 6);
            break;
        default:
            break;
    }
}

void MSPI_voidDisableSPIx(u8 copy_u8SPI_ID)
{
    switch (copy_u8SPI_ID)
    {
        case SPI_1:
            CLR_BIT(SPI1->CR1, 6);
            break;
        case SPI_2:
            CLR_BIT(SPI2->CR1, 6);
            break;
        default:
            break;
    }
}

void SPI1_IRQHandler(void)
{
    u32 local_u8DataReceived = SPI1->DR;
    SPI1_CallBack(local_u8DataReceived);
}

void SPI2_IRQHandler(void)
{
    u32 local_u8DataReceived = SPI2->DR;
    SPI2_CallBack(local_u8DataReceived);
}