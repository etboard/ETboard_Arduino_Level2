/******************************************************************************************
 * FileName     : ultrasonic_buzzer
 * Description  : 초음파센서에 가까워 지면 부저 소리로 알려주기
 * Author       : 이인정
 * Created Date : 2021.06.18
 * Reference    : 
 * Modified     : 2021.06.18 : LIJ : 헤더 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
 * Modified     : 2023.09.25 : PEJ : 소스 코드 오류 수정
******************************************************************************************/

int TRIG = D9;                          // TRIG 핀 설정 (초음파 보내는 핀)
int ECHO = D8;                          // ECHO 핀 설정 (초음파 받는 핀)

int buzzer = D6 ;                       // 부저


void setup() {
  Serial.begin(115200);                 // 통신 속도
  pinMode(TRIG, OUTPUT);                // 핀 모드 설정
  pinMode(ECHO, INPUT);                 // 핀 모드 설정
  pinMode (buzzer, OUTPUT) ;            // 핀 모드 설정
}


void loop() {
  long duration, distance;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  duration = pulseIn (ECHO, HIGH);     // 물체에 반사되어 돌아온 초음파의 시간을 저장
  
  distance = duration * 17 / 1000;     // 측정된 값을 Cm로 변환하기 위해 공식을 대입
  
  Serial.print(distance);              // 측정된 물체로부터 거리를 시리얼 모니터로 출력
  Serial.println(" Cm");

  delay(100);                          // 0.1초 대기
  
  if(distance < 15) {
    for (i = 0; i < 80; i++) {         // 부저에 소리 내기
      digitalWrite(buzzer, HIGH);
      delay(1);
      digitalWrite(buzzer, LOW);
      delay(1);
    }
  }
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
