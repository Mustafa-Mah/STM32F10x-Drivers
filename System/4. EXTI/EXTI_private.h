/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   12 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _EXTI_PRIVATE_H_
#define _EXTI_PRIVATE_H_

/*  Registers struct  */
typedef struct
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXTI_t;

#define EXTI                    ((volatile EXTI_t*)0x40010400)

void (*EXTI0_CallBack) (void);
void (*EXTI1_CallBack) (void);
void (*EXTI2_CallBack) (void);
void (*EXTI3_CallBack) (void);
void (*EXTI4_CallBack) (void);
void (*EXTI9_5_CallBack) (void);
void (*EXTI15_10_CallBack) (void);

#endif // _EXTI_PRIVATE_H_