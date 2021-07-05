/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   13 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _STK_PRIVATE_H_
#define _STK_PRIVATE_H_

/*  Registers struct  */
typedef struct
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;
} STK_t;

#define STK                     ((volatile STK_t*)0xE000E010)

volatile u8 MSTK_u8Periodic = 0;
void (*MSTK_CallBack)(void);

// SysTick clock source options:
#define STK_CLK_AHP_DIV_8       0
#define STK_CLK_AHP             1

#endif // _STK_PRIVATE_H_