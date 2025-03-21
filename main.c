//#define _XTAL_FREQ 4000000
//#define RS RC0
//#define EN RC2
//#define D4 RD4
//#define D5 RD5
//#define D6 RD6
//#define D7 RD7
//
//#include <xc.h>
//
//#pragma config FOSC = HS
//#pragma config WDTE = OFF
//#pragma config PWRTE = ON
//#pragma config BOREN = ON
//#pragma config LVP = OFF
//#pragma config CPD = OFF
//#pragma config WRT = OFF
//#pragma config CP = OFF
//
//unsigned char current_hour = 00, current_minute = 0, current_second = 0;
//unsigned char alarm_hour = 00, alarm_minute = 0, alarm_second = 5;
//unsigned char led_state = 0;
//unsigned char alarm_active = 0;
//unsigned char blink_flag = 1;
//unsigned char editing_field = 6;
//unsigned char is_editing = 0;
//unsigned int rb2_press_duration = 0;
//int count = 0;
//
//void updateRealTime();
//void checkAlarm();
//void handleButtonPress();
//void getFormattedTime(char *buffer, unsigned char hour, unsigned char minute, unsigned char second);
//void toggleLED();
//void moveCursorToEdit();
//void Lcd_SetBit(char data_bit);
//void Lcd_Cmd(char a);
//void Lcd_Clear();
//void Lcd_Set_Cursor(char a, char b);
//void Lcd_Start();
//void Lcd_Print_Char(char data);
//void Lcd_Print_String(char *a);
//
//void __interrupt() timer_isr() {
//    if (TMR0IF == 1) {
//        if (is_editing){
//            count = 0;
//        } else {
//            count++;
//            TMR0 = 100;
//            if (count >= 100) {
//                count = 0;
//                updateRealTime();
//                checkAlarm();
//            }
//        }
//        TMR0IF = 0;
//    }
//}
//
//
//void Lcd_SetBit(char data_bit) {
//    D4 = (data_bit & 1) ? 1 : 0;
//    D5 = (data_bit & 2) ? 1 : 0;
//    D6 = (data_bit & 4) ? 1 : 0;
//    D7 = (data_bit & 8) ? 1 : 0;
//}
//
//void Lcd_Cmd(char a) {
//    RS = 0;
//    Lcd_SetBit(a);
//    EN = 1;
//    EN = 0;
//}
//
//void Lcd_Clear() {
//    Lcd_Cmd(0);
//    Lcd_Cmd(1);
//}
//
//void Lcd_Set_Cursor(char a, char b) {
//    char temp;
//    if (a == 1) temp = 0x80 + b - 1;
//    else if (a == 2) temp = 0xC0 + b - 1;
//    Lcd_Cmd(temp >> 4);
//    Lcd_Cmd(temp & 0x0F);
//}
//
//void Lcd_Start() {
//    Lcd_SetBit(0x00);
//    for (int i = 0; i < 3; i++) {
//        Lcd_Cmd(0x03);
//    }
//    Lcd_Cmd(0x02);
//    Lcd_Cmd(0x02);
//    Lcd_Cmd(0x08);
//    Lcd_Cmd(0x00);
//    Lcd_Cmd(0x0C);
//    Lcd_Cmd(0x00);
//    Lcd_Cmd(0x06);
//}
//
//void Lcd_Print_Char(char data) {
//    RS = 1;
//    Lcd_SetBit(data >> 4);
//    EN = 1;
//    EN = 0;
//    Lcd_SetBit(data & 0x0F);
//    EN = 1;
//    EN = 0;
//}
//
//void Lcd_Print_String(char *a) {
//    for (int i = 0; a[i] != '\0'; i++) {
//        Lcd_Print_Char(a[i]);
//    }
//}
//
//void updateRealTime() {
//    current_second++;
//    if (current_second == 60) {
//        current_second = 0;
//        current_minute++;
//        if (current_minute == 60) {
//            current_minute = 0;
//            current_hour++;
//            if (current_hour == 24) current_hour = 0;
//        }
//    }
//}
//
//void checkAlarm() {
//    if (alarm_active && current_hour == alarm_hour &&
//        current_minute == alarm_minute && current_second == alarm_second) {
//        toggleLED();
//    }
//}
//
//void toggleLED() {
//    led_state = !led_state;
//    RD0 = led_state;
//}
//
//void handleButtonPress() {
//    moveCursorToEdit();
//    if (!RB0 && !RB1) {
//        RD0 = 0;
//    }
//    if (!RB0) {
//        if (editing_field == 0) current_hour = (current_hour + 1) % 24;
//        else if (editing_field == 1) current_minute = (current_minute + 1) % 60;
//        else if (editing_field == 2) current_second = (current_second + 1) % 60;
//        else if (editing_field == 3) alarm_hour = (alarm_hour + 1) % 24;
//        else if (editing_field == 4) alarm_minute = (alarm_minute + 1) % 60;
//        else if (editing_field == 5) alarm_second = (alarm_second + 1) % 60;
//    }
//    if (!RB1) {
//        if (editing_field == 0) current_hour = (current_hour == 0) ? 23 : current_hour - 1;
//        else if (editing_field == 1) current_minute = (current_minute == 0) ? 59 : current_minute - 1;
//        else if (editing_field == 2) current_second = (current_second == 0) ? 59 : current_second - 1;
//        else if (editing_field == 3) alarm_hour = (alarm_hour == 0) ? 23 : alarm_hour - 1;
//        else if (editing_field == 4) alarm_minute = (alarm_minute == 0) ? 59 : alarm_minute - 1;
//        else if (editing_field == 5) alarm_second = (alarm_second == 0) ? 59 : alarm_second - 1;
//        
//    }
//    if (!RB2) {
//        alarm_active = !alarm_active;
//    }
//    if (!RB3) {
//        editing_field = (editing_field + 1) % 7;
//        if (editing_field < 3) {
//            is_editing = 1;
//        } else is_editing = 0;
//    }
//}
//
//void moveCursorToEdit() {
//    int current_value;
//    switch (editing_field) {
//        case 0:
//            Lcd_Set_Cursor(1, 7);
//            current_value = current_hour;
//            break;
//        case 1:
//            Lcd_Set_Cursor(1, 10);
//            current_value = current_minute;
//            break;
//        case 2:
//            Lcd_Set_Cursor(1, 13);
//            current_value = current_second;
//            break;
//        case 3:
//            Lcd_Set_Cursor(2, 8);
//            current_value = alarm_hour;
//            break;
//        case 4:
//            Lcd_Set_Cursor(2, 11);
//            current_value = alarm_minute;
//            break;
//        case 5:
//            Lcd_Set_Cursor(2, 14);
//            current_value = alarm_second;
//            break;
//        case 6:
//            Lcd_Set_Cursor(2, 18);
//            current_value = alarm_second;
//            break;
//        default:
//            return;
//    }
//    if (blink_flag) {
//        Lcd_Print_String("__");
//    } else {
//        Lcd_Print_Char((current_value / 10) + '0');
//        Lcd_Print_Char((current_value % 10) + '0');
//    }
//    blink_flag = !blink_flag;
//    __delay_ms(200);
//}
//
//void getFormattedTime(char *buffer, unsigned char hour, unsigned char minute, unsigned char second) {
//    buffer[0] = (hour / 10) + '0';
//    buffer[1] = (hour % 10) + '0';
//    buffer[2] = ':';
//    buffer[3] = (minute / 10) + '0';
//    buffer[4] = (minute % 10) + '0';
//    buffer[5] = ':';
//    buffer[6] = (second / 10) + '0';
//    buffer[7] = (second % 10) + '0';
//    buffer[8] = '\0';
//}
//
//void main() {
//    char time_buffer[9];
//    char alarm_buffer[9];
//    TRISC = 0x00;
//    TRISD = 0x00;
//    TRISB = 0xFF;
//    OPTION_REGbits.nRBPU = 0;
//    RD0 = 0;
//
//    OPTION_REG = 0b00000101;
//    TMR0 = 100;
//    TMR0IE = 1;
//    GIE = 1;
//    PEIE = 1;
//
//    Lcd_Start();
//    Lcd_Clear();
//
//    while (1) {
//        handleButtonPress();
//        getFormattedTime(time_buffer, current_hour, current_minute, current_second);
//        getFormattedTime(alarm_buffer, alarm_hour, alarm_minute, alarm_second);
//
//        Lcd_Set_Cursor(1, 1);
//        Lcd_Print_String("Time: ");
//        Lcd_Print_String(time_buffer);
//        
//        if (alarm_active){
//            Lcd_Print_String(" H");
//        } else {
//            Lcd_Print_String("  ");
//        }
//
//        Lcd_Set_Cursor(2, 1);
//        Lcd_Print_String("Alarm: ");
//        Lcd_Print_String(alarm_buffer);
//    }
//}

