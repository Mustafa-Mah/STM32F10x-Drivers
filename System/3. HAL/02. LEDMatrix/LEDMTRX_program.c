/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   21 March 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMTRX_interface.h"
#include "LEDMTRX_private.h"
#include "LEDMTRX_config.h"

void HLEDMTRX_voidInit(void)
{
    // Setting row pins to output push-pull @2MHz
    MGPIO_voidSetPinDirection(LEDMTRX_ROW0_PIN, OUTPUT_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMTRX_ROW1_PIN, OUTPUT_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMTRX_ROW2_PIN, OUTPUT_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMTRX_ROW3_PIN, OUTPUT_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMTRX_ROW4_PIN, OUTPUT_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMTRX_ROW5_PIN, OUTPUT_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMTRX_ROW6_PIN, OUTPUT_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMTRX_ROW7_PIN, OUTPUT_2MHZ_PP);
    // Setting column pins to output push-pull @2MHz
    MGPIO_voidSetPinDirection(LEDMTRX_COL0_PIN, OUTPUT_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMTRX_COL1_PIN, OUTPUT_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMTRX_COL2_PIN, OUTPUT_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMTRX_COL3_PIN, OUTPUT_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMTRX_COL4_PIN, OUTPUT_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMTRX_COL5_PIN, OUTPUT_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMTRX_COL6_PIN, OUTPUT_2MHZ_PP);
    MGPIO_voidSetPinDirection(LEDMTRX_COL7_PIN, OUTPUT_2MHZ_PP);
    // Disable all columns
    DisableAllColumns();
}

void HLEDMTRX_voidDisplay(void)
{    
    // Display column 0
    MGPIO_voidSetPinValue(LEDMTRX_COL7_PIN, GPIO_HIGH);
    SetRowValue(LEDMTRX_Data[0]);
    MGPIO_voidSetPinValue(LEDMTRX_COL0_PIN, GPIO_LOW);    
    MSTK_voidSetBusyWait(2500);
    // Display column 1
    MGPIO_voidSetPinValue(LEDMTRX_COL0_PIN, GPIO_HIGH);
    SetRowValue(LEDMTRX_Data[1]);
    MGPIO_voidSetPinValue(LEDMTRX_COL1_PIN, GPIO_LOW);
    MSTK_voidSetBusyWait(2500);
    // Display column 2
    MGPIO_voidSetPinValue(LEDMTRX_COL1_PIN, GPIO_HIGH);
    SetRowValue(LEDMTRX_Data[2]);
    MGPIO_voidSetPinValue(LEDMTRX_COL2_PIN, GPIO_LOW);
    MSTK_voidSetBusyWait(2500);
    // Display column 3
    MGPIO_voidSetPinValue(LEDMTRX_COL2_PIN, GPIO_HIGH);
    SetRowValue(LEDMTRX_Data[3]);
    MGPIO_voidSetPinValue(LEDMTRX_COL3_PIN, GPIO_LOW);
    MSTK_voidSetBusyWait(2500);
    // Display column 4
    MGPIO_voidSetPinValue(LEDMTRX_COL3_PIN, GPIO_HIGH);
    SetRowValue(LEDMTRX_Data[4]);
    MGPIO_voidSetPinValue(LEDMTRX_COL4_PIN, GPIO_LOW);
    MSTK_voidSetBusyWait(2500);
    // Display column 5
    MGPIO_voidSetPinValue(LEDMTRX_COL4_PIN, GPIO_HIGH);
    SetRowValue(LEDMTRX_Data[5]);
    MGPIO_voidSetPinValue(LEDMTRX_COL5_PIN, GPIO_LOW);
    MSTK_voidSetBusyWait(2500);
    // Display column 6
    MGPIO_voidSetPinValue(LEDMTRX_COL5_PIN, GPIO_HIGH);
    SetRowValue(LEDMTRX_Data[6]);
    MGPIO_voidSetPinValue(LEDMTRX_COL6_PIN, GPIO_LOW);
    MSTK_voidSetBusyWait(2500);
    // Display column 7
    MGPIO_voidSetPinValue(LEDMTRX_COL6_PIN, GPIO_HIGH);
    SetRowValue(LEDMTRX_Data[7]);
    MGPIO_voidSetPinValue(LEDMTRX_COL7_PIN, GPIO_LOW);
    MSTK_voidSetBusyWait(2500);
}

void HLEDMTRX_voidSetDataArray(u8 *copy_u8Data)
{
    LEDMTRX_Data = copy_u8Data;
    LEDMTRX_NextCol = 0;
}

