/******************************************************************************************
 * FileName     : 01._oled_print
 * Description  : OLED 모듈에 "HelloWorld" 출력 해보기
 * Author       : 이인정
 * Created Date : 2021.06.08
 * Reference    : 
 * Modified     : 2021.06.08 : LIJ : 헤더 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
 * Modified     : 2024.07.11 : SCS : add 5 line, 8 line
 * Modified     : 2024.07.19 : SCS : add setLine(int line, String buffer)
******************************************************************************************/

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
