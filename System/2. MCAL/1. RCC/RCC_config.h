/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   4 March 2021                                                            */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _RCC_CONFIG_H_
#define _RCC_CONFIG_H_

/* System Clock options:
    HSE_CRYSTAL
    HSE_RC
    PLL
    HSI                                         */
#define RCC_SYS_CLK             HSE_CRYSTAL

/* Clock Security System enable  */
#define RCC_CLK_SEC_SYS_ON      0


#if RCC_SYS_CLK == PLL
/* PLL Input Clock options:
    PLL_INPUT_HSE
    PLL_INPUT_HSE_DIV_2
    PLL_INPUT_HSI_DIV_2                         */
    #define RCC_PLL_INPUT           PLL_INPUT_HSE

/* PLL multiplication factor options:
    2-16                                        */
    #define RCC_PLL_MUL             9
#endif

/* AHB prescaler options:
    SYSCLK
    SYSCLK_DIV_2
    SYSCLK_DIV_4
    SYSCLK_DIV_8
    SYSCLK_DIV_16
    SYSCLK_DIV_64
    SYSCLK_DIV_128
    SYSCLK_DIV_256
    SYSCLK_DIV_512                              */
#define RCC_AHB_PRE             SYSCLK

/* APB1 prescaler options:
    HCLK
    HCLK_DIV_2
    HCLK_DIV_4
    HCLK_DIV_8
    HCLK_DIV_16                                  */
#define RCC_APB1_PRE            HCLK_DIV_2

/* APB2 prescaler options:
    HCLK
    HCLK_DIV_2
    HCLK_DIV_4
    HCLK_DIV_8
    HCLK_DIV_16                                  */
#define RCC_APB2_PRE            HCLK

/* ADC prescaler options:
    PCLK2_DIV_2
    PCLK2_DIV_4
    PCLK2_DIV_8
    PCLK2_DIV_16                                  */
#define RCC_ADC_PRE             PCLK2_DIV_16

#endif // _RCC_CONFIG_H_