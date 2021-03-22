/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   11 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"

void MNVIC_voidInitNVIC(void)
{
    SCB_AIRCR = NVIC_PRIO_GROUPING;                         // Applying selected priority grouping
}

void MNVIC_voidEnableInterrupt(u8 copy_u8IntNum)
{
    if (copy_u8IntNum >= 0 && copy_u8IntNum < 32)
    {
        NVIC_ISER0 = (1 << copy_u8IntNum);
    }
    else if (copy_u8IntNum < 64)
    {
        copy_u8IntNum = copy_u8IntNum - 32;
        NVIC_ISER1 = (1 << copy_u8IntNum);
    }
    else if (copy_u8IntNum < 68)
    {
        copy_u8IntNum = copy_u8IntNum - 64;
        NVIC_ISER2 = (1 << copy_u8IntNum);
    }
    else
    {
        //Return Error
    }
}

void MNVIC_voidDisableInterrupt(u8 copy_u8IntNum)
{
    if (copy_u8IntNum <= 0 && copy_u8IntNum < 32)
    {
        NVIC_ICER0 = (1 << copy_u8IntNum);
    }
    else if (copy_u8IntNum < 64)
    {
        copy_u8IntNum = copy_u8IntNum - 32;
        NVIC_ICER1 = (1 << copy_u8IntNum);
    }
    else if (copy_u8IntNum < 68)
    {
        copy_u8IntNum = copy_u8IntNum - 64;
        NVIC_ICER2 = (1 << copy_u8IntNum);
    }
    else
    {
        //Return Error
    }
}

void MNVIC_voidSetPendingFlag(u8 copy_u8IntNum)
{
    if (copy_u8IntNum <= 0 && copy_u8IntNum < 32)
    {
        NVIC_ISPR0 = (1 << copy_u8IntNum);
    }
    else if (copy_u8IntNum < 64)
    {
        copy_u8IntNum = copy_u8IntNum - 32;
        NVIC_ISPR1 = (1 << copy_u8IntNum);
    }
    else if (copy_u8IntNum < 68)
    {
        copy_u8IntNum = copy_u8IntNum - 64;
        NVIC_ISPR2 = (1 << copy_u8IntNum);
    }
    else
    {
        //Return Error
    }
}

void MNVIC_voidClearPendingFlag(u8 copy_u8IntNum)
{
    if (copy_u8IntNum <= 0 && copy_u8IntNum < 32)
    {
        NVIC_ICPR0 = (1 << copy_u8IntNum);
    }
    else if (copy_u8IntNum < 64)
    {
        copy_u8IntNum = copy_u8IntNum - 32;
        NVIC_ICPR1 = (1 << copy_u8IntNum);
    }
    else if (copy_u8IntNum < 68)
    {
        copy_u8IntNum = copy_u8IntNum - 64;
        NVIC_ICPR2 = (1 << copy_u8IntNum);
    }
    else
    {
        //Return Error
    }
}

u8 MNVIC_u8GetActiveFlag(u8 copy_u8IntNum)
{
    u8 local_u8Result = 0;
    if (copy_u8IntNum <= 0 && copy_u8IntNum < 32)
    {
        local_u8Result = GET_BIT(NVIC_IABR0, copy_u8IntNum);
    }
    else if (copy_u8IntNum < 64)
    {
        copy_u8IntNum = copy_u8IntNum - 32;
        local_u8Result = GET_BIT(NVIC_IABR1, copy_u8IntNum);
    }
    else if (copy_u8IntNum < 68)
    {
        copy_u8IntNum = copy_u8IntNum - 64;
        local_u8Result = GET_BIT(NVIC_IABR2, copy_u8IntNum);
    }
    else
    {
        //Return Error
    }
    return local_u8Result;
}

void MNVIC_voidSetPriority(s8 copy_s8IntNum, u8 copy_u8GroupPriority, u8 copy_u8SubPriority)
{    
    u8 local_u8Priority = (copy_u8SubPriority) |            // Getting 4-bit periority
                          (copy_u8GroupPriority << ((NVIC_PRIO_GROUPING - 0x05FA0300) >> 8));
    if (copy_s8IntNum < 0)                                  // Check core pheriperal
    {
    }
    else if (copy_s8IntNum > -1 && copy_s8IntNum < 68)      // Check external pheriperal
    {
        NVIC_IPR[copy_s8IntNum] = (local_u8Priority << 4);  // Applying priority for selected peripheral
    }
}