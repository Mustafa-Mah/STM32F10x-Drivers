/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   28 April 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#ifndef _FPEC_PRIVATE_H_
#define _FPEC_PRIVATE_H_

/*
Key values
The key values are as follows:
● RDPRT key = 0x00A5
● KEY1 = 0x45670123
● KEY2 = 0xCDEF89AB
*/

#define FPEC_RDPRT              0x00A5
#define FPEC_KEY1               0x45670123U
#define FPEC_KEY2       		0xCDEF89ABU
#define FPEC_PAGE_BASE_ADDR     0x08000000U
#define FPEC_PAGE_END_ADDR		FPEC_PAGE_BASE_ADDR + 0x7FFFU	/*	32KB Flash limit	*/
#define FPEC_OPTION_BASE_ADDR   0x1FFFF800U

typedef struct
{
    volatile u32 ACR;
    volatile u32 KEYR;
    volatile u32 OPTKEYR;
    volatile u32 SR;
    volatile u32 CR;
    volatile u32 AR;
    volatile const u32 RESERVED;
    volatile u32 OBR;
    volatile u32 WRPR;
} FPEC_t;

/*typedef struct
{
    volatile u8 RDP;
    volatile const u8 RESERVED;
    volatile u8 USER;
    volatile const u8 RESERVED;
    volatile u8 DATA0;
    volatile const u8 RESERVED;
    volatile u8 DATA1;
    volatile const u8 RESERVED;
    volatile u8 WRP0;
    volatile const u8 RESERVED;
    volatile u8 WRP1;
    volatile const u8 RESERVED;
    volatile u8 WRP2;
    volatile const u8 RESERVED;
    volatile u8 WRP3;
    volatile const u8 RESERVED;
} FPEC_OPTION_t;*/

#define FPEC 					((volatile FPEC_t *)0x40022000)
/*#define FPEC_OPTION 			((volatile FPEC_OPTION_t *)FPEC_OPTION_BASE_ADDR)*/

static inline void UnlockFlash(void);
static u8 CalcCheckSum(u8 *copy_u8Bytes);

#endif // _FPEC_PRIVATE_H_