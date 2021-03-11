/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   4 March 2021                                                            */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void MRCC_voidInitSysClock(void)
{
    #if RCC_SYS_CLK == HSE_CRYSTAL
        RCC_CR = 0x00010083;                            // Enable HSE w/o bypass
        while (((volatile u32)GET_BIT(RCC_CR, 17)) == 0)
        {
        	asm("NOP");									// Wait for HSE oscillator to be stable
        }
        RCC_CFGR = 0x00000001;                          // HSE selected as system clock

    #elif RCC_SYS_CLK == HSE_RC
        RCC_CR = 0x00050083;                            // Enable HSE w/ bypass
        while (((volatile u32)GET_BIT(RCC_CR, 17)) == 0)
        {
        	asm("NOP");									// Wait for HSE oscillator to be stable
        }
        RCC_CFGR = 0x00000001;                          // HSE selected as system clock

    #elif RCC_SYS_CLK == HSI
        RCC_CR = 0x00000083;                            // Enable HSI
        while (((volatile u32)GET_BIT(RCC_CR, 2)) == 0)
        {
            asm("NOP");									// Wait for HSI oscillator to be stable
        }
        RCC_CFGR = 0x00000000;                          // HSI selected as system clock

    #elif RCC_SYS_CLK == PLL
        #if RCC_PLL_INPUT == PLL_INPUT_HSE
            RCC_CR = 0x00010083;                        // Enable HSE w/o bypass
            RCC_CFGR = 0x00010000;                      // Selecting HSE as PLL input
        #elif RCC_PLL_INPUT == PLL_INPUT_HSE_DIV_2
            RCC_CR = 0x00010083;                        // Enable HSE w/o bypass
            RCC_CFGR = 0x00030000;                      // Selecting HSE/2 as PLL input
        #elif RCC_PLL_INPUT == PLL_INPUT_HSI_DIV_2
            RCC_CR = 0x00000083;                        // Enable HSI
            RCC_CFGR = 0x00000000;                      // Selecting HSI/2 as PLL input
        #endif
        RCC_CFGR |= ((RCC_PLL_MUL - 2) << 18);          // Applying PLL mul factor
        SET_BIT(RCC_CR, 24);                            // Enabling PLL
        while (((volatile u32)GET_BIT(RCC_CR, 25)) == 0)
        {
        	asm("NOP");									// Wait for PLL to be locked
        }
        SET_BIT(RCC_CFGR, 1);                           // Selecting PLL as system clock
    #else
        #error("Invalid System Clock.")
    #endif

    RCC_CFGR |= ((RCC_AHB_PRE)  << 4);                  // Applying AHB prescaler
    RCC_CFGR |= ((RCC_APB1_PRE) << 8);                  // Applying APB1 prescaler
    RCC_CFGR |= ((RCC_APB2_PRE) << 11);                 // Applying APB2 prescaler
    RCC_CFGR |= ((RCC_ADC_PRE)  << 14);                 // Applying ADC prescaler

    #if RCC_CLK_SEC_SYS_ON == 1
        SET_BIT(RCC_CR, 19);                            // Enable Clock security system
    #endif
}

void MRCC_voidEnableClock(u8 copy_u8Bus, u8 copy_u8Peripheral)
{
    if (copy_u8Peripheral < 32)
    {
        switch (copy_u8Bus)
        {
            case RCC_AHB:   SET_BIT(RCC_AHBENR,  copy_u8Peripheral);    break;
            case RCC_APB1:  SET_BIT(RCC_APB1ENR, copy_u8Peripheral);    break;
            case RCC_APB2:  SET_BIT(RCC_APB2ENR, copy_u8Peripheral);    break;
            default:    /*Return Error*/                                break;
        }
    }
    else
    {
        //Return Error
    }
}

void MRCC_voidDisableClock(u8 copy_u8Bus, u8 copy_u8Peripheral)
{
    if (copy_u8Peripheral < 32)
    {
        switch (copy_u8Bus)
        {
            case RCC_AHB:   CLR_BIT(RCC_AHBENR,  copy_u8Peripheral);    break;
            case RCC_APB1:  CLR_BIT(RCC_APB1ENR, copy_u8Peripheral);    break;
            case RCC_APB2:  CLR_BIT(RCC_APB2ENR, copy_u8Peripheral);    break;
            default:    /*Return Error*/                                break;
        }
    }
    else
    {
        //Return Error
    }
}