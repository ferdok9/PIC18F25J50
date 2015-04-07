
#define     DS3231_WriteX    0xD0
#define     DS3231_ReadX     0xD1

#define Sec             0
#define TenSec          1
#define Min             2
#define TenMin          3
#define Hour            4
#define TenHour         5

#define Day             0
#define Date            1
#define TenDate         2
#define Month           3
#define TenMonth        4
#define Year            5
#define TenYear         6

#define Sec_Mask             0b00001111
#define TenSec_Mask          0b01110000
#define Min_Mask             0b00001111
#define TenMin_Mask          0b01110000
#define Hour_Mask            0b00001111
#define TenHour_Mask         0b00110000

#define Day_Mask             0b00000111
#define Date_Mask            0b00001111
#define TenDate_Mask         0b00110000
#define Month_Mask           0b00001111
#define TenMonth_Mask        0b00010000
#define Year_Mask            0b00001111
#define TenYear_Mask         0b11110000

#define Monday      1
#define Tuesday     2
#define Wednesday   3
#define Thursday    4
#define Friday      5
#define Saturday    6
#define Sunday      7

static char cMsgClock[10];
static char cMsgData[10];
static uint8 u8StateMashine = 0;
static uint8 u8MsgCount=0;
static uint8 u8FlagSet = 0;

void DS3231_Write(uint8 u8AddresP, uint8 *pDataP, uint8 u8NumberOfBytesP);
void DS3231_Read(uint8 u8AddresP, uint8 *pDataP, uint8 u8NumberOfBytesP);

uint8 DS3231_Reade_Pointer(uint8 u8AddresP, uint8 *pDataP, uint8 u8NumberOfBytesP);

void DS3231_Init_Clock(uint8 u8FlagInitP,uint8 *pDataP);
void DS3231_Init_Data(uint8 u8FlagInitP,uint8 *pDataP);
void DS3231_Read_Clock(uint8 *pDataP);

void DS3231_Read_Data(uint8 *pDataP);
void DS3231_Print_Data(uint8 *pDataP);

void DS3231_String_To_Massiv_Clock(uint8 *pDataP);
void DS3231_String_To_Massiv_Data(uint8 *pDataP);

