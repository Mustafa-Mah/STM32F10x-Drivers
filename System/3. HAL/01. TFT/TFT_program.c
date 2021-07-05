/****************************************************************************************/
/* Author   :   Mustafa Mahmoud Mustafa                                                 */
/* Date     :   06 April 2021                                                           */
/* Version  :   V01                                                                     */
/****************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "SPI_interface.h"
#include "GPIO_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"
#include "TFT_font.h"

void HTFT_voidInit(void)
{    
    /*  Sending reset sequence                          
     *  100us H >> 1us L >> 100us H >> 100us L >> 120ms H   */
    MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
    MSTK_voidSetBusyWait(100);
    MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_LOW);
    MSTK_voidSetBusyWait(1);
    MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
    MSTK_voidSetBusyWait(100);
    MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_LOW);
    MSTK_voidSetBusyWait(100);
    MGPIO_voidSetPinValue(TFT_RST_PIN,GPIO_HIGH);
    MSTK_voidSetBusyWait(120000);
    /*  Sending sleep out command                           */
    voidWriteCommand(0x11);
    /*  Waiting for 150ms                                   */
    MSTK_voidSetBusyWait(150000);
    /*  Sending color mode command                          */
    voidWriteCommand(0x3A);
    /*  Sending color mode parameter                        */
    voidWriteData(0x05);
    /*  Sending display on command                          */
    voidWriteCommand(0x29);
}

void HTFT_voidDisplayImage(const u16 *copy_pu16Image)
{
    u8 local_u8Temp;
    /*  Set x address               */
    voidWriteCommand(0x2A);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(127);
    /*  Set y address               */
    voidWriteCommand(0x2B);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(159);
    /*  Sending RAM write command   */
    voidWriteCommand(0x2C);
    /*  Sending pixels' data        */
    for (u16 i = 0; i < 20480; i++)
    {
        /*  Sending high byte       */
        local_u8Temp = (u8)(copy_pu16Image[i] >> 8);
        voidWriteData(local_u8Temp);
        /*  Sending low byte        */
        local_u8Temp = (u8)copy_pu16Image[i];
        voidWriteData(local_u8Temp);
    }
}

void HTFT_voidFillColor(u16 copy_u16Color)
{
    /*  Set x address               */
    voidWriteCommand(0x2A);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(127);
    /*  Set y address               */
    voidWriteCommand(0x2B);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(0);
    voidWriteData(159);
    /*  Sending RAM write command   */
    voidWriteCommand(0x2C);
    /*  Sending pixels' data        */
    for (u16 i = 0; i < 20480; i++)
    {
        /*  Sending high byte       */
        voidWriteData((u8)(copy_u16Color >> 8));
        /*  Sending low byte        */
        voidWriteData((u8)copy_u16Color);
    }
}

void HTFT_voidDrawRectangle(u16 copy_u16Color, u8 copy_u8XStart, u8 copy_u8XEnd, u8 copy_u8YStart, u8 copy_u8YEnd)
{
    u16 local_u16PixelCount = (copy_u8XEnd - copy_u8XStart + 1) * (copy_u8YEnd - copy_u8YStart + 1);
    /*  Set x address               */
    voidWriteCommand(0x2A);
    voidWriteData(0);
    voidWriteData(copy_u8XStart);
    voidWriteData(0);
    voidWriteData(copy_u8XEnd);
    /*  Set y address               */
    voidWriteCommand(0x2B);
    voidWriteData(0);
    voidWriteData(copy_u8YStart);
    voidWriteData(0);
    voidWriteData(copy_u8YEnd);
    /*  Sending RAM write command   */
    voidWriteCommand(0x2C);
    /*  Sending pixels' data        */
    for (u16 i = 0; i < local_u16PixelCount; i++)
    {
        /*  Sending high byte       */
        voidWriteData((u8)(copy_u16Color >> 8));
        /*  Sending low byte        */
        voidWriteData((u8)copy_u16Color);
    }
}

