/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   9 March 2021                                                            */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"

void MGPIO_voidSetPinDirection(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Mode)
{
    switch (copy_u8Port)
    {
        case GPIOA:
			if (copy_u8Pin < 8)
			{
				GPIOA_CRL &= ~((0b1111) << (copy_u8Pin << 2));		// Clearing mode bits
				GPIOA_CRL |= (copy_u8Mode << (copy_u8Pin << 2));	// Applying mode
			}
			else if (copy_u8Pin < 16)
			{
				copy_u8Pin = copy_u8Pin - 8;
				GPIOA_CRH &= ~((0b1111) << (copy_u8Pin << 2));		// Clearing mode bits
				GPIOA_CRH |= (copy_u8Mode << (copy_u8Pin << 2));	// Applying mode
			}
			break;
        case GPIOB:
			if (copy_u8Pin < 8)
			{
				GPIOB_CRL &= ~((0b1111) << (copy_u8Pin << 2));		// Clearing mode bits
				GPIOB_CRL |= (copy_u8Mode << (copy_u8Pin << 2));	// Applying mode
			}
			else if (copy_u8Pin < 16)
			{
				copy_u8Pin = copy_u8Pin - 8;
				GPIOB_CRH &= ~((0b1111) << (copy_u8Pin << 2));		// Clearing mode bits
				GPIOB_CRH |= (copy_u8Mode << (copy_u8Pin << 2));	// Applying mode
			}
			break;
        case GPIOC:
            if (copy_u8Pin < 8)
			{
				GPIOC_CRL &= ~((0b1111) << (copy_u8Pin << 2));		// Clearing mode bits
				GPIOC_CRL |= (copy_u8Mode << (copy_u8Pin << 2));	// Applying mode
			}
			else if (copy_u8Pin < 16)
			{
				copy_u8Pin = copy_u8Pin - 8;
				GPIOC_CRH &= ~((0b1111) << (copy_u8Pin << 2));		// Clearing mode bits
				GPIOC_CRH |= (copy_u8Mode << (copy_u8Pin << 2));	// Applying mode
			}
            break;
        case GPIOD:
            if (copy_u8Pin < 8)
			{
				GPIOD_CRL &= ~((0b1111) << (copy_u8Pin << 2));		// Clearing mode bits
				GPIOD_CRL |= (copy_u8Mode << (copy_u8Pin << 2));	// Applying mode
			}
			else if (copy_u8Pin < 16)
			{
				copy_u8Pin = copy_u8Pin - 8;
				GPIOD_CRH &= ~((0b1111) << (copy_u8Pin << 2));		// Clearing mode bits
				GPIOD_CRH |= (copy_u8Mode << (copy_u8Pin << 2));	// Applying mode
			}
            break;
        case GPIOE:
            if (copy_u8Pin < 8)
			{
				GPIOE_CRL &= ~((0b1111) << (copy_u8Pin << 2));		// Clearing mode bits
				GPIOE_CRL |= (copy_u8Mode << (copy_u8Pin << 2));	// Applying mode
			}
			else if (copy_u8Pin < 16)
			{
				copy_u8Pin = copy_u8Pin - 8;
				GPIOE_CRH &= ~((0b1111) << (copy_u8Pin << 2));		// Clearing mode bits
				GPIOE_CRH |= (copy_u8Mode << (copy_u8Pin << 2));	// Applying mode
			}
            break;
        case GPIOF:
            if (copy_u8Pin < 8)
			{
				GPIOF_CRL &= ~((0b1111) << (copy_u8Pin << 2));		// Clearing mode bits
				GPIOF_CRL |= (copy_u8Mode << (copy_u8Pin << 2));	// Applying mode
			}
			else if (copy_u8Pin < 16)
			{
				copy_u8Pin = copy_u8Pin - 8;
				GPIOF_CRH &= ~((0b1111) << (copy_u8Pin << 2));		// Clearing mode bits
				GPIOF_CRH |= (copy_u8Mode << (copy_u8Pin << 2));	// Applying mode
			}
            break;
        case GPIOG:
            if (copy_u8Pin < 8)
			{
				GPIOG_CRL &= ~((0b1111) << (copy_u8Pin << 2));		// Clearing mode bits
				GPIOG_CRL |= (copy_u8Mode << (copy_u8Pin << 2));	// Applying mode
			}
			else if (copy_u8Pin < 16)
			{
				copy_u8Pin = copy_u8Pin - 8;
				GPIOG_CRH &= ~((0b1111) << (copy_u8Pin << 2));		// Clearing mode bits
				GPIOG_CRH |= (copy_u8Mode << (copy_u8Pin << 2));	// Applying mode
			}
			break;
		default:
			break;
    }
}

