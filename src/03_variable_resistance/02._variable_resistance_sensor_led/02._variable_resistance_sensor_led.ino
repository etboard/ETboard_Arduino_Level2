/******************************************************************************************
 * FileName     : 02._variable_resistance_sensor_led
 * Description  : 가변저항 값에 따라 LED 순차적으로 켜보기(빨강-파랑-노랑-초록)
 * Author       : 이인정
 * Created Date : 2021.05.28
 * Reference    : 
 * Modified     : 2021.06.02 : LIJ : 헤더 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
******************************************************************************************/

int sensor     = A0;                      // 가변저항 센서
int led_red    = D2;                      // 빨강 LED
int led_blue   = D3;                      // 파랑 LED
int led_green  = D4;                      // 초록 LED
int led_yellow = D5;                      // 노랑 LED


void setup() {
  pinMode(led_red,OUTPUT);                // 핀 모드 설정
  pinMode(led_blue,OUTPUT);               // 핀 모드 설정
  pinMode(led_green,OUTPUT);              // 핀 모드 설정
  pinMode(led_yellow,OUTPUT);             // 핀 모드 설정
  Serial.begin(115200);
}


void loop() {
  int sensor_result = analogRead(sensor); // 센서가 측정한 값 저장
  
  digitalWrite(led_red,LOW);
  digitalWrite(led_blue,LOW);
  digitalWrite(led_green,LOW);
  digitalWrite(led_yellow,LOW);
  Serial.println(sensor_result);          //센서가 측정한값 출력
  
  if(sensor_result>500){                  // 센서측정값이 500초과 빨강 LED 켜기
    digitalWrite(led_red,HIGH);
    }
    
  if(sensor_result>1000){                 // 센서측정값이 1000초과 파랑 LED 켜기
    digitalWrite(led_blue,HIGH);
    }

  if(sensor_result>1500){                 // 센서측정값이 1500초과 노랑 LED 켜기
    digitalWrite(led_yellow,HIGH);
    }

  if(sensor_result>2000){                 // 센서측정값이 2000초과 초록 LED 켜기
    digitalWrite(led_green,HIGH);
    }
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
