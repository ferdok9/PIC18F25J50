#include <18F25J50.h>

#include "SFR.h"

#device adc=16
//#device ICD = TRUE
#fuses NOWDT            //No Watch Dog Timer
#FUSES WDT128                   //Watch Dog Timer uses 1:128 Postscale
#FUSES NOXINST                  //Extended set extension and Indexed Addressing mode disabled (Legacy mode)
#FUSES NOIOL1WAY             	//Allows multiple reconfigurations of peripheral pins
//#FUSES PROTECT                  //Code protected from reads
//#FUSES HS                       //High speed Osc (> 4mhz for PCM/PCH) (>10mhz for PCD)

#fuses NOFCMEN          //Fail-safe clock monitor disabled
#fuses NOIESO           //Internal External Switch Over mode disabled

//48MHz
#fuses INTRC_PLL_IO

#fuses PLL2             //Divide By 2(8MHz oscillator input)
#fuses NOCPUDIV         //System Clock by 1

#use delay(clock=48MHZ,RESTART_WDT)

////8MHz
//#fuses INTRC
//
//#fuses PLL2             //Divide By 2(8MHz oscillator input)
//#fuses NOCPUDIV         //System Clock by 1
//
//#use delay(clock=8MHZ,RESTART_WDT)

//#PIN_SELECT CCP1 = PIN_C0
//#pin_select TX2 = PIN_B4
//#pin_select RX2 = PIN_B5

#use rs232(UART1,baud=115200,xmit=PIN_C6,rcv=PIN_C7,bits=8,parity=N,STOP=1)
//#use rs232(UART2,baud=9600,parity=E,xmit=PIN_B4,rcv=PIN_B5,bits=8,stream=PORT2,STOP=1)

#use i2c(master, sda=PIN_B5, scl=PIN_B4, slow, FORCE_HW, fast=400000)



