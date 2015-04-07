// #if ARDUINO >= 100
 // #include "Arduino.h"
// #else
 // #include "WProgram.h"
// #endif

#define swap(a, b) { uint8_t t = a; a = b; b = t; }
#ifndef SSD1306_DriverH
#define SSD1306_DriverH

#define BLACK 0
#define WHITE 1

/*=========================================================================
    SSD1306 Displays
    -----------------------------------------------------------------------
    The driver is used in multiple displays (128x64, 128x32, etc.).
    Select the appropriate display below to create an appropriately
    sized framebuffer, etc.

    SSD1306_128_64  128x64 pixel display

    SSD1306_128_32  128x32 pixel display

    You also need to set the LCDWIDTH and LCDHEIGHT defines to an 
    appropriate size

    -----------------------------------------------------------------------*/
#define SSD1306_128_64
//     #define SSD1306_128_32
/*=========================================================================*/

#if defined SSD1306_128_64 && defined SSD1306_128_32
  #error "Only one SSD1306 display can be specified at once in SSD1306.h"
#endif
#if !defined SSD1306_128_64 && !defined SSD1306_128_32
  #error "At least one SSD1306 display must be specified in SSD1306.h"
#endif

#if defined SSD1306_128_64
  #define SSD1306_LCDWIDTH              128
  #define SSD1306_LCDHEIGHT             64
#endif

#if defined SSD1306_128_32
  #define SSD1306_LCDWIDTH              128
  #define SSD1306_LCDHEIGHT             32
#endif

#define PAGE_MODE                       01
#define HORIZONTAL_MODE                 02

#define SSD1306_Addres_Write            0x78
#define SSD1306_Addres_Read             0b01111001

#define SSD1306_Command_Mode            0x80
#define SSD1306_Data_Mode               0x40

#define SSD1306_SET_CONTRAST 		0x81
#define SSD1306_DISPLAY_ALL_ON_RESUME   0xA4
#define SSD1306_DISPLAY_ALL_ON 		0xA5
#define SSD1306_DISPLAY_NORMAL 		0xA6
#define SSD1306_DISPLAY_INVERT		0xA7
#define SSD1306_DISPLAY_OFF 		0xAE
#define SSD1306_DISPLAY_ON 		0xAF

#define SSD1306_SET_DISPLAY_OFFSET 	0xD3
#define SSD1306_SET_COMPINS 		0xDA

#define SSD1306_SET_VCOM_DETECT		0xDB

#define SSD1306_SET_DISPLAY_CLOCK_DIV 	0xD5
#define SSD1306_SET_PRECHARGE 		0xD9

#define SSD1306_SET_MULTIPLEX 		0xA8

#define SSD1306_SET_LOW_COLUM_N 	0x00
#define SSD1306_SET_HIGH_COLUM_N 	0x10

#define SSD1306_SET_START_LINE 		0x40

#define SSD1306_MEMORY_MODE 		0x20

#define SSD1306_COM_SCAN_INC 		0xC0
#define SSD1306_COM_SCAN_DEC 		0xC8

#define SSD1306_SEG_REMAP 		0xA0

#define SSD1306_CHARGE_PUMP 		0x8D

#define SSD1306_EXTERNAL_VCC 		0x1
#define SSD1306_SWITCH_CAP_VCC 		0x2

#define SSD1306_Activate_Scroll_Cmd     0x2F
#define SSD1306_Dectivate_Scroll_Cmd    0x2E

#define Scroll_Left                     0x00
#define Scroll_Right                    0x01

#define uint8 unsigned int8
#define uint16 unsigned int16

uint8 addressingMode;

uint8 SSD1306_Init(void);
uint8 SSD1306_Init_X(void);
uint8 SSD1306_SurchForAddres(uint8 Command);
uint8 SSD1306_SendCommand(uint8 Command);
uint8 SSD1306_SendData(uint8 Data);
void SSD1306_setBrightness(uint8 Brightness);

void SSD1306_setHorizontalMode();
void SSD1306_setPageMode();
void SSD1306_setTextXY(uint8 Row, uint8 Column);
void SSD1306_clearDisplay();
void SSD1306_putChar(uint8 C);
void SSD1306_putString(char *StringP);
uint8 SSD1306_putNumber(signed long long_num);
void SSD1306_drawBitmap(uint8 *bitmaparray,uint8 bytes);

void SSD1306_setHorizontalScrollProperties(int1 direction, uint8 startPage, uint8 endPage, uint8 scrollSpeed);

void SSD1306_activateScroll();
void SSD1306_deactivateScroll();
void SSD1306_setNormalDisplay();
void SSD1306_setInverseDisplay();
#endif