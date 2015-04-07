
	#define NOP #asm nop #endasm
	#define BTG() #asm btg #endasm

	#byte	STATUS          =       0xFD8
	#bit	Cery            =       STATUS.0 //No carry-out from the MSb of the result occurred

	#byte	OSCCON          =       0xFD3
        #bit    OSTS            =       OSCCON.3 //Oscillator Start-up Timer time-out has expired

//PORT

	//PORTA
	#byte 	PORTA		= 0xF80   // PORTA
	#byte 	TRISA		= 0xF92   // PORTA tris
	#byte 	LATA		= 0xF89   // PORTB LAT

	#bit a0 = PORTA.0
	#bit a1 = PORTA.1
	#bit a2 = PORTA.2
	#bit a3 = PORTA.3
	#bit a4 = PORTA.4
	#bit a5 = PORTA.5
	#bit a6 = PORTA.6

	//PORTB
	#byte 	PORTB		= 0xF81   // PORTB
	#byte 	TRISB		= 0xF93   // PORTB tris
	#byte 	LATB		= 0xF8A   // PORTB LAT

	#bit b0 = PORTB.0
	#bit b1 = PORTB.1
	#bit b2 = PORTB.2
	#bit b3 = PORTB.3
	#bit b4 = PORTB.4
	#bit b5 = PORTB.5
	#bit b6 = PORTB.6
	#bit b7 = PORTB.7

	//PORTC
	#byte 	PORTC		= 0xF82   // PORTC
	#byte 	TRISC		= 0xF94   // PORTC tris
	#byte 	LATC		= 0xF8B   // PORTB LAT

	#bit c0 = PORTC.0			
	#bit c1 = PORTC.1
	#bit c2 = PORTC.2
	#bit c3 = PORTC.3
	#bit c4 = PORTC.4
	#bit c5 = PORTC.5
	#bit c6 = PORTC.6
	#bit c7 = PORTC.7

//INTERRUPT
	#byte 	PIR1		=	0xF9E
	#byte 	PIR2		=	0xFA1
	#byte 	PIR3		=	0xFA4
	#byte 	PIE1		=	0xF9D
	#byte 	PIE2		=	0xFA0
	#byte 	PIE3		=	0xFA3
	#byte 	IPR1		=	0xF9F
	#byte 	IPR3		=	0xFA5
	#byte 	IPR2		=	0xFA2

	#byte 	INTCON		=	0xFF2		//INTERRUPT CONTROL REGISTER
	#byte 	PIE1		=	0xF9D		//PERIPHERAL INTERRUPT ENABLE REGISTER 1
	#byte	PIE2		=	0xFA0		//PERIPHERAL INTERRUPT ENABLE REGISTER 2
	#byte	PIE3		=	0xFA3		//PERIPHERAL INTERRUPT ENABLE REGISTER 3
	#bit	GIE		=	INTCON.7	//Global Interrupt Enable bit

//TIMER 
	#byte	T1CON		=	0xFCD		//TIMER1 CONTROL REGISTER
	#bit	TMR1IE		=	PIE1.0		//TMR1 Overflow Interrupt Enable bit
	#byte 	T1GCON		=	0xF9A		//TIMER1 GATE CONTROL REGISTER
	#byte 	TMR1L		=	0xFCE
	#byte 	TMR1H		=	0xFCF
	#byte 	T0CON		=	0xFD5		//TIMER0 CONTROL REGISTER
	#bit	TMR0IE	 	=	INTCON.5	//TMR0 Overflow Interrupt Enable bit

//CCP
	#byte 	CCP1CON		=	0xFBA		//ENHANCED CAPTURE/COMPARE/PWM x CONTROL REGISTER
	#byte 	CCP2CON		=	0xFB4		//ENHANCED CAPTURE/COMPARE/PWM x CONTROL REGISTER
	#byte 	CCPR1H		=	0xFBC
	#byte 	CCPR1L		=	0xFBB
	#bit	CCP1IF		=	PIR1.2
	#bit	CCP2IF		=	PIR2.0
	#bit	CCP1IE		=	PIE1.2
	#bit	CCP2IE		=	PIE2.0

//USART
	#bit	RC1IE		=	PIE1.5		//EUSART1 Receive Interrupt Enable
	#bit	TX1IE		=	PIE1.4		//EUSART1 Transmit Interrupt Enable bit
	#bit	RC2IE		=	PIE3.5		//EUSART2 Receive Interrupt Enable
	#bit	TX2IE		=	PIE3.4		//EUSART2 Transmit Interrupt Enable bit

	#byte 	TXSTA1		=	0xFAD
	#byte 	TXSTA2		=	0xFA8
	#byte 	RCSTA1		=	0xFAC
	#byte 	RCSTA2		=	0xF9C
	#byte 	BAUDCON1	=	0xF7E
	#bit	BRGH1		=	BAUDCON1.3
	#byte 	BAUDCON2	=	0xF7C
	#bit	BRGH2		=	BAUDCON2.3
	#byte 	SPBRGH1		=	0xF7F
	#byte 	SPBRGH2		=	0xF7D
	#byte 	SPBRG1		=	0xFB0
	#byte 	SPBRG2		=	0xFAB
	#byte 	TXREG1		=	0xFAE
	#byte 	TXREG2		=	0xFA9
	#byte 	RCREG1		=	0xFAF
	#byte 	RCREG2		=	0xFAA

	#byte 	ODCON1		=	0xF42
	#byte 	ODCON2		=	0xF41
	#byte 	ODCON3		=	0xF40
//RTC
//	#bit	RTCCIE	=	INTCON.5	//RTCC Interrupt Enable

//PPS
	#byte 	PPSCON		=	0xEFF		//PERIPHERAL PIN SELECT INPUT REGISTER 0
	#bit	IOLOCK		=	PPSCON.0	//I/O Lock Enable bit
	#byte 	RPINR7		=	0xEED		//Assign Input Capture 1 (ECCP1) to the Corresponding RPn Pin bits
	#byte 	RPINR16		=	0xEF6		//Peripheral Pin Select Input Register 16
	#byte 	EECON2		=	0xFA7		//Program Memory Control Register 2
	#byte 	RPOR7		=	0xECD		//PERIPHERAL PIN SELECT OUTPUT REGISTER 7


//OSCTUNE
	#byte 	OSCTUNEF	=	0xF9B		//OSCILLATOR TUNING REGISTER
	#bit	PLLEN		=	OSCTUNEF.6


//MSSP
	#byte 	SSP1STAT	=	0xFC7
	#byte 	SSP2STAT	=	0xF73
	#bit	BF1			=	SSP1STAT.0
	#bit	BF2			=	SSP2STAT.0

	#byte 	SSP1CON1	=	0xFC6
	#byte 	SSP2CON1	=	0xF72
	#bit	CKP1			=	SSP1CON1.4
	#bit	CKP2			=	SSP2CON1.4

	#byte 	SSP1BUF		=	0xFC9
	#byte 	SSP2BUF		=	0xF75

