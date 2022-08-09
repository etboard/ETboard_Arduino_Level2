/******************************************************************************************
 * FileName     : ultrasonic_oled
 * Description  : 초음파센서와 거리를 측정하여 OLED에 출력 해보기
 * Author       : 이인정
 * Created Date : 2021.06.17
 * Reference    : 
 * Modified     : 2021.06.17 : LIJ : 헤더 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
******************************************************************************************/

#include"oled_u8g2.h"
int TRIG = D9;                          // TRIG 핀 설정 (초음파 보내는 핀)
int ECHO = D8;                          // ECHO 핀 설정 (초음파 받는 핀)
OLED_U8G2 oled;


void setup() {
  Serial.begin(115200);                 // 통신속도
  oled.setup();                         // OLED 통신핀 기능 설정
  pinMode(TRIG, OUTPUT);                // 핀 모드 설정
  pinMode(ECHO, INPUT);                 // 핀 모드 설정
}


void loop(){  
  long duration, distance;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  duration = pulseIn (ECHO, HIGH);      // 물체에 반사되어돌아온 초음파의 시간을 저장
  
  distance = duration * 17 / 1000;      // 물체와의 거리 계산

  oled.setLine(2," ");
  
  if(distance > 0)                      // 물체와의 거리가 20cm 이하이면 "danger !" 출력
  {
    oled.setLine(2,"danger !");
  }
  
  if(distance >= 20)                     // 물체와의 거리가 40cm 이하 20cm이상이면 "warning !" 출력
  {
    oled.setLine(2,"warning !");
  }
  
  if(distance >= 40)                     // 물체와 거리가 40cm 이상이면 "safe !" 출력
  {
    oled.setLine(2,"safe !");
  }
  Serial.println(distance);
  oled.display();
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
