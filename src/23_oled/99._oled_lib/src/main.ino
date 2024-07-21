/******************************************************************************************
 * FileName     : main.cpp
 * Description  : OLED 모듈사용 샘플
 * Author       : 손철수
 * Created Date : 2024.07.21
 * Reference    : 
 * Modified     : 2022.10.03 : SCS : support arduino uno with ET-Upboard
 * Modified     : 2024.07.11 : SCS : add 5 line, 8 line
 * Modified     : 2024.07.19 : SCS : add setLine(int line, String buffer)
******************************************************************************************/
#include <Arduino.h>

#include "oled_u8g2.h"
OLED_U8G2 oled;


void setup(){
  oled.setup();                                   // OLED 통신핀 기능 설정
}


void loop(){  
  String str_type = "Mode : automatic";
  int int_type = 1234;
  float float_type = 56.789;

  oled.setLine(1, "* Aqua *");                    // char *, 문자 배열
  oled.setLine(2, str_type);                      // String, 문자열
  oled.setLine(3, int_type);                      // int, 정수
  oled.setLine(4, float_type, 2);                 // float, 실수, 소수점 2자리
  oled.setLine(5, "TDS  : 39ppm");
  oled.setLine(6, "Water: enough");
  oled.setLine(7, "Motor: Off");   
  oled.setLine(8, "Timer: 01:12:21");

  oled.display(3);                                // 3줄로 표시: 글꼴 큼
  delay(1000);

  oled.display(5);                                // 5줄로 표시: 글꼴 중간
  delay(1000);
  
  oled.display(8);                                // 8줄로 표시: 글꼴 작음
  delay(1000);  
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
