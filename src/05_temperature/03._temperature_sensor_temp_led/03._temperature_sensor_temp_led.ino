/******************************************************************************************
 * FileName     : 03._temperature_sensor_temp_led
 * Description  : 온도 센서 값을 이용해 LED 켜보기
 * Author       : 이인정
 * Created Date : 2021.06.08
 * Reference    : 
 * Modified     : 2021.06.08 : LIJ : 헤더 수정
 * Modified     : 2021.12.14 : LEH : 온도 비교 로직 수정
 * Modified     : 2021.12.14 : LEH : 소스 크린징
 ******************************************************************************************/
 
int sensor     = A2;                                     // 온도 센서
int led_red    = D2;                                     // 빨강 LED 
int led_blue   = D3;                                     // 파랑 LED
int led_green  = D4;                                     // 초록 LED
int led_yellow = D5;                                     // 노랑 LED
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;
// 현재 온도를 계산하기 위한 값들입니다. 굳이 알 필요없으니 넘어가도 됩니다. 


void setup() {
  Serial.begin(115200);                                  // 통신속도
  pinMode(led_red, OUTPUT);                              // 핀 모드 설정
  pinMode(led_blue, OUTPUT);                             // 핀 모드 설정
  pinMode(led_green, OUTPUT);                            // 핀 모드 설정
  pinMode(led_yellow, OUTPUT);                           // 핀 모드 설정
}


void loop() {
  Vo = analogRead(sensor);                               // 센서의 값을 읽고 온도로 변환
  R2 = R1 * (4095.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;  
  
  Serial.print(Tc);                                      // 변환한 온도값을 출력
  Serial.println(" C");

  if(Tc < 10){                                           // 온도가 10도 미만이면 파랑 LED 켜기
    digitalWrite(led_red, LOW);
    digitalWrite(led_blue, HIGH);
    digitalWrite(led_green, LOW);
    digitalWrite(led_yellow, LOW);
    Serial.println("파랑온");
  }
  
  if(Tc >=10 && Tc < 20){                                // 온도가 10도 이상 20도 미만이면 초록 LED 켜기
    digitalWrite(led_red, LOW);
    digitalWrite(led_blue, LOW);
    digitalWrite(led_green, HIGH);
    digitalWrite(led_yellow, LOW);
    Serial.println("초록온");
  }
  
  if(Tc >=20 && Tc < 30){                                // 온도가 20도 이상 30도 미만이면 노랑 LED 켜기
    digitalWrite(led_red, LOW);
    digitalWrite(led_blue, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_yellow, HIGH);
    Serial.println("노랑온");
  }
  
  if (Tc >= 30)                                          // 온도가 30도이상 이면 빨강 LED 켜기
  {
    digitalWrite(led_red, HIGH);
    digitalWrite(led_blue, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_yellow, LOW);
    Serial.println("빨강온");
  }  
  
  delay(200);                                            // 0.2초대기  
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
