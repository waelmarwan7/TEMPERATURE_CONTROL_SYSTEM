#ifndef LCD_H_
#define LCD_H_

/*DEFINES DATA PORT FOR LCD */
#define LCD_DATA_PORT  DIO_PORTC

/*DEFINES CTRL PORT FOR LCD */
#define LCD_CTRL_PORT  DIO_PORTA


/*DEFINEES CTRL PINS FOR LCD*/
#define LCD_RS_PIN      DIO_PIN1
#define LCD_RW_PIN      DIO_PIN2
#define LCD_E_PIN       DIO_PIN3

/*DEFINES THE COMMAND BITS*/
#define CLEAR         0B00000001
#define FUNCTION_SET  0B00111000
#define DISPLAY_SET   0B00001100
#define RETURN_HOME   0B00000010
#define CURSOR_SHIFT  0B00000100
#define second_row    0xC0          // set cursor position in second row
#define CURSOR_OFF    0x0C                    // Cursor off
#define CURSOR_ON     0x0E                    // Cursor on

//DEFINES FUNCTIONS OF LCD...
void LCD_voidSendData(const char* Copy_pcString);
void LCD_VoidSendCommand(u8 U8CommandCopy);
void LCD_Voidinit(void);
void LCD_VoidSendChar(u8 U8DataCopy);






//////LCD init 8bit mode//////
//N =1 -> 2 lines , N =0 -> 1 line
//font F =0 -> 5x8, F=1 -> 5x11
//no need for delay as we put additional delay in command
//D: display
//C: cursor
//B: blink

#endif /* LCD_H_ */