void MGPIO_voidSetPinValue(u8 copy_u8Port, u8 copy_u8Pin, u8 copy_u8Val)
{
	switch (copy_u8Port)
    {
        case GPIOA:
			if (copy_u8Val == GPIO_HIGH)
			{
				GPIOA_BSRR = (1 << copy_u8Pin);						// Setting corresponding bit in BSRR
			}
			else if (copy_u8Val == GPIO_LOW)
			{
				GPIOA_BRR  = (1 << copy_u8Pin);						// Setting corresponding bit in BRR
			}
			break;
        case GPIOB:
			if (copy_u8Val == GPIO_HIGH)
			{
				GPIOB_BSRR = (1 << copy_u8Pin);						// Setting corresponding bit in BSRR
			}
			else if (copy_u8Val == GPIO_LOW)
			{
				GPIOB_BRR  = (1 << copy_u8Pin);						// Setting corresponding bit in BRR
			}
			break;
        case GPIOC:
            if (copy_u8Val == GPIO_HIGH)
			{
				GPIOC_BSRR = (1 << copy_u8Pin);						// Setting corresponding bit in BSRR
			}
			else if (copy_u8Val == GPIO_LOW)
			{
				GPIOC_BRR  = (1 << copy_u8Pin);						// Setting corresponding bit in BRR
			}
            break;
        case GPIOD:
            if (copy_u8Val == GPIO_HIGH)
			{
				GPIOD_BSRR = (1 << copy_u8Pin);						// Setting corresponding bit in BSRR
			}
			else if (copy_u8Val == GPIO_LOW)
			{
				GPIOD_BRR  = (1 << copy_u8Pin);						// Setting corresponding bit in BRR
			}
            break;
        case GPIOE:
            if (copy_u8Val == GPIO_HIGH)
			{
				GPIOE_BSRR = (1 << copy_u8Pin);						// Setting corresponding bit in BSRR
			}
			else if (copy_u8Val == GPIO_LOW)
			{
				GPIOE_BRR  = (1 << copy_u8Pin);						// Setting corresponding bit in BRR
			}
            break;
        case GPIOF:
            if (copy_u8Val == GPIO_HIGH)
			{
				GPIOF_BSRR = (1 << copy_u8Pin);						// Setting corresponding bit in BSRR
			}
			else if (copy_u8Val == GPIO_LOW)
			{
				GPIOF_BRR  = (1 << copy_u8Pin);						// Setting corresponding bit in BRR
			}
            break;
        case GPIOG:
            if (copy_u8Val == GPIO_HIGH)
			{
				GPIOG_BSRR = (1 << copy_u8Pin);						// Setting corresponding bit in BSRR
			}
			else if (copy_u8Val == GPIO_LOW)
			{
				GPIOG_BRR  = (1 << copy_u8Pin);						// Setting corresponding bit in BRR
			}
			break;
		default:
			break;
	}
}

u8 MGPIO_u8GetPinValue(u8 copy_u8Port, u8 copy_u8Pin)
{
	u8 local_u8Result = 0;
	switch (copy_u8Port)
    {
		// Getting corresponding bit from IDR
        case GPIOA:
			local_u8Result = GET_BIT(GPIOA_IDR, copy_u8Pin);
			break;
		case GPIOB:
			local_u8Result = GET_BIT(GPIOB_IDR, copy_u8Pin);
			break;
        case GPIOC:
            local_u8Result = GET_BIT(GPIOC_IDR, copy_u8Pin);
            break;
        case GPIOD:
            local_u8Result = GET_BIT(GPIOD_IDR, copy_u8Pin);
            break;
        case GPIOE:
            local_u8Result = GET_BIT(GPIOE_IDR, copy_u8Pin);
            break;
        case GPIOF:
            local_u8Result = GET_BIT(GPIOF_IDR, copy_u8Pin);
            break;
        case GPIOG:
            local_u8Result = GET_BIT(GPIOG_IDR, copy_u8Pin);
			break;
		default:
			break;
	}
    return local_u8Result;
}