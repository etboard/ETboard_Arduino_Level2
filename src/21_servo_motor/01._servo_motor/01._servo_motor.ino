/******************************************************************************************
 * FileName     : 01._servo_motor
 * Description  : 서보모터를 지정된 각도 만큼 회전 해보기(0~180도)
 * Author       : 이인정
 * Created Date : 2021.06.04
 * Reference    : 
 * Modified     : 2021.06.04 : LIJ : 헤더 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
  * Modified     : 2023.9.19 : PEJ : 서보모터 핀 변경
******************************************************************************************/

#include <Servo.h>

static const int servoPin = D6;                        // 서보모터
int posDegrees = 0;

Servo servo;                                           // 서보모터 선언


void setup() {
  Serial.begin(115200);                                // 통신속도
  servo.attach(servoPin);                              // 서보모터 핀 설정
}


void loop() {    
  for(posDegrees=0 ; posDegrees<180 ; posDegrees++){   // 서보모터의 각도 180도 까지 증가
    servo.write(posDegrees);
    delay(10);                                         // 0.01초 대기
  }
  
  for(posDegrees=180;posDegrees > 0; posDegrees--){    // 서보모터의 각도 0도 까지 감소
    servo.write(posDegrees);
    delay(10);                                         // 0.01초 대기
  }
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
