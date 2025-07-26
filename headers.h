#include "lcd.h"
#include "keypad.h"
#include "types.h"  
#ifndef _MINIIPROJECT_H
#define _MINIPROJECT_H
void RTC_Init(void);	
void RTCSetTime(u32 h,u32 min,u32 s);
void RTCSetDate(u32 d,u32 m,u32 y);
void RTCSetDay(u32 d);

void RTCGetTime(u32 *h,u32 *m,u32 *s);
void DisplayRTCTime(u32 h, u32 m,u32 s);
void RTCGetDate(u32 *dom,u32 *mon,u32 *y);
void DisplayRTCDate(u32 dom,u32 mon,u32 y);
void RTCGetDay(u32 *day);
void DisplayRTCDay(u32 day);

void RTC_edit(u32 *hour,u32 *min,u32 *sec,u32 *day,u32 *date, u32 *year);
void medicine_edit(u32 rem_h,u32 rem_min,u32 rem_sec);

#endif


