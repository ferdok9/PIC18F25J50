

void rtc_init(unsigned char flag_inc);
void ds1307_write(unsigned char rtcreg, unsigned char rtc_data);
void ds1307_write_test(unsigned char rtcreg, unsigned int8 rtc_data);
void read_rtc(void);
void print_date_ds1307(void);
void print_hour_ds1307(void);
unsigned char read(unsigned char adr);
void min_inc(void);
void hour_inc(void);

unsigned int8 rtensec,rsec,rtenmin,rmin,rtenhour,rhour,rday,rtendate,rdate,rmonth,rtenmonth,rtenyear,ryear;

////////////////////////////////////////////////////////////////////////////////////////////////////////////
void hour_inc(void)
{
unsigned char flag_inc=0;

if( !input(PIN_B4)){
   delay_ms(170);
   read_rtc();
      if(!input_state(pin_B2))output_bit(PIN_B2,1);
      else output_bit(PIN_B2,0);

      flag_inc=1;
   if((rtenhour==1)|(rtenhour==0)){
      rhour++;
      if(rhour==10){
         rhour=0;
         rtenhour++;
      if(rtenhour==10)rtenhour=0;
      }
   }

   if(rtenhour==2){
      rhour++;
      if(rhour==4){
         rhour=0;
         rtenhour=0;
      }
   }
}
if(flag_inc){
   rtc_init(1);
   print_hour_ds1307();
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void min_inc(void)
{
unsigned char flag_inc=0;

if( !input(PIN_B3)){
   delay_ms(170);
   read_rtc();
      if(!input_state(pin_B2))output_bit(PIN_B2,1);
      else output_bit(PIN_B2,0);
   flag_inc=1;
   rmin++;
   if(rmin==10){
      rmin=0;
      rtenmin++;
      if(rtenmin==6)rtenmin=0;
   }
}
if(flag_inc){
   rtc_init(1);
   print_hour_ds1307();
}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rtc_init(unsigned char flag_inc){

//char string[10]= "asdasd";

if(flag_inc){

ds1307_write(3,0b00000001);
ds1307_write(4,0b00100011);
ds1307_write(5,0b00000001);
ds1307_write(6,0b00010010);
ds1307_write(7,0b00010000);

rtensec=5;
rsec=9;
rtenmin=5;
rmin=9;
rtenhour=0;
rhour=7;



//lcd_gotoxy(0,3);

//rtensec=rtensec&0b00001111;
rsec=rsec&0b00001111;

//rtenmin=rtenmin&0b00001111;
rmin=rmin&0b00001111;

rhour=rhour&0b00001111;

rtenhour=((rtenhour<<4)&0b00110000);
rtenmin=(rtenmin<<4)&0b01110000;
rtensec=(rtensec<<4)&0b01110000;

rhour=rtenhour|rhour;
rmin=rtenmin|rmin;
rsec=rtensec|rsec;

ds1307_write(0,rsec);
ds1307_write(1,rmin);
ds1307_write(2,rhour);


}
flag_inc=0;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_hour_ds1307(void)
{
static unsigned char delta_hour;

read_rtc();

if(rhour!=delta_hour)
{
delta_hour=rmin;
print_date_ds1307();
}

//lcd_gotoxy(1,1);

if(rtenhour!=0){
//lcd_gotoxy(1,1);
//printf(lcd_putc,"              ");
printf("%1u",rtenhour);   // percent one u
}
else{printf(" ");}
printf("%1u:",rhour);   // percent one u

printf("%1u",rtenmin);   // percent one u
printf("%1u:",rmin);

printf("%1u",rtensec);   // percent one u
printf("%1u",rsec);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_date_ds1307(void)
{
read_rtc();

//lcd_gotoxy(0,5);

printf("20");

printf("%1u",rtenyear);   // percent one u
printf("%1u/",ryear);   // percent one u

printf("%1u",rtenmonth);   // percent one u
printf("%1u/",rmonth);

printf("%1u",rtendate);   // percent one u
printf("%1u(",rdate);

if (rday==1){printf("Mo");}      // monday
else if (rday==2){printf("Tu");}   // tuesday
else if (rday==3){printf("We");}   // wednesday
else if (rday==4){printf("Th");}   // thursday
else if (rday==5){printf("Fr");}   // friday
else if (rday==6){printf("Sa");}   // saturday
else if (rday==7){printf("Su");}   // sunday
printf(")");

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
unsigned char read(unsigned char adr){
unsigned char popo;   
    i2c_start();
    i2c_write(0xd0);        // Device address
    i2c_write(adr);
    
    i2c_start();            // Restart 
    i2c_write(0xd1);        //   to change data direction
    popo=i2c_read(0);
    i2c_stop();
    return(popo);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void read_rtc(void)
{
rsec=read(0)&0x0f;
rtensec=(read(0)>>4) &0b00000111;

rmin=read(1)&0x0f;
rtenmin=(read(1)>>4) &0b00000111;

rhour=read(2)&0x0f;         
rtenhour=(read(2)>>4)&0b00000011;


rday=read(3)&0b00000111;

      
rdate=read(4)&0x0f;         
rtendate=(read(4)>>4)&0b00000011;   

rmonth=read(5)&0b00001111;      
rtenmonth=(read(5)>>4)&0b00000001;

ryear=read(6)&0x0f;      
rtenyear=(read(6)>>4)&0x0f;   
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ds1307_write(unsigned char rtcreg, unsigned int8 rtc_data)
{
i2c_start();
i2c_write(0xd0);
i2c_write(rtcreg);
i2c_write(rtc_data);
i2c_stop();
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ds1307_write_test(unsigned char rtcreg, unsigned int8 rtc_data)
{
	short ick[4]= {1,1,1,1};
i2c_start();
ick[0] = i2c_write(0xd0);
ick[1] = i2c_write(rtcreg);
ick[2] = i2c_write(rtc_data);
i2c_stop();
if(!(ick[0]||ick[1]||ick[2])){/*lcd_gotoxy(17,1);*/ printf("YES");}
else {/*lcd_gotoxy(17,1);*/ printf("NO");}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
