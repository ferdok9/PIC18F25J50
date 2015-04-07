#include "Config.h"
//#include "ds1307_25J50.c"

#include "SSD1306.c"
//#include "Bitmap_logo.c"
#include "DS3231.c"
//static char cMessage[16]= "kogato togava";
//static uint8 u8StateMashine = 0;
//static uint8 u8MsgCount=0;
//static uint8 u8FlagSet = 0;
//#013#010kotarak#013#010
#int_RDA	//priema ot mashinata
void  RDA_isr(void)
{
   char c;
   c = fgetc();

   switch(u8StateMashine)
   {
       case 0:
           if(c == 13)
           {
                u8StateMashine = 1;
           }
           else
           {
                u8StateMashine = 0;
           }
           break;

       case 1:
           if(c == 10)
           {                

                u8StateMashine = 2;
                u8MsgCount=0;
           }
           else
           {
                u8StateMashine = 0;
           }
           break;

       case 2:
           if(c == 13)
           {
             
                u8StateMashine = 3;
           }
           else
           {
               cMsgClock[u8MsgCount] = c;
               u8MsgCount++;
               //fputc(c);
           }
           break;

       case 3:
           if(c == 10)
           {
                cMsgClock[u8MsgCount] = 0;
                u8StateMashine = 0;
                printf("\n\r%s",cMsgClock);
                u8FlagSet = 1;
           }
           else
           {
                u8StateMashine = 0;
           }
           break;
           
   }
//               printf("\n\r%s",cMessage);
//   fputc(c);
}

void main()
{
    uint8 DataL[16];
    uint8 u8Count = 0;
    uint8 u8AckL = 0;

    while(OSTS == 0);
    PLLEN = 1;

    delay_ms( 250 );

//    PIE1 |= 0x20;// EUSART1 Receive Interrupt Enable
//    GIE = 1;//      enable_interrupts
    enable_interrupts(INT_RDA);
    enable_interrupts(INT_RDA2);
    enable_interrupts(GLOBAL);

    printf("\n\rproba za init\n\r");

    for(u8Count = 0; u8Count <= 15; u8Count++)
    {
       DataL[u8Count]=0;
    }
    
//    DS3231_Init_Clock(0,DataL);
//    DS3231_Init_Data(0,DataL);

    printf("\n\rAfter SetClock\n\r");
//    u8AckL = DS3231_Reade_Pointer(0x00, &DataL, 16);
//    printf("\n\rDS3231_u8AckL=0x%x\n\r",u8AckL);

//    for(u8Count = 0; u8Count <= 15; u8Count++)
//    {
//        printf("\n\rData[%d]=%d\n\r",u8Count,DataL[u8Count]);
//    }
    
//    u8AckL = SSD1306_SendCommand(SSD1306_DISPLAY_NORMAL);
//    printf("\n\rSSD1306_u8AckL=0x%x\n\r",u8AckL);
    
    while(TRUE)//FALSE)//
    {
//        u8AckL = DS3231_Reade_Pointer(0x00, &DataL[0], 1);
//        printf("\n\rSEkundi = %x\n\r",DataL[0]);
        DS3231_Print_Clock(DataL);
        DS3231_Print_Data(DataL);
        if(1==u8FlagSet)
        {
            DS3231_String_To_Massiv_Clock(DataL);
            //DS3231_Init_Clock(1,DataL);

            u8FlagSet=0;
        }
        delay_ms(1000);
    }
}
