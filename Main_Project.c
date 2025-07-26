#include <LPC21xx.h>
#include "delay.h"
#include "miniproject.h" 

#define sw1 19//menu mode
#define sw2 6//stop the alarm
#define BUZZER 5

u32 hour,min,sec,date,month,year,day;
u32 alh,almin,alsec;
u8 keyc;
int main()
{
	IODIR0|=1<<BUZZER;//buzzer init
	
	RTC_Init();
	InitLCD();
	Init_keypad();
	CmdLCD(0x0C);//DSP_ON_CUR_OFF
	RTCSetTime(03,45,00);
	RTCSetDate(10,02,2025);
	RTCSetDay(1);
	
	while(1)
	{
		RTCGetTime(&hour,&min,&sec);		
		DisplayRTCTime(hour,min,sec);
		RTCGetDate(&date,&month,&year);
		DisplayRTCDate(date,month,year);
		RTCGetDay(&day);
		DisplayRTCDay(day);
		if (((IOPIN0>>sw1)&1)==0)
		{
			while(((IOPIN0>>sw1)&1)==0);
			while(1)
			{
					CmdLCD(0x01);//CLEAR_LCD
					CmdLCD(0x80);//GOTO_LINE1_POS0
					StrLCD("1.RTC EDIT");
					StrLCD(" 3.EXIT");
					CmdLCD(0xC0);//GOTO_LINE2_POS0
					StrLCD("2.MEDICINE TIME EDIT");
					keyc=keyscan();
					if(keyc=='1')
					{
					    RTC_edit(&hour,&min,&sec,&day,&date,&year);
					}
					else if(keyc=='3')
					{
						CmdLCD(0x01);//clear dispaly
						break;
					}
					else if(keyc=='2')
					{
					   medicine_edit(alh,almin,alsec);	
					}
			}	
		}
		else if((HOUR==alh)&&(MIN==almin)&&(SEC==alsec))
			{
				  CmdLCD(0x01);//CLEAR_LCD
					CmdLCD(0x80);//GOTO_LINE1_POS0
					StrLCD("**!MEDICINE TIME!**");
					while(1)
					{
							IOPIN0=1<<BUZZER;//buzzer on
							delay_s(1);
							while(((IOPIN0>>sw2)&1)==1);
							IOCLR0=(1<<BUZZER);//buzzer off
						  CmdLCD(0x01);//clear dispaly
						   break;
					}
			}
	}
}


