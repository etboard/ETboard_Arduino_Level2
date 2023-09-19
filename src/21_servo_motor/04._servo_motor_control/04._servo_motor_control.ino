/******************************************************************************************
 * FileName     : 04._servo_motor_control
 * Description  : 파랑, 초록 버튼을 눌러 서보모터를 제어 해보기
 * Author       : 이인정
 * Created Date : 2021.06.04
 * Reference    : 
 * Modified     : 2021.06.04 : LIJ : 헤더 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
 * Modified     : 2023.9.19 : PEJ : 서보모터, 버튼 핀 변경
******************************************************************************************/

#include <Servo.h>

static const int servoPin = D6;        // 서보모터
int posDegrees  = 0;                   // 서보모터 설정각도 값
int up = D7;                           // 파랑 버튼
int down = D8;                         // 초록 버튼

Servo servo;                           // 서보모터 선언


void setup() {
  Serial.begin(115200);                // 통신속도
  servo.attach(servoPin);              // 서보모터 핀 설정
  pinMode(up, INPUT);                  // 핀 모드 설정
  pinMode(down, INPUT);                // 핀 모드 설정
}


void loop() {
  int up_value = digitalRead(up);      // 파랑 버튼의 값을 저장
  int down_value = digitalRead(down);  // 초록 버튼의 값을 저장
  
  if(up_value == LOW) {                 // 파랑 버튼이 눌리면 서보모터의 각도 1도씩 증가
    posDegrees += 1;
    servo.write(posDegrees);
  }
  
  if(posDegrees > 180) {                // 서보모터의 설정각도가 180도 이상이 되지 않게 설정
    posDegrees = 180;
  }
  
  if(down_value == LOW) {               // 초록 버튼이 눌리면 서보모터의 각도 1도씩 감소
    posDegrees -= 1;
    servo.write(posDegrees);
  }
  
  if(posDegrees < 0) {                  // 서보모터의 설정각도가 0도 이하가 되지 않게 설정
    posDegrees = 0;
  }
  delay(10);
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
