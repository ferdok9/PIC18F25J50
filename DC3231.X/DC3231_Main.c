#include "Config.h"
//#include "ds1307_25J50.c"

#include "SSD1306.c"
//#include "Bitmap_logo.c"
#include "DS3231.c"
void main()
{
    uint8 u8CountL=0;

    while(OSTS == 0);

//    delay_ms( 250 );
    PLLEN = 1;

    delay_ms( 250 );

    printf("\n\rStavat\n\r");

    DS3231_Init();

//    u8CountL = DS3231_Read_Test();

    u8CountL = DS3231_Reade_Multiple(DS3231_Def_Control, 0x12 , Ds3231_Data);
    
    printf("\n\rasdasd   %x\n\r",u8CountL);
//
//    for(u8CountL=0;u8CountL <= DS3231_Def_Number_Of_Bytes; u8CountL++)
//    {
//        printf("\n\rByte%x:    %X\n\r",u8CountL, Ds3231_Data[u8CountL]);
//    }


    while(TRUE)//FALSE)//
    {
//        printf("\n\rStavat\n\r");
        delay_ms(400);
    }
}