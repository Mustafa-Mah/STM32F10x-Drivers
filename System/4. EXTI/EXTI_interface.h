/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   12 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _EXTI_INTERFACE_H_
#define _EXTI_INTERFACE_H_

// Lines
#define LINE0                   0
#define LINE1                   1
#define LINE2                   2
#define LINE3                   3
#define LINE4                   4
#define LINE5                   5
#define LINE6                   6
#define LINE7                   7
#define LINE8                   8
#define LINE9                   9
#define LINE10                  10
#define LINE11                  11
#define LINE12                  12
#define LINE13                  13
#define LINE14                  14
#define LINE15                  15

// Modes
#define EXTI_MODE_RISING        0
#define EXTI_MODE_FALLING       1
#define EXTI_MODE_ON_CHANGE     2

/*  Functions prototype	 */
void MEXTI_voidEnableEXTI(u8 copy_u8Line, u8 copy_u8Mode);
void MEXTI_voidDisableEXTI(u8 copy_u8Line);
void MEXTI_voidSWTrigger(u8 copy_u8Line);
void MEXTI_voidSetTriggerMode(u8 copy_u8Line, u8 copy_u8Mode);
void MEXTI_voidClearPendingBit(u8 copy_u8Line);
void MEXTI_voidSetCallBack(u8 copy_u8Line, void (*copy_ptr)(void));

#endif // _EXTI_INTERFACE_H_