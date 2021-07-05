/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   13 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

void MSTK_voidInitSysTick(void)
{
    CLR_BIT(STK->CTRL, 1);
    CLR_BIT(STK->CTRL, 0);
    /* Applying SysTick clock source */
    #if STK_CLK_SRC == STK_CLK_AHP
        SET_BIT(STK->CTRL, 2);
    #elif STK_CLK_SRC == STK_CLK_AHP_DIV_8
        CLR_BIT(STK->CTRL, 2);
    #endif
}

void MSTK_voidSetBusyWait(u32 copy_u32Ticks)
{
    STK->LOAD = copy_u32Ticks;
    CLR_BIT(STK->CTRL, 1);                      // Disable timer interrupt
    SET_BIT(STK->CTRL, 0);                      // Start timer
    while (GET_BIT(STK->CTRL, 16) == 0);        // Wait for timer to reach 0
}

void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks, void (*copy_ptr)(void))
{
    STK->LOAD = copy_u32Ticks;
    MSTK_u8Periodic = 1;                        // Periodic interval
    MSTK_CallBack = copy_ptr;                   // Setting call-back function
    SET_BIT(STK->CTRL, 1);                      // Enable timer interrupt
    SET_BIT(STK->CTRL, 0);                      // Start timer
}

void MSTK_voidSetIntervalSingle(u32 copy_u32Ticks, void (*copy_ptr)(void))
{
    CLR_BIT(STK->CTRL, 0);                      // Reset timer
    STK->VAL = 0;

    STK->LOAD = copy_u32Ticks;
    MSTK_u8Periodic = 0;                        // Single interval
    MSTK_CallBack = copy_ptr;                   // Setting call-back function
    SET_BIT(STK->CTRL, 1);                      // Enable timer interrupt
    SET_BIT(STK->CTRL, 0);                      // Start timer
}

void MSTK_voidStopTimer(void)
{
    CLR_BIT(STK->CTRL, 0);                      // Stop timer
    CLR_BIT(STK->CTRL, 1);                      // Disable timer interrupt
    STK->VAL = 0;
}

u32  MSTK_u32GetElapsedTicks(void)
{
    u32 local_32Result = (STK->LOAD) - (STK->VAL);
    return local_32Result;
}

u32  MSTK_u32GetRemainingTicks(void)
{
    return (STK->VAL);
}

u8   MSTK_u8GetCountFlag(void)
{
    return GET_BIT(STK->CTRL, 16);
}

void SysTick_Handler(void)
{
    if (MSTK_u8Periodic == 0)                   // Check single interval
    {
        CLR_BIT(STK->CTRL, 0);                  // Stop timer
    }
    MSTK_CallBack();
}