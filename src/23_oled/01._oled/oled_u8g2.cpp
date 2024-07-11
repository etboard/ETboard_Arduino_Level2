/********************************************************************************** 
 * Author : SCS
 * Date : 2018.09.30  
 * Description : SSD1306 OLED Display  
 * Reference: FontUsage.ino in u8g2 examples 
 * Modified     : 2022.10.03 : SCS : support arduino uno with ET-Upboard
 * Modified     : 2023.10.11 : SCS : decrease memory for arduino
 * Modified     : 2024.07.11 : SCS : add 5 line, 8 line
 **********************************************************************************/

#include "oled_u8g2.h"

#include <Arduino.h>

#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

// 2018.09.05 : SCS
// U8g2 Contructor (Frame Buffer)
#if defined(ARDUINO_AVR_UNO)    
  // Slow  
  U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ A0, /* data=*/ A1, /* reset=*/ U8X8_PIN_NONE);   // OLEDs without Reset of the Display
  // Fast & No Flickering
  //U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);         
#elif defined(ESP32)   
  // Fast
  U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
#else
  #error "Unknown board"
#endif
// End of constructor

//=================================================================================
OLED_U8G2::OLED_U8G2() 
//=================================================================================  
{
  lineString[0] = "";
  lineString[1] = "";
  lineString[2] = "";
  lineString[3] = "";
  lineString[4] = "";
  lineString[5] = "";
  lineString[6] = "";   
}

#if defined(ARDUINO_AVR_UNO)    
//=================================================================================
void OLED_U8G2::setup(void) 
//=================================================================================
{
  u8x8.begin();  
  u8x8.setFont(u8x8_font_8x13B_1x2_r);
  //u8x8.setBusClock(4000000);
}

//=================================================================================
void OLED_U8G2::clearDisplay() 
//=================================================================================
{ 
  // Clear 
  u8x8.clearDisplay();   
}  
  
//=================================================================================
void OLED_U8G2::display() 
//=================================================================================
{ 
  // First line  
  u8x8.drawString(0, 0, lineString[0]);

  //Second line
  u8x8.drawString(0, 2, lineString[1]);

  // Third line
  u8x8.drawString(0, 4, lineString[2]);
  
  // Display
  u8x8.refreshDisplay(); 
}

#elif defined(ESP32)   
//=================================================================================
void OLED_U8G2::setup(void) 
//=================================================================================
{
  u8g2.begin();
  u8g2.clearBuffer();          // clear the internal memory
}
//=================================================================================
void OLED_U8G2::display(int display_line) 
//=================================================================================
{ 
  // Clear 
  u8g2.clearBuffer();          // clear the internal memory

  if (display_line <= 3) {
    // First line
    u8g2.setFont(u8g2_font_9x15B_tf); 
    
    u8g2.setCursor(0,10);
    u8g2.print(lineString[0]);

    // Second line
    u8g2.setFont(u8g2_font_logisoso18_tf ); 
    u8g2.setCursor(0,35);
    u8g2.print(lineString[1]);  

    // Third line
    u8g2.setCursor(0,60);
    u8g2.print(lineString[2]);
  }
  
  else if (display_line <= 5) {
    // First line
    u8g2.setFont(u8g2_font_9x15B_tf);     
    u8g2.setCursor(0,10);
    u8g2.print(lineString[0]);
    
    u8g2.setFont( u8g2_font_crox1cb_mr );
    for(int r=1; r<display_line; r++) {
      u8g2.setCursor(0, r*12+13);
      u8g2.print(lineString[r]);
    } 
  }    
 
  else if (display_line <= 8) {
    u8g2.setFont( u8g2_font_pcsenior_8r );   // 글자가 작아서 넓은 간격으로해야 가독성
    for(int r=0; r<display_line; r++) {
      u8g2.setCursor(0, r*8+6);
      u8g2.print(lineString[r]);
    } 
  }  
  
  // Display
  u8g2.sendBuffer();          // transfer internal memory to the display
}
#else
  #error "Unknown board"
#endif

//=================================================================================
void OLED_U8G2::setLine(int line, char* buffer)
//=================================================================================
{  
  if (line < 1 || line > MAX_LINES) return;
  lineString[line - 1] = buffer;  
}

 
//=================================================================================
// End of Line
//=================================================================================
