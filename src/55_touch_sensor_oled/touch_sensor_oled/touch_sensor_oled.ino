/******************************************************************************************
 * FileName     : touch_sensor_oled
 * Description  : 터치센서에 터치시 OLED에 "touch" 출력
 * Author       : 이인정
 * Created Date : 2021.06.17
 * Reference    : 
 * Modified     : 2021.06.17 : LIJ : 헤더 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
******************************************************************************************/

#include"oled_u8g2.h"
OLED_U8G2 oled;
int touch_sensor = D6;                                  // 터치센서


void setup(){
  Serial.begin(115200);                                 // 통신속도
  oled.setup();                                         // OLED 통신핀 기능 설정
  pinMode(touch_sensor, INPUT);                         // 핀모드 설정
}


void loop(){
  int touch_sensor_result = digitalRead(touch_sensor);  // 터치센서의 값을 저장

  oled.setLine(2," ");
  if(touch_sensor_result == 1)
  {
    oled.setLine(2,"touch");
  }
  oled.display();
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
