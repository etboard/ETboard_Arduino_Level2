/******************************************************************************************
 * FileName     : 03._oled_photoresistor_sensor_result
 * Description  : 조도센서의 값을 낮, 밤 OLED에 출력 해보기
 * Author       : 이인정
 * Created Date : 2021.06.17
 * Reference    : 
 * Modified     : 2021.06.17 : LIJ : 헤더 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
 * Modified     : 2024.07.31 : SCS : 주석 수정
******************************************************************************************/

#include "oled_u8g2.h"

int sensor = A1;                           // 조도센서
OLED_U8G2 oled;


void setup(){
  Serial.begin(115200);                    // 통신속도설정
  oled.setup();                            // OLED 통신핀 기능 설정
}


void loop(){
  int sensor_result = analogRead(sensor);  // 조도센서의 값 읽기
  
  if(sensor_result >= 700)                 // 조도센서의 값이 700d이상이면 
  {
    oled.setLine(2,"morning !");           // morning ! 출력
  }
  
  if(sensor_result < 700)                  // 조도센서의 값이 700미만이면
  {
    oled.setLine(2, "night !");            // night ! 출력
  }  
  
  oled.display();                          // OLED에 표시
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
