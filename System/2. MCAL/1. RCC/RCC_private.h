/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   4 March 2021                                                            */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _RCC_PRIVATE_H_
#define _RCC_PRIVATE_H_

/*  Registers Definition  */
#define RCC_CR                  *((u32*)0x40021000)
#define RCC_CFGR                *((u32*)0x40021004)
#define RCC_CIR                 *((u32*)0x40021008)
#define RCC_APB2RSTR            *((u32*)0x4002100C)
#define RCC_APB1RSTR            *((u32*)0x40021010)
#define RCC_AHBENR              *((u32*)0x40021014)
#define RCC_APB2ENR             *((u32*)0x40021018)
#define RCC_APB1ENR             *((u32*)0x4002101C)
#define RCC_BDCR                *((u32*)0x40021020)
#define RCC_CSR                 *((u32*)0x40021024)

// RCC_SYS_CLK options
#define HSE_CRYSTAL             0
#define HSE_RC                  1
#define PLL                     2
#define HSI                     3

// PLL Input Clock options:
#define PLL_INPUT_HSE           0
#define PLL_INPUT_HSE_DIV_2     1
#define PLL_INPUT_HSI_DIV_2     2

// PLL multiplication factor options:
#define PLL_MUL_2               0b0000
#define PLL_MUL_3               0b0001
#define PLL_MUL_4               0b0010
#define PLL_MUL_5               0b0011
#define PLL_MUL_6               0b0100
#define PLL_MUL_7               0b0101
#define PLL_MUL_8               0b0110
#define PLL_MUL_9               0b0111
#define PLL_MUL_10              0b1000
#define PLL_MUL_11              0b1001
#define PLL_MUL_12              0b1010
#define PLL_MUL_13              0b1011
#define PLL_MUL_14              0b1100
#define PLL_MUL_15              0b1101
#define PLL_MUL_16              0b1110

// AHB prescaler options:
#define SYSCLK                  0b0000
#define SYSCLK_DIV_2            0b1000
#define SYSCLK_DIV_4            0b1001
#define SYSCLK_DIV_8            0b1010
#define SYSCLK_DIV_16           0b1011
#define SYSCLK_DIV_64           0b1100
#define SYSCLK_DIV_128          0b1101
#define SYSCLK_DIV_256          0b1110
#define SYSCLK_DIV_512          0b1111

// APB1/APB2 prescaler options:
#define HCLK                    0b000
#define HCLK_DIV_2              0b100
#define HCLK_DIV_4              0b101
#define HCLK_DIV_8              0b110
#define HCLK_DIV_16             0b111

// ADC prescaler options:
#define PCLK2_DIV_2             0b00
#define PCLK2_DIV_4             0b01
#define PCLK2_DIV_8             0b10
#define PCLK2_DIV_16            0b11

#endif // _RCC_PRIVATE_H_