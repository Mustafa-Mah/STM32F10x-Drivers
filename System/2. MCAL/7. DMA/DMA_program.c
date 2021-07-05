/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   28 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"

void MDMA_voidInitDMA(void)
{
    // Clearing config reg
    DMA->CH[0].CCR = 0;
    // Applying config bits for Channel 1
    DMA->CH[0].CCR |= (CH1_TCIE << 1) | (CH1_HTIE << 2) | (CH1_TEIE << 3) |
                      (CH1_DIR << 4) | (CH1_CIRC_MODE << 5) | (CH1_PERIPH_INC << 6) |
                      (CH1_MEM_INC << 7) | (CH1_PERIPH_SIZE << 8) | (CH1_MEM_SIZE << 10) |
                      (CH1_PRI_LVL << 12) | (CH1_MEM2MEM << 14);
    // Clearing config reg
    DMA->CH[1].CCR = 0;
    // Applying config bits for Channel 2
    DMA->CH[1].CCR |= (CH2_TCIE << 1) | (CH2_HTIE << 2) | (CH2_TEIE << 3) |
                      (CH2_DIR << 4) | (CH2_CIRC_MODE << 5) | (CH2_PERIPH_INC << 6) |
                      (CH2_MEM_INC << 7) | (CH2_PERIPH_SIZE << 8) | (CH2_MEM_SIZE << 10) |
                      (CH2_PRI_LVL << 12) | (CH2_MEM2MEM << 14);
    // Clearing config reg
    DMA->CH[2].CCR = 0;
    // Applying config bits for Channel 3
    DMA->CH[2].CCR |= (CH3_TCIE << 1) | (CH3_HTIE << 2) | (CH3_TEIE << 3) |
                      (CH3_DIR << 4) | (CH3_CIRC_MODE << 5) | (CH3_PERIPH_INC << 6) |
                      (CH3_MEM_INC << 7) | (CH3_PERIPH_SIZE << 8) | (CH3_MEM_SIZE << 10) |
                      (CH3_PRI_LVL << 12) | (CH3_MEM2MEM << 14);
    // Clearing config reg
    DMA->CH[3].CCR = 0;
    // Applying config bits for Channel 4
    DMA->CH[3].CCR |= (CH4_TCIE << 1) | (CH4_HTIE << 2) | (CH4_TEIE << 3) |
                      (CH4_DIR << 4) | (CH4_CIRC_MODE << 5) | (CH4_PERIPH_INC << 6) |
                      (CH4_MEM_INC << 7) | (CH4_PERIPH_SIZE << 8) | (CH4_MEM_SIZE << 10) |
                      (CH4_PRI_LVL << 12) | (CH4_MEM2MEM << 14);
    // Clearing config reg
    DMA->CH[4].CCR = 0;
    // Applying config bits for Channel 5
    DMA->CH[4].CCR |= (CH5_TCIE << 1) | (CH5_HTIE << 2) | (CH5_TEIE << 3) |
                      (CH5_DIR << 4) | (CH5_CIRC_MODE << 5) | (CH5_PERIPH_INC << 6) |
                      (CH5_MEM_INC << 7) | (CH5_PERIPH_SIZE << 8) | (CH5_MEM_SIZE << 10) |
                      (CH5_PRI_LVL << 12) | (CH5_MEM2MEM << 14);
    // Clearing config reg
    DMA->CH[5].CCR = 0;
    // Applying config bits for Channel 6
    DMA->CH[5].CCR |= (CH6_TCIE << 1) | (CH6_HTIE << 2) | (CH6_TEIE << 3) |
                      (CH6_DIR << 4) | (CH6_CIRC_MODE << 5) | (CH6_PERIPH_INC << 6) |
                      (CH6_MEM_INC << 7) | (CH6_PERIPH_SIZE << 8) | (CH6_MEM_SIZE << 10) |
                      (CH6_PRI_LVL << 12) | (CH6_MEM2MEM << 14);
    // Clearing config reg
    DMA->CH[6].CCR = 0;
    // Applying config bits for Channel 7
    DMA->CH[6].CCR |= (CH7_TCIE << 1) | (CH7_HTIE << 2) | (CH7_TEIE << 3) |
                      (CH7_DIR << 4) | (CH7_CIRC_MODE << 5) | (CH7_PERIPH_INC << 6) |
                      (CH7_MEM_INC << 7) | (CH7_PERIPH_SIZE << 8) | (CH7_MEM_SIZE << 10) |
                      (CH7_PRI_LVL << 12) | (CH7_MEM2MEM << 14);
}

void MDMA_voidConfigChannel(u8 copy_u8ChID, u32 *copy_pu32PeriphAddr, u32 *copy_pu32MemAddr, u16 copy_u16NumOfData)
{
    u8 local_u8ID = copy_u8ChID - 1;
    DMA->CH[local_u8ID].CPAR = copy_pu32PeriphAddr;
    DMA->CH[local_u8ID].CMAR = copy_pu32MemAddr;
    DMA->CH[local_u8ID].CNDTR = copy_u16NumOfData;
}

void MDMA_voidEnableChannel(u8 copy_u8ChID)
{
    u8 local_u8ID = copy_u8ChID - 1;
    SET_BIT(DMA->CH[local_u8ID].CCR, 0);
}

void MDMA_voidDisableChannel(u8 copy_u8ChID)
{
    u8 local_u8ID = copy_u8ChID - 1;
    CLR_BIT(DMA->CH[local_u8ID].CCR, 0);
}

void MDMA_voidClearINTFlag(u8 copy_u8ChID,u8 copy_u8InterruptID)
{
    u8 local_u8Pos = copy_u8ChID - 1;
    local_u8Pos = local_u8Pos << 2;
    if (copy_u8InterruptID < 4)
    {
        local_u8Pos = local_u8Pos + copy_u8InterruptID;
        SET_BIT(DMA->IFCR, local_u8Pos);
    }
}

u8   MDMA_u8GetINTFlag(u8 copy_u8ChID,u8 copy_u8InterruptID)
{
    u8 local_u8Result;
    u8 local_u8Pos = copy_u8ChID - 1;
    local_u8Pos = local_u8Pos << 2;
    if (copy_u8InterruptID < 4)
    {
        local_u8Pos = local_u8Pos + copy_u8InterruptID;
        local_u8Result = GET_BIT(DMA->ISR, local_u8Pos);
    }
    return local_u8Result;
}