void HLEDMTRX_voidDisplayOSTask(void)
{
    if (LEDMTRX_NextCol > LEDMTRX_COL7)
    {
        LEDMTRX_NextCol = LEDMTRX_COL0;
    }

    switch (LEDMTRX_NextCol)
    {
        case LEDMTRX_COL0:
            MGPIO_voidSetPinValue(LEDMTRX_COL7_PIN, GPIO_HIGH);
            SetRowValue(LEDMTRX_Data[0]);
            MGPIO_voidSetPinValue(LEDMTRX_COL0_PIN, GPIO_LOW);
            break;
        case LEDMTRX_COL1:
            MGPIO_voidSetPinValue(LEDMTRX_COL0_PIN, GPIO_HIGH);
            SetRowValue(LEDMTRX_Data[1]);
            MGPIO_voidSetPinValue(LEDMTRX_COL1_PIN, GPIO_LOW);
            break;
        case LEDMTRX_COL2:
            MGPIO_voidSetPinValue(LEDMTRX_COL1_PIN, GPIO_HIGH);
            SetRowValue(LEDMTRX_Data[2]);
            MGPIO_voidSetPinValue(LEDMTRX_COL2_PIN, GPIO_LOW);
            break;
        case LEDMTRX_COL3:
            MGPIO_voidSetPinValue(LEDMTRX_COL2_PIN, GPIO_HIGH);
            SetRowValue(LEDMTRX_Data[3]);
            MGPIO_voidSetPinValue(LEDMTRX_COL3_PIN, GPIO_LOW);
            break;
        case LEDMTRX_COL4:
            MGPIO_voidSetPinValue(LEDMTRX_COL3_PIN, GPIO_HIGH);
            SetRowValue(LEDMTRX_Data[4]);
            MGPIO_voidSetPinValue(LEDMTRX_COL4_PIN, GPIO_LOW);
            break;
        case LEDMTRX_COL5:
            MGPIO_voidSetPinValue(LEDMTRX_COL4_PIN, GPIO_HIGH);
            SetRowValue(LEDMTRX_Data[5]);
            MGPIO_voidSetPinValue(LEDMTRX_COL5_PIN, GPIO_LOW);
            break;
        case LEDMTRX_COL6:
            MGPIO_voidSetPinValue(LEDMTRX_COL5_PIN, GPIO_HIGH);
            SetRowValue(LEDMTRX_Data[6]);
            MGPIO_voidSetPinValue(LEDMTRX_COL6_PIN, GPIO_LOW);
            break;
        case LEDMTRX_COL7:
            MGPIO_voidSetPinValue(LEDMTRX_COL6_PIN, GPIO_HIGH);
            SetRowValue(LEDMTRX_Data[7]);
            MGPIO_voidSetPinValue(LEDMTRX_COL7_PIN, GPIO_LOW);
            break;
        default:
            break;
    }
    LEDMTRX_NextCol++;  
}

u8 HLEDMTRX_u8GetColumnsDrawn(void)
{
	return LEDMTRX_NextCol;
}

static void DisableAllColumns(void)
{
    // Disable all columns
    MGPIO_voidSetPinValue(LEDMTRX_COL0_PIN, GPIO_HIGH);
    MGPIO_voidSetPinValue(LEDMTRX_COL1_PIN, GPIO_HIGH);
    MGPIO_voidSetPinValue(LEDMTRX_COL2_PIN, GPIO_HIGH);
    MGPIO_voidSetPinValue(LEDMTRX_COL3_PIN, GPIO_HIGH);
    MGPIO_voidSetPinValue(LEDMTRX_COL4_PIN, GPIO_HIGH);
    MGPIO_voidSetPinValue(LEDMTRX_COL5_PIN, GPIO_HIGH);
    MGPIO_voidSetPinValue(LEDMTRX_COL6_PIN, GPIO_HIGH);
    MGPIO_voidSetPinValue(LEDMTRX_COL7_PIN, GPIO_HIGH);
}

static void SetRowValue(u8 copy_u8Value)
{
    u8 local_u8Bit;
    local_u8Bit = GET_BIT(copy_u8Value, 0);
    MGPIO_voidSetPinValue(LEDMTRX_ROW0_PIN, local_u8Bit);
    local_u8Bit = GET_BIT(copy_u8Value, 1);
    MGPIO_voidSetPinValue(LEDMTRX_ROW1_PIN, local_u8Bit);
    local_u8Bit = GET_BIT(copy_u8Value, 2);
    MGPIO_voidSetPinValue(LEDMTRX_ROW2_PIN, local_u8Bit);
    local_u8Bit = GET_BIT(copy_u8Value, 3);
    MGPIO_voidSetPinValue(LEDMTRX_ROW3_PIN, local_u8Bit);
    local_u8Bit = GET_BIT(copy_u8Value, 4);
    MGPIO_voidSetPinValue(LEDMTRX_ROW4_PIN, local_u8Bit);
    local_u8Bit = GET_BIT(copy_u8Value, 5);
    MGPIO_voidSetPinValue(LEDMTRX_ROW5_PIN, local_u8Bit);
    local_u8Bit = GET_BIT(copy_u8Value, 6);
    MGPIO_voidSetPinValue(LEDMTRX_ROW6_PIN, local_u8Bit);
    local_u8Bit = GET_BIT(copy_u8Value, 7);
    MGPIO_voidSetPinValue(LEDMTRX_ROW7_PIN, local_u8Bit);
}