#define _XTAL_FREQ 4000000
#define RS RC0
#define EN RC2
#define D4 RD4
#define D5 RD5
#define D6 RD6
#define D7 RD7

#include <xc.h>

#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = ON
#pragma config BOREN = ON
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = OFF
#pragma config CP = OFF

unsigned char mode = 0;           // 0 = Mode A, 1 = Mode B
unsigned char seconds = 0, minutes = 0;
unsigned char alarm_triggered = 0;
unsigned int count = 0;

void updateClock();
void checkAlarm();
void handleButtonPress();
void displayTime();
void Lcd_SetBit(char data_bit);
void Lcd_Cmd(char a);
void Lcd_Clear();
void Lcd_Set_Cursor(char a, char b);
void Lcd_Start();
void Lcd_Print_Char(char data);
void Lcd_Print_String(char *a);

void __interrupt() timer_isr() {
    if (TMR0IF == 1) {
        count++;
        TMR0 = 100;
        if (count >= 100) {  // 1 second delay
            count = 0;
            updateClock();
            checkAlarm();
            displayTime();
        }
        TMR0IF = 0;
    }
}

void updateClock() {
    if (mode == 0) {  // Mode A: Countdown
        if (minutes == 0 && seconds == 0) {
            alarm_triggered = 1;
        } else {
            if (seconds == 0) {
                seconds = 59;
                minutes--;
            } else {
                seconds--;
            }
        }
    } else if (mode == 1) {  // Mode B: Count-up
        if (minutes == 1 && seconds == 30) {
            alarm_triggered = 1;
        } else {
            seconds++;
            if (seconds == 60) {
                seconds = 0;
                minutes++;
            }
        }
    }
}

