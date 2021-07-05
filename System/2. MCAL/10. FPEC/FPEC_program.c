/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   28 April 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "FPEC_interface.h"
#include "FPEC_private.h"
#include "FPEC_config.h"

void MFPEC_voidInit(void)
{
	/*	Unlock Flash	*/
	UnlockFlash();
}

void MFPEC_voidEraseAllPages(void)
{
	/*	Check if flash is locked	*/
		if (GET_BIT(FPEC->CR, 7) == 1)
		{
			UnlockFlash();
		}
	/*	Check busy flag				*/
	while(GET_BIT(FPEC->SR, 0) == 1);
	/*	Select mass erase op		*/
	SET_BIT(FPEC->CR, 2);
	/*	Start Erasing page			*/
	SET_BIT(FPEC->CR, 6);
	/*	Check busy flag				*/
	while(GET_BIT(FPEC->SR, 0) == 1);
}

void MFPEC_voidErasePage(u8 copy_u8PageNum)
{	
	/*	Check if flash is locked	*/
		if (GET_BIT(FPEC->CR, 7) == 1)
		{
			UnlockFlash();
		}
	/*	Check busy flag				*/
	while(GET_BIT(FPEC->SR, 0) == 1);
	/*	Select page erase OP		*/
	SET_BIT(FPEC->CR, 1);
	/*	Set page's address			*/
	FPEC->ACR = FPEC_PAGE_BASE_ADDR + ((u32)copy_u8PageNum * 0x400U);
	/*	Start Erasing page			*/
	SET_BIT(FPEC->CR, 6);
	/*	Check busy flag				*/
	while (GET_BIT(FPEC->SR, 0) == 1);
	/*	Reset end of OP				*/
	SET_BIT(FPEC->SR, 5);
	/*	End page erase OP			*/
	CLR_BIT(FPEC->CR, 1);
}

void MFPEC_voidProgramFlash(u32 copy_u32Address, u16 *copy_u16Data, u8 copy_u8length)
{
	volatile u16 *local_p16Addr = ((volatile u16 *)copy_u32Address);
	/*	Check address					*/
	if ((copy_u32Address >= FPEC_PAGE_BASE_ADDR) && (copy_u32Address < FPEC_PAGE_END_ADDR))
	{
		/*	Check if flash is locked	*/
		if (GET_BIT(FPEC->CR, 7) == 1)
		{
			UnlockFlash();
		}
		/*	Check busy flag				*/
		while (GET_BIT(FPEC->SR, 0) == 1);

		for (u8 i = 0; i <= copy_u8length; i++)
		{
			/*	Start programming OP	*/
			SET_BIT(FPEC->CR, 0);
			/*	Write data				*/
			*local_p16Addr = copy_u16Data[i];
			/*	Wait untill OP is done	*/
			while(GET_BIT(FPEC->SR, 0) == 1);
			/*	Check if addr is programmed correctly	*/
			if (*local_p16Addr != copy_u16Data[i])
			{
				break;
			}
			copy_u32Address += 2;
			/*	Reset end of OP			*/
			SET_BIT(FPEC->SR, 5);
			/*	End programming	OP		*/
			CLR_BIT(FPEC->CR, 0);
		}
	}
}

static inline void UnlockFlash(void)
{
	/*	Unlock Flash	*/
	FPEC->KEYR = FPEC_KEY1;
	FPEC->KEYR = FPEC_KEY2;
}