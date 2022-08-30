/******************************************************************************************
 * FileName     : ultrasonic_servo_motor
 * Description  : 초음파센서의 거리에 따라 서버모터를 제어 해보기
 * Author       : 이인정
 * Created Date : 2021.06.17
 * Reference    : 
 * Modified     : 2021.06.17 : LIJ : 헤더 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
******************************************************************************************/

#include <Servo.h>
int TRIG = D9;                          // TRIG 핀 설정 (초음파 보내는 핀)
int ECHO = D8;                          // ECHO 핀 설정 (초음파 받는 핀)
static const int servoPin = D2;         // 서보모터 핀 설정

Servo servo;                            // 서보모터 선언


void setup() {
  Serial.begin(115200);                 // 통신속도
  servo.attach(servoPin);               // 서보모터 핀 설정  
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
  
  duration = pulseIn (ECHO, HIGH);    // 물체에 반사되어돌아온 초음파의 시간을 저장
  
  distance = duration * 17 / 1000;    // 물체와의 거리 계산식
  
  if(distance < 20)                   // 물체와 거리가 20cm 미만이면 서보모터를 180도로 설정
  {
    servo.write(180);
  }

  if(distance >=20){                  // 물체와 거리가 20cm 이상이면 서보모터를 0도로 설정
    servo.write(0);
  }
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
