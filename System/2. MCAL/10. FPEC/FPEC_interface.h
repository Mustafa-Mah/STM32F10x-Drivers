/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   28 April 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _FPEC_INTERFACE_H_
#define _FPEC_INTERFACE_H_

void MFPEC_voidInit(void);
void MFPEC_voidEraseAllPages(void);
void MFPEC_voidErasePage(u8 copy_u8PageNum);
void MFPEC_voidProgramFlash(u32 copy_u32Address, u16 *copy_u16Data, u8 copy_u8length);
void MFPEC_voidEraseOptionByte(u32 copy_u32Address);
void MFPEC_voidWriteOptionByte(u32 copy_u32Address);

#endif // _FPEC_INTERFACE_H_