/******************************************************************************************
 * FileName     : ultrasonic_buzzer
 * Description  : 초음파센서에 가까워 지면 부저 소리로 알려주기
 * Author       : 이인정
 * Created Date : 2021.06.18
 * Reference    : 
 * Modified     : 2021.06.18 : LIJ : 헤더 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
******************************************************************************************/

#define TRIG D9                        // TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO D8                        // ECHO 핀 설정 (초음파 받는 핀)

int buzzer = D6 ;                      // 부저
int i;


void setup()
{
  Serial.begin(115200);                  // 통신속도설정
  pinMode(TRIG, OUTPUT);               // 핀 모드 설정
  pinMode(ECHO, INPUT);                // 핀 모드 설정
  pinMode (buzzer, OUTPUT) ;           // 핀 모드 설정
}


void loop()
{
  long duration, distance;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  
  duration = pulseIn (ECHO, HIGH);     // 초음파가 돌아온시간 저장
  distance = duration * 17 / 1000;     // 거리를 계산
      
  Serial.print(distance);              // 계산한 거리를 출력
  if(distance<15)
  {
    for (i=0;i<80;i++)                 // 부저에 소리내기
    {
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
