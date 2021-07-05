/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   06 April 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _TFT_PRIVATE_H_
#define _TFT_PRIVATE_H_

static void voidWriteCommand(u8 copy_u8CMD);
static void voidWriteData(u8 copy_u8Data);
static u8 u8GetStringLength(u8 *copy_pu8String);

#endif // _TFT_PRIVATE_H_