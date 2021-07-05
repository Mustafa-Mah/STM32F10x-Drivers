/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   28 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _DMA_PRIVATE_H_
#define _DMA_PRIVATE_H_

#define ENABLED                 1
#define DISABLED                0

// CHx_PRI_LVL options:
#define DMA_PL_LOW              0b00
#define DMA_PL_MEDIUM           0b01
#define DMA_PL_HIGH             0b10
#define DMA_PL_VERY_HIGH        0b11

// CHx_MEM_SIZE/PERIPH_SIZE options:
#define DMA_SIZE_8BIT           0b00
#define DMA_SIZE_16BIT          0b01
#define DMA_SIZE_32BIT          0b10

// CHx_MEM_SIZE/PERIPH_SIZE options:
#define DMA_DIR_READ_PERIPH     0
#define DMA_DIR_READ_MEM        1

typedef struct
{
    volatile u32 CCR;
    volatile u32 CNDTR;
    volatile u32 CPAR;
    volatile u32 CMAR;
    const u32 RESERVED;
} DMA_CH_t;

typedef struct
{
    volatile u32 ISR;
    volatile u32 IFCR;
    volatile DMA_CH_t CH[7];
} DMA_t;

#define DMA                     ((volatile DMA_t*)0x40020000)

#endif // _DMA_PRIVATE_H_