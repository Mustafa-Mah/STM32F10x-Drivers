/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   13 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_private.h"
#include "AFIO_config.h"

void MAFIO_voidConfigEXTI(u8 copy_u8Line, u8 copy_u8Port)
{
    u8 local_u8MaskPos = ((copy_u8Line & 0b11) << 2);                       // Getting starting position for mask
    u8 local_u8CnfgRegIdx = (copy_u8Line >> 2);                             // Getting corresponding EXTICR index

    AFIO->EXTICR[local_u8CnfgRegIdx] &= ~(0b1111 << local_u8MaskPos);       // Clearing Corresponding bits
    AFIO->EXTICR[local_u8CnfgRegIdx] |= (copy_u8Port << local_u8MaskPos);   // Applying selected port
}
/*
0101 > 01
0110 > 01
0011 > 00
1001 > 10
1100 > 11
*/