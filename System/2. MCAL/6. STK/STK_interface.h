/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   13 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _STK_INTERFACE_H_
#define _STK_INTERFACE_H_

/*  Functions prototype	 */
void MSTK_voidInitSysTick(void);
void MSTK_voidSetBusyWait(u32 copy_u32Ticks);
void MSTK_voidSetIntervalPeriodic(u32 copy_u32Ticks, void (*copy_ptr)(void));
void MSTK_voidSetIntervalSingle(u32 copy_u32Ticks, void (*copy_ptr)(void));
void MSTK_voidStopTimer(void);
u32  MSTK_u32GetElapsedTicks(void);
u32  MSTK_u32GetRemainingTicks(void);
u8   MSTK_u8GetCountFlag(void);

#endif // _STK_INTERFACE_H_