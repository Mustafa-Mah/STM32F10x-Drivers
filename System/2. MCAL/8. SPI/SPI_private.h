/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   30 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _SPI_PRIVATE_H_
#define _SPI_PRIVATE_H_

// SPIx_BAUD_RATE options:
#define SPI_BAUD_PCLK_DIV_2     0b000
#define SPI_BAUD_PCLK_DIV_4     0b001
#define SPI_BAUD_PCLK_DIV_8     0b010
#define SPI_BAUD_PCLK_DIV_16    0b011
#define SPI_BAUD_PCLK_DIV_32    0b100
#define SPI_BAUD_PCLK_DIV_64    0b101
#define SPI_BAUD_PCLK_DIV_128   0b110
#define SPI_BAUD_PCLK_DIV_256   0b111

/*// CHx_PRI_LVL options:
#define DMA_PL_LOW              0b00
#define DMA_PL_MEDIUM           0b01
#define DMA_PL_HIGH             0b10
#define DMA_PL_VERY_HIGH        0b11*/

void (*SPI1_CallBack)(u16);
void (*SPI2_CallBack)(u16);

typedef struct
{
    volatile u32 CR1;
    volatile u32 CR2;
    volatile u32 SR;
    volatile u32 DR;
    volatile u32 CRCPR;
    volatile u32 RXCRCR;
    volatile u32 TXCRCR;
    volatile u32 I2SCFGR;
    volatile u32 I2SPR;
} SPI_t;

#define SPI1                    ((volatile SPI_t *)0x40013000)
#define SPI2                    ((volatile SPI_t *)0x40003800)

void SPI1_IRQHandler(void);
void SPI2_IRQHandler(void);

#endif // _SPI_PRIVATE_H_