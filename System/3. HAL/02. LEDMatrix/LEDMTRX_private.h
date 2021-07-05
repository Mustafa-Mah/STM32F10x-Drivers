/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   21 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _LEDMTRX_PRIVATE_H_
#define _LEDMTRX_PRIVATE_H_

#define LEDMTRX_COL0            0
#define LEDMTRX_COL1            1
#define LEDMTRX_COL2            2
#define LEDMTRX_COL3            3
#define LEDMTRX_COL4            4
#define LEDMTRX_COL5            5
#define LEDMTRX_COL6            6
#define LEDMTRX_COL7            7

volatile u8 LEDMTRX_NextCol = 0;
volatile u8 volatile *LEDMTRX_Data = 0;

static void DisableAllColumns(void);
static void SetRowValue(u8 copy_u8Value);

#endif // _LEDMTRX_PRIVATE_H_