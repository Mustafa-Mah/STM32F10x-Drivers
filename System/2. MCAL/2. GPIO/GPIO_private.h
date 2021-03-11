/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   9 March 2021                                                            */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _GPIO_PRIVATE_H_
#define _GPIO_PRIVATE_H_

/*  Registers Definition  */
// PORTA
#define GPIOA_CRL               *((u32*)0x40010800)
#define GPIOA_CRH               *((u32*)0x40010804)
#define GPIOA_IDR               *((u32*)0x40010808)
#define GPIOA_ODR               *((u32*)0x4001080C)
#define GPIOA_BSRR              *((u32*)0x40010810)
#define GPIOA_BRR               *((u32*)0x40010814)
#define GPIOA_LCKR              *((u32*)0x40010818)
// PORTB
#define GPIOB_CRL               *((u32*)0x40010C00)
#define GPIOB_CRH               *((u32*)0x40010C04)
#define GPIOB_IDR               *((u32*)0x40010C08)
#define GPIOB_ODR               *((u32*)0x40010C0C)
#define GPIOB_BSRR              *((u32*)0x40010C10)
#define GPIOB_BRR               *((u32*)0x40010C14)
#define GPIOB_LCKR              *((u32*)0x40010C18)
// PORTC
#define GPIOC_CRL               *((u32*)0x40011000)
#define GPIOC_CRH               *((u32*)0x40011004)
#define GPIOC_IDR               *((u32*)0x40011008)
#define GPIOC_ODR               *((u32*)0x4001100C)
#define GPIOC_BSRR              *((u32*)0x40011010)
#define GPIOC_BRR               *((u32*)0x40011014)
#define GPIOC_LCKR              *((u32*)0x40011018)
// PORTD
#define GPIOD_CRL               *((u32*)0x40011400)
#define GPIOD_CRH               *((u32*)0x40011404)
#define GPIOD_IDR               *((u32*)0x40011408)
#define GPIOD_ODR               *((u32*)0x4001140C)
#define GPIOD_BSRR              *((u32*)0x40011410)
#define GPIOD_BRR               *((u32*)0x40011414)
#define GPIOD_LCKR              *((u32*)0x40011418)
// PORTE
#define GPIOE_CRL               *((u32*)0x40011800)
#define GPIOE_CRH               *((u32*)0x40011804)
#define GPIOE_IDR               *((u32*)0x40011808)
#define GPIOE_ODR               *((u32*)0x4001180C)
#define GPIOE_BSRR              *((u32*)0x40011810)
#define GPIOE_BRR               *((u32*)0x40011814)
#define GPIOE_LCKR              *((u32*)0x40011818)
// PORTF
#define GPIOF_CRL               *((u32*)0x40011C00)
#define GPIOF_CRH               *((u32*)0x40011C04)
#define GPIOF_IDR               *((u32*)0x40011C08)
#define GPIOF_ODR               *((u32*)0x40011C0C)
#define GPIOF_BSRR              *((u32*)0x40011C10)
#define GPIOF_BRR               *((u32*)0x40011C14)
#define GPIOF_LCKR              *((u32*)0x40011C18)
// PORTG
#define GPIOG_CRL               *((u32*)0x40012000)
#define GPIOG_CRH               *((u32*)0x40012004)
#define GPIOG_IDR               *((u32*)0x40012008)
#define GPIOG_ODR               *((u32*)0x4001200C)
#define GPIOG_BSRR              *((u32*)0x40012010)
#define GPIOG_BRR               *((u32*)0x40012014)
#define GPIOG_LCKR              *((u32*)0x40012018)

#endif // _GPIO_PRIVATE_H_