void HTFT_voidWriteString(u16 copy_u16ForeColor, u16 copy_u16BackColor, u8 copy_u8Col, u8 copy_u8Row, u8 *copy_pu8String)
{
    const u8 *local_u8ImgTemp;
    u8 local_u8Bit;
    u8 local_u8CharID;
    u8 local_u8XStart = 0;
    u8 local_u8XEnd = 0;
    u8 local_u8YStart = 0;
    u8 local_u8YEnd = 0;
    u8 local_u8StringLen = u8GetStringLength(copy_pu8String);    
    /*  Limit line length to 16 chars   */
    if (local_u8StringLen > 16)
    {
        local_u8StringLen = 16;
    }
    /*  Limit column indx to 16         */
    if (copy_u8Col < 16)
    {
        local_u8XStart = copy_u8Col << 3;
    }
    /*  Width = #char * char width      */
    local_u8XEnd = local_u8XStart + (local_u8StringLen << 3) - 1;
    /*  Limit row indx to 10            */
    if (copy_u8Row < 10)
    {
        local_u8YStart = copy_u8Row << 4;
    }
    /*  Height = char height = 16       */
    local_u8YEnd = local_u8YStart + TFT_CHAR_HEIGHT - 1;
    /*  Set x address                   */
    voidWriteCommand(0x2A);
    voidWriteData(0);
    voidWriteData(local_u8XStart);
    voidWriteData(0);
    voidWriteData(local_u8XEnd);
    /*  Set y address                   */
    voidWriteCommand(0x2B);
    voidWriteData(0);
    voidWriteData(local_u8YStart);
    voidWriteData(0);
    voidWriteData(local_u8YEnd);
    /*  Sending RAM write command       */
    voidWriteCommand(0x2C);
    /*  Start drawing pixels row by row */
    for (u8 k = 0; k < TFT_CHAR_HEIGHT; k++)
    {
        /*  Display whole row k         */
        for (u8 i = 0; i < local_u8StringLen; i++)
        {
            /*  Display row k of char i */
            local_u8CharID = copy_pu8String[i] - 0x20;
            local_u8ImgTemp = Font_array[local_u8CharID].image;
            for (u8 j = 0; j < TFT_CHAR_WIDTH; j++)
            {
                /*  Display 8 pixels of char i  */
                local_u8Bit = GET_BIT((local_u8ImgTemp[k]), j);
                /*  Check corresponding pixel
                 *  0 means draw pixel
                 *  1 means don't draw pixel    */
                if (local_u8Bit == 0)
                {
                    /*  Sending high byte       */
                    voidWriteData((u8)(copy_u16ForeColor >> 8));
                    /*  Sending low byte        */
                    voidWriteData((u8)copy_u16ForeColor);
                }
                else
                {
                    /*  Sending high byte       */
                    voidWriteData((u8)(copy_u16BackColor >> 8));
                    /*  Sending low byte        */
                    voidWriteData((u8)copy_u16BackColor);
                }
            }
        }
    }
}

static void voidWriteCommand(u8 copy_u8CMD)
{
    /*  Set A0 pin to low               */
    MGPIO_voidSetPinValue(TFT_A0_PIN, GPIO_LOW);
    /*  Send command over SPIx          */
    (void)MSPI_u32SendReceiveDataSync(SPIx_USED, copy_u8CMD);
}

static void voidWriteData(u8 copy_u8Data)
{
    /*  Set A0 pin to high              */
    MGPIO_voidSetPinValue(TFT_A0_PIN, GPIO_HIGH);
    /*  Send data over SPIx             */
    (void)MSPI_u32SendReceiveDataSync(SPIx_USED, copy_u8Data);
}

static u8 u8GetStringLength(u8 *copy_pu8String)
{
    u8 local_u8Result = 0;

    while (copy_pu8String[local_u8Result] != '\0')
    {
        local_u8Result++;
    }
    return local_u8Result;
}