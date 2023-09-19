/******************************************************************************************
 * FileName     : 03._servo_motor_up_down
 * Description  : 파랑, 초록 버튼을 눌러 서보모터 움직여 보기
 * Author       : 이인정
 * Created Date : 2021.06.08
 * Reference    : 
 * Modified     : 2021.06.08 : LIJ : 헤더 수정 
 * Modified     : 2021.12.16 : LEH : 소스 크린징
 * Modified     : 2023.9.19 : PEJ : 서보모터, 버튼 핀 변경
******************************************************************************************/

#include <Servo.h>

static const int servoPin = D6;             // 서보모터
int up = D7;                                // 파랑 버튼         
int down = D8;                              // 초록 버튼

Servo servo;


void setup() {
  Serial.begin(115200);                     // 통신속도
  pinMode(up,INPUT);                        // 핀 모드 설정
  pinMode(down,INPUT);                      // 핀 모드 설정
  servo.attach(servoPin);
}


void loop() {
  int up_value = digitalRead(up);           // 파랑 버튼 상태확인
  int down_value = digitalRead(down);       // 초록 버튼 상태확인
  
  if(up_value == LOW){                      // 파랑 버튼이 눌리면 서보모터 180도까지 회전
    servo.write(180);
  }
  
  if(down_value == LOW){                    // 초록 버튼이 눌리면 서보모터 0도까지 회전
    servo.write(0);
  }
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
