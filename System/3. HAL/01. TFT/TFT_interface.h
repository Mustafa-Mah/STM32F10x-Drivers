/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   06 April 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _TFT_INTERFACE_H_
#define _TFT_INTERFACE_H_

void HTFT_voidInit(void);
void HTFT_voidDisplayImage(const u16 *copy_pu16Image);
void HTFT_voidFillColor(u16 copy_u16Color);
void HTFT_voidDrawRectangle(u16 copy_u16Color, u8 copy_u8XStart, u8 copy_u8XEnd, 
                            u8 copy_u8YStart, u8 copy_u8YEnd);
void HTFT_voidWriteString(u16 copy_u16ForeColor, u16 copy_u16BackColor, 
                          u8 copy_u8Col, u8 copy_u8Row, u8 *copy_pu8String);

#endif // _TFT_INTERFACE_H_