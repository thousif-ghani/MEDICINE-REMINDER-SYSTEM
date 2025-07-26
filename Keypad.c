#include <lpc21xx.h>
#include "keypad.h"
//unsigned char keypad_LUT[4][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
unsigned char keypad_LUT[4][4]={{'7','8','9','/'},{'4','5','6','X'},{'1','2','3','-'},{'c','0','=','+'}};

void Init_keypad(void)
{
	IODIR1|=(15<<ROW0);
}
unsigned char keyscan(void)
{
	unsigned  char rno,cno,keyv;
	while(colscan()==0);//switch_press condition
	rno=rowcheck();
	cno=colcheck();
	keyv=keypad_LUT[rno][cno];
	while(colscan());
	return keyv; 
}
unsigned char colscan(void)
{
	return (((IOPIN1>>COL0)&15)<15)?1:0;//switch_press(return 1),switch_press(return 0)
}
unsigned char rowcheck(void)
{
	unsigned char rno;
	for(rno=0;rno<4;rno++)
	{
		IOPIN1=(IOPIN1&~(15<<ROW0))|((~(1<<rno))<<ROW0);
		if(colscan()==1)
		{
			break;
		}
	}
	IOPIN1=(IOPIN1&~(15<<ROW0))|(0x0<<ROW0);
	return rno;
}
unsigned char colcheck(void)
{
	unsigned char cno;
	for(cno=0;cno<4;cno++)
		{
		if(((IOPIN1>>(COL0+cno))&1)==0)
		{
			break;
		}
	}
		return cno;
}
