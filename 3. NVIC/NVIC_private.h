/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   11 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _NVIC_PRIVATE_H_
#define _NVIC_PRIVATE_H_

/*  Registers Definition  */
#define NVIC_ISER0              *((u32*)0xE000E100)
#define NVIC_ISER1              *((u32*)0xE000E104)
#define NVIC_ISER2              *((u32*)0xE000E108)

#define NVIC_ICER0              *((u32*)0xE000E180)
#define NVIC_ICER1              *((u32*)0xE000E184)
#define NVIC_ICER2              *((u32*)0xE000E188)

#define NVIC_ISPR0              *((u32*)0xE000E200)
#define NVIC_ISPR1              *((u32*)0xE000E204)
#define NVIC_ISPR2              *((u32*)0xE000E208)

#define NVIC_ICPR0              *((u32*)0xE000E280)
#define NVIC_ICPR1              *((u32*)0xE000E284)
#define NVIC_ICPR2              *((u32*)0xE000E288)

#define NVIC_IABR0              *((volatile u32*)0xE000E300)
#define NVIC_IABR1              *((volatile u32*)0xE000E304)
#define NVIC_IABR2              *((volatile u32*)0xE000E308)

#define NVIC_IPR                 ((volatile u8 *)0xE000E400)
#define SCB_AIRCR               *((volatile u32*)0xE000ED0C)    // Temporarily 

// Priority grouping
#define GROUPS4_SUB0            0x05FA0300              // 4 Groups - 0 Sub Groups
#define GROUPS3_SUB1            0x05FA0400              // 3 Groups - 1 Sub Groups
#define GROUPS2_SUB2            0x05FA0500              // 2 Groups - 2 Sub Groups
#define GROUPS1_SUB3            0x05FA0600              // 1 Groups - 3 Sub Groups
#define GROUPS0_SUB4            0x05FA0700              // 0 Groups - 4 Sub Groups

#endif // _NVIC_PRIVATE_H_