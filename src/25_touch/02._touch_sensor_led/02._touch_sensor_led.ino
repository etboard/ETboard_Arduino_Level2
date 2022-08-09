/******************************************************************************************
 * FileName     : 02._touch_sensor_led
 * Description  : 터치센서에 터치 해서 LED를 켜보기
 * Author       : 이인정
 * Created Date : 2021.06.17
 * Reference    : 
 * Modified     : 2021.06.17 : LIJ : 헤더 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
******************************************************************************************/

int touch_sensor = D6;                                  // 터치센서
int led_red    = D2;                                    // 빨강 LED
int led_blue   = D3;                                    // 파랑 LED
int led_green  = D4;                                    // 초록 LED
int led_yellow = D5;                                    // 노랑 LED


void setup() {
  Serial.begin(115200);                                 // 통신속도
  pinMode(touch_sensor, INPUT);                         // 핀 모드 설정
  pinMode(led_red, OUTPUT);                             // 핀 모드 설정
  pinMode(led_blue, OUTPUT);                            // 핀 모드 설정
  pinMode(led_green, OUTPUT);                           // 핀 모드 설정
  pinMode(led_yellow, OUTPUT);                          // 핀 모드 설정
}


void loop() {
  int touch_sensor_result = digitalRead(touch_sensor);  // 터치센서의 값을 저장
  
  digitalWrite(led_red, LOW);
  digitalWrite(led_blue, LOW);
  digitalWrite(led_green, LOW);
  digitalWrite(led_yellow, LOW);
  
  if(touch_sensor_result == 1)                          // 터치시 모든 LED 켜기
  {
    digitalWrite(led_red, HIGH);
    digitalWrite(led_blue, HIGH);
    digitalWrite(led_green, HIGH);
    digitalWrite(led_yellow, HIGH);
  }
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
