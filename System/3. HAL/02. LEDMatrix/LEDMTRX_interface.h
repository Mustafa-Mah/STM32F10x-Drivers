/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   21 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _LEDMTRX_INTERFACE_H_
#define _LEDMTRX_INTERFACE_H_

void HLEDMTRX_voidInit(void);
void HLEDMTRX_voidSetDataArray(u8 *copy_u8Data);
void HLEDMTRX_voidDisplay(void);
void HLEDMTRX_voidDisplayOSTask(void);
u8 HLEDMTRX_u8GetColumnsDrawn(void);

#endif // _LEDMTRX_INTERFACE_H_