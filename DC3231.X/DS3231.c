#include "DS3231.h"



////////////////////////////////////////////////////////////////////////////////
void DS3231_Write(uint8 u8AddresP, uint8 *pDataP, uint8 u8NumberOfBytesP)
{
    uint8 u8ByteCountL=1;
    i2c_start();
    i2c_write( DS3231_WriteX );

    i2c_write(u8AddresP);

    for( u8ByteCountL=1; u8ByteCountL <= u8NumberOfBytesP; u8ByteCountL++ )
    {
        i2c_write(pDataP[u8ByteCountL-1]);
    }

    i2c_stop();         // Restart
}

////////////////////////////////////////////////////////////////////////////////
void DS3231_Read(uint8 u8AddresP, uint8 *pDataP, uint8 u8NumberOfBytesP)
{
    uint8 u8ByteCountL=1;

    i2c_start();
//    printf("\n\rStart1");
    i2c_write( DS3231_ReadX );
//    printf("\n\rWrite2");
    i2c_write( u8AddresP );
//    printf("\n\rAfter Addres3");
    
//    for( u8ByteCountL=1; u8ByteCountL < (u8NumberOfBytesP); u8ByteCountL++ )
//    {
//        pDataP[u8ByteCountL] = i2c_read(TRUE);  // Data to device
//        printf("\n\ru8ByteCountL=%d\n\r",u8ByteCountL);
//    }
//    pDataP[u8NumberOfBytesP] = i2c_read(FALSE);
    pDataP = i2c_read(FALSE);
//    printf("\n\rlast write");
    i2c_stop();         // Restart
//    printf("\n\rStop\n\r");
}

////////////////////////////////////////////////////////////////////////////////
uint8 DS3231_Reade_Pointer(uint8 u8AddresP, uint8 *pDataP, uint8 u8NumberOfBytesP)
{
    uint8 u8ByteCountL=1;
    uint8 pAckL[3];

    i2c_start();
    pAckL[0] = i2c_write( DS3231_WriteX );
    pAckL[1] = i2c_write( u8AddresP );
    pAckL[1] <<= 1;
    i2c_start();
    pAckL[2] = i2c_write(DS3231_ReadX);
    pAckL[2] <<= 2;

    for( u8ByteCountL=1; u8ByteCountL < u8NumberOfBytesP; u8ByteCountL++ )
    {
        pDataP[u8ByteCountL-1] = i2c_read(TRUE);  // Data to device
    }

    pDataP[u8NumberOfBytesP-1] = i2c_read(FALSE);
    i2c_stop();         // Restart

    return ( pAckL[0] | pAckL[1] | pAckL[2] );
}
////////////////////////////////////////////////////////////////////////////////
void DS3231_Init_Clock(uint8 u8FlagInitP,uint8 *pDataP)
{
    uint8 u8TenSecL=5;
    uint8 u8SecL=9;
    uint8 u8TenMinL=5;
    uint8 u8MinL=9;
    uint8 u8TenHourL=2;
    uint8 u8HourL=3;

    if( u8FlagInitP == 1)
    {
        u8TenSecL = pDataP[TenSec];
        u8SecL = pDataP[Sec];
        u8TenMinL = pDataP[TenMin];
        u8MinL = pDataP[Min];
        u8TenHourL = pDataP[TenHour];
        u8HourL = pDataP[Hour];
    }

    u8SecL&=Sec_Mask;
    u8MinL&=Min_Mask;
    u8HourL&=Hour_Mask;

    u8TenSecL <<= 4;
    u8TenMinL <<= 4;
    u8TenHourL <<= 4;

    u8TenSecL &= TenSec_Mask;
    u8TenMinL &= TenMin_Mask;
    u8TenHourL &= TenHour_Mask;

    u8SecL|=u8TensecL;
    u8MinL|=u8TenMinL;
    u8HourL|=u8TenHourL;

    DS3231_Write(0,&u8SecL,1);
    DS3231_Write(1,&u8MinL,1);
    DS3231_Write(2,&u8HourL,1);

}
////////////////////////////////////////////////////////////////////////////////
void DS3231_Init_Data(uint8 u8FlagInitP,uint8 *pDataP)
{
    uint8 u8TenDateL    =2;
    uint8 u8DateL       =7;

    uint8 u8TenMonthL   =1;
    uint8 u8MonthL      =2;

    uint8 u8TenYearL    =1;
    uint8 u8YearL       =5;

    if(u8FlagInitP == 1)
    {
        u8TenDateL  = pDataP[TenDate];
        u8DateL     = pDataP[Date];
        u8TenMonthL = pDataP[TenMonth];
        u8MonthL    = pDataP[Month];
        u8TenYearL  = pDataP[TenYear];
        u8YearL     = pDataP[Year];
    }

    u8DateL &= Date_Mask;
    u8MonthL &= Month_Mask;
    u8YearL &= Year_Mask;

    u8TenDateL  <<= 4;
    u8TenMonthL <<= 4;
    u8TenYearL  <<= 4;

    u8TenDateL  &= TenDate_Mask;
    u8TenMonthL &= TenMonth_Mask;
    u8TenYearL  &= TenYear_Mask;

    u8DateL |= u8TenDateL;
    u8MonthL |= u8TenMonthL;
    u8YearL |= u8TenYearL;

    DS3231_Write(4,&u8DateL,1);
    DS3231_Write(5,&u8MonthL,1);
    DS3231_Write(6,&u8YearL,1);

}

