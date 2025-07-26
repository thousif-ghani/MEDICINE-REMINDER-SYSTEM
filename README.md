Project Title: Medicine Reminder System Using LPC2148

Overview: This embedded project is a Real-Time Clock (RTC) based Medicine Reminder System built on the LPC2148 microcontroller. It keeps track of time using RTC and alerts the user with a buzzer when it's time to take their medicine. The system also includes a menu interface via keypad for setting time and medicine reminders, and a 16x2 LCD for user display.

Features:
Display current time, date, and day on an LCD.

Set and edit RTC time and medicine reminder time.

Buzzer alert at the set medicine time.

User interaction via push buttons and a keypad.

Hardware Requirements:
LPC2148 ARM7 Development Board

16x2 LCD

Matrix Keypad (4x4 or 4x3)

Buzzer

Push Buttons (Menu and Stop Alarm)

Power supply module

Supporting components (resistors, wires, etc.)

Pin Configuration:
BUZZER: P0.5

Menu Button (sw1): P0.19

Stop Alarm Button (sw2): P0.6

Included Files:
Main_Project.c – main program source code

delay.h – delay routines

miniproject.h – header for custom functions like LCD, RTC, keypad, edit functions, etc.

Code Flow Summary:
Initialization:

Configure Buzzer output pin.

Initialize RTC, LCD, and Keypad.

Set default time and date.

Main Loop:

Continuously fetch and display current time, date, and day on LCD.

Detects Menu Button press (sw1) to enter setting mode:

Option 1: RTC time editing.

Option 2: Set medicine reminder time.

Option 3: Exit menu.

If current time equals medicine reminder time:

Activate buzzer.

Show "!MEDICINE TIME!" message.

Wait for Stop Alarm Button (sw2) press to deactivate buzzer.

Functions Used:
RTC_Init() – Initialize RTC

RTCSetTime(h,m,s) – Set time

RTCSetDate(d,m,y) – Set date

RTCSetDay(day) – Set weekday

RTCGetTime() / RTCGetDate() / RTCGetDay() – Fetch current time info

DisplayRTCTime() / DisplayRTCDate() / DisplayRTCDay() – Display functions

RTC_edit() – Edit RTC time via keypad

medicine_edit() – Set alarm time via keypad

delay_s(seconds) – Delay function

keyscan() – Read keypad input

Usage Instructions:
Power on the system.

The current time/date/day is displayed on the LCD.

Press the Menu Button (sw1) to enter menu:

Press 1 for RTC edit.

Press 2 to set medicine reminder.

Press 3 to exit.

At the set medicine time, the buzzer sounds.

Press Stop Button (sw2) to stop the buzzer.
