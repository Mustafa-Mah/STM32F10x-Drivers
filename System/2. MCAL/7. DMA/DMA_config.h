/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   28 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _DMA_CONFIG_H_
#define _DMA_CONFIG_H_

/* CHx memory to memory options:
    ENABLED   
    DISABLED                                    */
#define CH1_MEM2MEM             ENABLED
/* CHx priority level options:
    DMA_PL_LOW      
    DMA_PL_MEDIUM   
    DMA_PL_HIGH     
    DMA_PL_VERY_HIGH                            */
#define CH1_PRI_LVL             DMA_PL_HIGH
/* CHx memory size/peripheral size options:
    DMA_SIZE_8BIT           0b00
    DMA_SIZE_16BIT          0b01
    DMA_SIZE_32BIT          0b10                */
#define CH1_MEM_SIZE            DMA_SIZE_32BIT
#define CH1_PERIPH_SIZE         DMA_SIZE_32BIT
/* CHx memory increment mode options:
    ENABLED   
    DISABLED                                    */
#define CH1_MEM_INC             DISABLED
/* CHx peripheral increment mode options:
    ENABLED   
    DISABLED                                    */
#define CH1_PERIPH_INC          DISABLED
/* CHx circular mode options:
    ENABLED   
    DISABLED                                    */
#define CH1_CIRC_MODE           DISABLED
/* CHx data transfer direction options:
    DMA_DIR_READ_PERIPH     0
    DMA_DIR_READ_MEM        1                   */
#define CH1_DIR                 DMA_DIR_READ_MEM
/* CHx transfer error interrupt enable options:
    ENABLED   
    DISABLED                                    */
#define CH1_TEIE                DISABLED
/* CHx Half transfer interrupt enable options:
    ENABLED   
    DISABLED                                    */
#define CH1_HTIE                DISABLED
/* CHx transfer complete interrupt enable options:
    ENABLED   
    DISABLED                                    */
#define CH1_TCIE                DISABLED

#define CH2_MEM2MEM             ENABLED
#define CH2_PRI_LVL             DMA_PL_HIGH
#define CH2_MEM_SIZE            DMA_SIZE_32BIT
#define CH2_PERIPH_SIZE         DMA_SIZE_32BIT
#define CH2_MEM_INC             DISABLED
#define CH2_PERIPH_INC          DISABLED
#define CH2_CIRC_MODE           DISABLED
#define CH2_DIR                 DMA_DIR_READ_MEM
#define CH2_TEIE                DISABLED
#define CH2_HTIE                DISABLED
#define CH2_TCIE                DISABLED

#define CH3_MEM2MEM             ENABLED
#define CH3_PRI_LVL             DMA_PL_HIGH
#define CH3_MEM_SIZE            DMA_SIZE_32BIT
#define CH3_PERIPH_SIZE         DMA_SIZE_32BIT
#define CH3_MEM_INC             DISABLED
#define CH3_PERIPH_INC          DISABLED
#define CH3_CIRC_MODE           DISABLED
#define CH3_DIR                 DMA_DIR_READ_MEM
#define CH3_TEIE                DISABLED
#define CH3_HTIE                DISABLED
#define CH3_TCIE                DISABLED

#define CH4_MEM2MEM             ENABLED
#define CH4_PRI_LVL             DMA_PL_HIGH
#define CH4_MEM_SIZE            DMA_SIZE_32BIT
#define CH4_PERIPH_SIZE         DMA_SIZE_32BIT
#define CH4_MEM_INC             DISABLED
#define CH4_PERIPH_INC          DISABLED
#define CH4_CIRC_MODE           DISABLED
#define CH4_DIR                 DMA_DIR_READ_MEM
#define CH4_TEIE                DISABLED
#define CH4_HTIE                DISABLED
#define CH4_TCIE                DISABLED

#define CH5_MEM2MEM             ENABLED
#define CH5_PRI_LVL             DMA_PL_HIGH
#define CH5_MEM_SIZE            DMA_SIZE_32BIT
#define CH5_PERIPH_SIZE         DMA_SIZE_32BIT
#define CH5_MEM_INC             DISABLED
#define CH5_PERIPH_INC          DISABLED
#define CH5_CIRC_MODE           DISABLED
#define CH5_DIR                 DMA_DIR_READ_MEM
#define CH5_TEIE                DISABLED
#define CH5_HTIE                DISABLED
#define CH5_TCIE                DISABLED

#define CH6_MEM2MEM             ENABLED
#define CH6_PRI_LVL             DMA_PL_HIGH
#define CH6_MEM_SIZE            DMA_SIZE_32BIT
#define CH6_PERIPH_SIZE         DMA_SIZE_32BIT
#define CH6_MEM_INC             DISABLED
#define CH6_PERIPH_INC          DISABLED
#define CH6_CIRC_MODE           DISABLED
#define CH6_DIR                 DMA_DIR_READ_MEM
#define CH6_TEIE                DISABLED
#define CH6_HTIE                DISABLED
#define CH6_TCIE                DISABLED

#define CH7_MEM2MEM             ENABLED
#define CH7_PRI_LVL             DMA_PL_HIGH
#define CH7_MEM_SIZE            DMA_SIZE_32BIT
#define CH7_PERIPH_SIZE         DMA_SIZE_32BIT
#define CH7_MEM_INC             DISABLED
#define CH7_PERIPH_INC          DISABLED
#define CH7_CIRC_MODE           DISABLED
#define CH7_DIR                 DMA_DIR_READ_MEM
#define CH7_TEIE                DISABLED
#define CH7_HTIE                DISABLED
#define CH7_TCIE                DISABLED

#endif // _DMA_CONFIG_H_