////////////////////////////////////////////////////////////////////////////////
void DS3231_Read_Clock(uint8 *pDataP)
{
    uint8 ClockBuff[3];

    DS3231_Reade_Pointer(0,ClockBuff,3);

    pDataP[Sec]     = (ClockBuff[0] & Sec_Mask);
    pDataP[TenSec]  = ((ClockBuff[0] & TenSec_Mask)>>4);
    pDataP[Min]     = (ClockBuff[1] & Min_Mask);
    pDataP[TenMin]  = ((ClockBuff[1] & TenMin_Mask)>>4);
    pDataP[Hour]    = (ClockBuff[2] & Hour_Mask);
    pDataP[TenHour] = ((ClockBuff[2] & TenHour_Mask)>>4);
}
////////////////////////////////////////////////////////////////////////////////
void DS3231_Print_Clock(uint8 *pDataP)
{

    DS3231_Read_Clock(pDataP);
    printf("\n\r%d%d:%d%d:%d%d",pDataP[TenHour],pDataP[Hour],
                           pDataP[TenMin],pDataP[Min],
                           pDataP[TenSec],pDataP[Sec]);

}
////////////////////////////////////////////////////////////////////////////////
void DS3231_Read_Data(uint8 *pDataP)
{
    uint8 ClockBuff[4];

    DS3231_Reade_Pointer(3,ClockBuff,4);

    pDataP[Day]     = (ClockBuff[1] & Day_Mask);

    pDataP[Date]     = (ClockBuff[1] & Date_Mask);
    pDataP[TenDate]  = ((ClockBuff[1] & TenDate_Mask)>>4);
    pDataP[Month]     = (ClockBuff[2] & Month_Mask);
    pDataP[TenMonth]  = ((ClockBuff[2] & TenMonth_Mask)>>4);
    pDataP[Year]    = (ClockBuff[3] & Year_Mask);
    pDataP[TenYear] = ((ClockBuff[3] & TenYear_Mask)>>4);
}
////////////////////////////////////////////////////////////////////////////////
void DS3231_Print_Data(uint8 *pDataP)
{

    DS3231_Read_Data(pDataP);
    printf("\n\r%d%d\\%d%d\\%d%d  ",pDataP[TenDate],pDataP[Date],
                           pDataP[TenMonth],pDataP[Month],
                           pDataP[TenYear],pDataP[Year]);
    switch(pDataP[Day])
    {
        case Monday : 
            printf("Mo");
            break;
        case Tuesday :
            printf("Tu");
            break;
        case Wednesday :
            printf("We");
            break;
        case Thursday :
            printf("Th");
            break;
        case Friday :
            printf("Fr");
            break;
        case Saturday :
            printf("Sa");
            break;
        case Sunday :
            printf("Su");
            break;
    }

}
////////////////////////////////////////////////////////////////////////////////
void DS3231_String_To_Massiv_Clock(uint8 *pDataP)
{
    pDataP[0] = cMsgClock[7];
    pDataP[1] = cMsgClock[6];

    pDataP[2] = cMsgClock[4];
    pDataP[3] = cMsgClock[3];

    pDataP[4] = cMsgClock[1];
    pDataP[5] = cMsgClock[0];
}
////////////////////////////////////////////////////////////////////////////////
void DS3231_String_To_Massiv_Data(uint8 *pDataP)
{
    pDataP[0] = cMsgData[7];
    pDataP[1] = cMsgData[6];

    pDataP[2] = cMsgData[4];
    pDataP[3] = cMsgData[3];

    pDataP[4] = cMsgData[1];
    pDataP[5] = cMsgData[0];
}