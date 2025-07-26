#include <LPC21xx.h>
#include "types.h"
#include "lcd.h"
#include "delay.h"
#include "keypad.h"
extern int alh,almin,alsec;
void set_hour(void);
void set_min(void);
void set_sec(void);

void set_date(void);
void set_mon(void);
void set_year(void);

void set_day(void);

void set_rhour(void);
void set_rmin(void);
void set_rsec(void);
void RTC_edit(u32 *hour,u32 *min,u32 *sec,u32 *day,u32 *date, u32 *year)
{
		while(1)
		{
		u8 keyc;
		CmdLCD(0x01);
		CmdLCD(0x80);
		StrLCD("1.HOUR 2.MIN 3.SEC");
		CmdLCD(0xc0);
		StrLCD("4.DATE 5.MON 6.YEAR");
		CmdLCD(0x94);	
		StrLCD("7.DAY 8.EXIT");
		keyc=keyscan();
			delay_s(1);
		if(keyc=='1')
		{
			CmdLCD(0x01);
			set_hour();
		}
		else if(keyc=='2')
		{
			CmdLCD(0x01);
			set_min();
		}
		else if(keyc=='3')
		{
			CmdLCD(0x01);
			set_sec();
		}
		else if(keyc=='4')
		{
			CmdLCD(0x01);
		set_date();
		}
		else if(keyc=='5')
		{
				CmdLCD(0x01);
			set_mon();
		}
		else if(keyc=='6')
		{
				CmdLCD(0x01);
			set_year();
		}
		else if(keyc=='7')
		{	CmdLCD(0x01);
			set_day();
		}
		else if(keyc=='8')
			return;
		}
}
void set_hour(void)
{
		s32 arr[3],i,res=0;
		StrLCD("HOUR:");
		CmdLCD(0xc0);
		for(i=0;i<2;i++)
		{
			arr[i]=keyscan();
			delay_ms(100);
			CharLCD(arr[i]);
		}
		arr[i]='\0';
		for(i=0;i<2;i++)
		{
			res=(res*10+(arr[i]-48));
		}
		if(keyscan() =='=')
		{
			if(!(res<=23 && res>=1))
			{
				CmdLCD(0X01);
				CmdLCD(0x80);
				StrLCD("HOURS NOT FOUND");		
				CmdLCD(0XC0);
				StrLCD("HOUR 0-23");
				delay_s(1);
				return ;
			}
			else
			{
				CmdLCD(0xc0);
				U32LCD(res);
				HOUR=res;
			StrLCD("HOUR UPDATED");
			delay_s(1);
			}
		}
}
void set_min(void)
{
	s32 arr[3],i,res=0;
	StrLCD("MIN:");
	CmdLCD(0xc0);
	for(i=0;i<2;i++)
	{
		arr[i]=keyscan();
				delay_ms(100);
		CharLCD(arr[i]);
	}
	arr[i]='\0';
	for(i=0;i<2;i++)
	{
		res=(res*10+arr[i])-48;
	}
	if(keyscan() =='=')
	{
		if(!(res<=59 && res>=0))
		{
		CmdLCD(0X01);
			CmdLCD(0x80);
			StrLCD("MIN NOT FOUND");
			//delay_s(1);
			CmdLCD(0XC0);
			StrLCD("MIN 0-59");
			delay_s(1);
			return ;
		}
		else
		{
			CmdLCD(0xc0);
			U32LCD(res);
			MIN=res;
		StrLCD("MIN UPDATED");
		delay_s(1);
		}
	}
}
	void set_sec(void)
{
	s32 arr[3],i,res=0;
	StrLCD("SEC:");
	CmdLCD(0xc0);
	for(i=0;i<2;i++)
	{
		arr[i]=keyscan();
				delay_ms(100);
		CharLCD(arr[i]);
	}
	arr[i]='\0';
	for(i=0;i<2;i++)
	{
		res=(res*10+arr[i])-48;
	}
	if(keyscan() =='=')
	{
		if(!(res<=59 && res>=0))
		{
		CmdLCD(0X01);
			CmdLCD(0x80);
			StrLCD("SEC NOT FOUND");
			CmdLCD(0XC0);
			StrLCD("SEC 0-59");
			delay_s(1);
			return ;
		}
		else
		{
			CmdLCD(0xc0);
			U32LCD(res);
			SEC=res;
		  StrLCD("SEC UPDATED");
		  delay_s(1);
		}
	}
}
	void set_date(void)
{
	s32 arr[3],i,res=0;
	StrLCD("DATE:");
	CmdLCD(0xc0);
	for(i=0;i<2;i++)
	{
		arr[i]=keyscan();
				delay_ms(100);
		CharLCD(arr[i]);
	}
	arr[i]='\0';
	for(i=0;i<2;i++)
	{
		res=(res*10+arr[i])-48;
	}
	if(keyscan() =='=')
	{
		if(!(res<=31&& res>=1))
		{
		CmdLCD(0X01);
			CmdLCD(0x80);
			StrLCD("DATE NOT FOUND");
			CmdLCD(0XC0);
			StrLCD("DATE 1-31");
			delay_s(1);
			return ;
		}
		else
		{
			CmdLCD(0xc0);
			U32LCD(res);
			DOM=res;
		StrLCD("DATE updated");
		delay_s(1);
	}
}
}
	void set_mon(void)
{
	s32 arr[3],i,res=0;
	StrLCD("MONTH:");
	CmdLCD(0xc0);
	for(i=0;i<2;i++)
	{
		arr[i]=keyscan();
				delay_ms(100);
		CharLCD(arr[i]);
	}
	arr[i]='\0';
	for(i=0;i<2;i++)
	{
		res=(res*10+arr[i])-48;
	}
	
	if(keyscan() =='=')
	{
		if(!(res<=12 && res>=1))
		{
		CmdLCD(0X01);
			CmdLCD(0x80);
			StrLCD("MONTH NOT FOUND");
			CmdLCD(0XC0);
			StrLCD("MONTH 1-12");
			delay_s(1);
			return ;
		}
		else
		{
			CmdLCD(0xc0);
			U32LCD(res);
			MONTH=res;
		StrLCD("MONTH UPDATED");
		delay_s(1);
	}
}
}
void set_year(void)
{
	s32 arr[6],i,res=0;
	StrLCD("YEAR:");
	CmdLCD(0xc0);
	for(i=0;i<4;i++)
	{
		arr[i]=keyscan();
				delay_ms(100);
		CharLCD(arr[i]);
	}
	arr[i]='\0';
	for(i=0;i<4;i++)
	{
		res=(res*10+arr[i])-48;
	}
	if(keyscan()=='=')
	{
		if(!(res<=2030 && res>=2000))
		{
		CmdLCD(0X01);
			CmdLCD(0x80);
			StrLCD("YEAR NOT FOUND");
			CmdLCD(0XC0);
			StrLCD("YEAR 2000-2030");
			delay_s(1);
			return ;
		}
		else
		{
			CmdLCD(0xc0);
			U32LCD(res);
			YEAR=res;
		StrLCD("YEAR UPDATED");
		delay_s(1);
	}
}
}
void set_day(void)
{
	s32 res=0;
	StrLCD("DAY:");
	CmdLCD(0xc0);
	res=(keyscan())-'0';
	U32LCD(res);
	delay_ms(100);
	if(keyscan() =='=')
	{
		if(!(res<=6 && res>=0))
		{
		CmdLCD(0X01);
			CmdLCD(0x80);
			StrLCD("DAY NOT FOUND");
			CmdLCD(0XC0);
			StrLCD("day 0-6");
			delay_s(1);
			return ;
		}
		else
		{
			CmdLCD(0xc0);
			U32LCD(res);
			DOW=res;
		StrLCD("DAY UPDATED");
		delay_s(1);
	}
}
}
void medicine_edit(u32 *rem_h,u32 *rem_min,u32 *rem_sec)
{
	while(1)
	{
	u8 keyc;
	CmdLCD(0x01);
	CmdLCD(0x80);
	StrLCD("1.HOUR 2.MIN 3.SEC");
	CmdLCD(0xc0);	
	StrLCD("4.EXIT  C.DISPALY");
	keyc=keyscan();
	delay_ms(200);
	if(keyc=='c')
	{
		CmdLCD(0x94);
		U32LCD(alh);
		CharLCD(':');
		U32LCD(almin);
		CharLCD(':');
		U32LCD(alsec);
		delay_s(1);
	}
		
	if(keyc=='1')
	{
		CmdLCD(0x01);
		set_rhour();
	}
	else if(keyc=='2')
	{
		CmdLCD(0x01);
		set_rmin();
	}
	else if(keyc=='3')
	{
		CmdLCD(0x01);
	  set_rsec();
	}
	else if(keyc=='4')
		return;
}
}
void set_rhour(void)
{
	s32 arr[3],i,res=0;
	StrLCD("HOUR:");
	CmdLCD(0xc0);
	for(i=0;i<2;i++)
	{
		arr[i]=keyscan();
		delay_ms(100);
		CharLCD(arr[i]);
	}
	arr[i]='\0';
	for(i=0;i<2;i++)
	{
		res=(res*10+(arr[i]-48));
	}
	if(keyscan() =='=')
	{
		if(!(res<=23 && res>=1))
		{
	  	CmdLCD(0X01);
			CmdLCD(0x80);
			StrLCD("HOURS NOT FOUND");
			
			CmdLCD(0XC0);
			StrLCD("HOUR 0-23");
			delay_s(1);
			return ;
		}
		else
		{
			CmdLCD(0xc0);
			U32LCD(res);
			alh=res;
		StrLCD("HOUR UPDATED");
		delay_s(1);
		}
	}
}
void set_rmin(void)
{
	s32 arr[3],i,res=0;
	StrLCD("MIN:");
	CmdLCD(0xc0);
	for(i=0;i<2;i++)
	{
		arr[i]=keyscan();
				delay_ms(100);
		CharLCD(arr[i]);
	}
	arr[i]='\0';
	for(i=0;i<2;i++)
	{
		res=(res*10+arr[i])-48;
	}
	if(keyscan() =='=')
	{
		if(!(res<=59 && res>=0))
		{
		CmdLCD(0X01);
			CmdLCD(0x80);
			StrLCD("MIN NOT FOUND");
			//delay_s(1);
			CmdLCD(0XC0);
			StrLCD("MIN 0-59");
			delay_s(1);
			return ;
		}
		else
		{
			CmdLCD(0xc0);
			U32LCD(res);
			almin=res;
		StrLCD("MIN UPDATED");
		delay_s(1);
		}
	}
}
void set_rsec(void)
{
	s32 arr[3],i,res=0;
	StrLCD("SEC:");
	CmdLCD(0xc0);
	for(i=0;i<2;i++)
	{
		arr[i]=keyscan();
				delay_ms(100);
		CharLCD(arr[i]);
	}
	arr[i]='\0';
	for(i=0;i<2;i++)
	{
		res=(res*10+arr[i])-48;
	}
	if(keyscan() =='=')
	{
		if(!(res<=59 && res>=0))
		{
		CmdLCD(0X01);
			CmdLCD(0x80);
			StrLCD("SEC NOT FOUND");
			CmdLCD(0XC0);
			StrLCD("SEC 0-59");
			delay_s(1);
			return ;
		}
		else
		{
			CmdLCD(0xc0);
			U32LCD(res);
			alsec=res;
		  StrLCD("SEC UPDATED");
		  delay_s(1);
		}
	}
}	

	
	
