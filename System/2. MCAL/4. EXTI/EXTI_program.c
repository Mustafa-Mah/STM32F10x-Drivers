/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   12 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "EXTI_config.h"

void MEXTI_voidEnableEXTI(u8 copy_u8Line,u8 copy_u8Mode)
{   
    SET_BIT(EXTI->IMR, copy_u8Line);
}
void MEXTI_voidDisableEXTI(u8 copy_u8Line)
{
    CLR_BIT(EXTI->IMR, copy_u8Line);
}
void MEXTI_voidSWTrigger(u8 copy_u8Line)
{
    SET_BIT(EXTI->IMR, copy_u8Line);
    SET_BIT(EXTI->PR, copy_u8Line);
    SET_BIT(EXTI->SWIER, copy_u8Line);
}

void MEXTI_voidSetTriggerMode(u8 copy_u8Line,u8 copy_u8Mode)
{
    if (copy_u8Mode == EXTI_MODE_RISING)
    {
        SET_BIT(EXTI->RTSR, copy_u8Line);
        CLR_BIT(EXTI->FTSR, copy_u8Line);
    }
    else if (copy_u8Mode == EXTI_MODE_FALLING)
    {
        SET_BIT(EXTI->FTSR, copy_u8Line);
        CLR_BIT(EXTI->RTSR, copy_u8Line);
    }
    else if (copy_u8Mode == EXTI_MODE_ON_CHANGE)
    {
        SET_BIT(EXTI->RTSR, copy_u8Line);
        SET_BIT(EXTI->FTSR, copy_u8Line);
    }
}

void MEXTI_voidClearPendingBit(u8 copy_u8Line)
{
    if (copy_u8Line < 16)
        SET_BIT(EXTI->PR, copy_u8Line);
}

void MEXTI_voidSetCallBack(u8 copy_u8Line, void (*copy_ptr)(void))
{
    switch (copy_u8Line)
    {
        case LINE0:
            EXTI0_CallBack = copy_ptr;
            break;
        case LINE1:
            EXTI1_CallBack = copy_ptr;
            break;
        case LINE2:
            EXTI2_CallBack = copy_ptr;
            break;
        case LINE3:
            EXTI0_CallBack = copy_ptr;
            break;
        case LINE4:
            EXTI4_CallBack = copy_ptr;
            break;
        case LINE5:
        case LINE6:
        case LINE7:
        case LINE8:
        case LINE9:
            EXTI9_5_CallBack = copy_ptr;
            break;
        case LINE10:
        case LINE11:
        case LINE12:
        case LINE13:
        case LINE14:
        case LINE15:
            EXTI15_10_CallBack = copy_ptr;
        default:
            break;
    }
}

void EXTI0_IRQHandler(void)
{
    EXTI0_CallBack();
}

void EXTI1_IRQHandler(void)
{
    EXTI1_CallBack();
}

void EXTI2_IRQHandler(void)
{
    EXTI2_CallBack();
}

void EXTI3_IRQHandler(void)
{
    EXTI3_CallBack();
}

void EXTI4_IRQHandler(void)
{
    EXTI4_CallBack();
}

void EXTI9_5_IRQHandler(void)
{
    EXTI9_5_CallBack();
}

void EXTI15_10_IRQHandler(void)
{
    EXTI15_10_CallBack();
}