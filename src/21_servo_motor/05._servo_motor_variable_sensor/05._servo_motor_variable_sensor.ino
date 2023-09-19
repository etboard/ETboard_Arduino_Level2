/******************************************************************************************
 * FileName     : 05._servo_motor_variable_sensor
 * Description  : 가변저항으로 서보모터 제어 해보기
 * Author       : 이인정
 * Created Date : 2021.06.17
 * Reference    : 
 * Modified     : 2021.06.17 : LIJ : 헤더 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
 * Modified     : 2023.09.19 : PEJ : 서보모터 핀 수정
******************************************************************************************/

#include <Servo.h>

static const int servoPin = D6;                           // 서보모터
int posDegrees = 0;                                       // 서보모터 설정각도 값
int sensor = A0;                                          // 가변저항
Servo servo;                                              // 서보모터 선언


void setup() {
  Serial.begin(115200);                                   // 통신속도
  servo.attach(servoPin);                                 // 서보모터 핀 설정
}


void loop() {
  int posDegrees = map(analogRead(sensor),0,4095,0,255);  // 가변저항값 만큼 서보모터를 제어
  servo.write(posDegrees);
  
  delay(10);
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