void checkAlarm() {
    if (alarm_triggered) {
        RD0 = 1;  // Turn on LED as alarm indicator
    }
}

void handleButtonPress() {
    if (!RB0) {  // Button for Mode A
        mode = 0;
        minutes = 3;
        seconds = 0;
        alarm_triggered = 0;
        RD0 = 0;  // Turn off alarm
        __delay_ms(300);  // Debounce delay
    }
    if (!RB1) {  // Button for Mode B
        mode = 1;
        minutes = 0;
        seconds = 0;
        alarm_triggered = 0;
        RD0 = 0;  // Turn off alarm
        __delay_ms(300);  // Debounce delay
    }
}

void displayTime() {
    char buffer[6];
    buffer[0] = (minutes / 10) + '0';
    buffer[1] = (minutes % 10) + '0';
    buffer[2] = ':';
    buffer[3] = (seconds / 10) + '0';
    buffer[4] = (seconds % 10) + '0';
    buffer[5] = '\0';
    
    Lcd_Set_Cursor(1, 1);
    Lcd_Print_String("Mode: ");
    if (mode == 0) {
        Lcd_Print_String("A ");
    } else {
        Lcd_Print_String("B ");
    }
    
    Lcd_Set_Cursor(2, 1);
    Lcd_Print_String("Time: ");
    Lcd_Print_String(buffer);
}

void Lcd_SetBit(char data_bit) {
    D4 = (data_bit & 1) ? 1 : 0;
    D5 = (data_bit & 2) ? 1 : 0;
    D6 = (data_bit & 4) ? 1 : 0;
    D7 = (data_bit & 8) ? 1 : 0;
}

void Lcd_Cmd(char a) {
    RS = 0;
    Lcd_SetBit(a);
    EN = 1;
    __delay_ms(4);
    EN = 0;
}

void Lcd_Clear() {
    Lcd_Cmd(0);
    Lcd_Cmd(1);
}

void Lcd_Set_Cursor(char a, char b) {
    char temp;
    if (a == 1) temp = 0x80 + b - 1;
    else if (a == 2) temp = 0xC0 + b - 1;
    Lcd_Cmd(temp >> 4);
    Lcd_Cmd(temp & 0x0F);
}

void Lcd_Start() {
    Lcd_SetBit(0x00);
    for (int i = 0; i < 3; i++) {
        Lcd_Cmd(0x03);
        __delay_ms(5);
    }
    Lcd_Cmd(0x02);
    Lcd_Cmd(0x02);
    Lcd_Cmd(0x08);
    Lcd_Cmd(0x00);
    Lcd_Cmd(0x0C);
    Lcd_Cmd(0x00);
    Lcd_Cmd(0x06);
}

void Lcd_Print_Char(char data) {
    RS = 1;
    Lcd_SetBit(data >> 4);
    EN = 1;
    __delay_ms(4);
    EN = 0;
    Lcd_SetBit(data & 0x0F);
    EN = 1;
    __delay_ms(4);
    EN = 0;
}

void Lcd_Print_String(char *a) {
    for (int i = 0; a[i] != '\0'; i++) {
        Lcd_Print_Char(a[i]);
    }
}

void main() {
    TRISC = 0x00;
    TRISD = 0x00;
    TRISB = 0xFF;
    OPTION_REGbits.nRBPU = 0;
    RD0 = 0;

    OPTION_REG = 0b00000101;
    TMR0 = 100;
    TMR0IE = 1;
    GIE = 1;
    PEIE = 1;

    Lcd_Start();
    Lcd_Clear();

    while (1) {
        handleButtonPress();
    }
}
