/******************************************************************************************
 * FileName     : 05._Bluetooth_led_control
 * Description  : 블루투스 통신으로 LED 제어해 보기
 * Author       : 이인정
 * Created Date : 2021.06.03
 * Reference    : 
 * Modified     : 2021.06.03 : LIJ : 헤더 수정
 * Modified     : 2021.06.03 : WDW : 필요없는 코드 삭제, 출력문구 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
 * Modified     : 2024.07.30 : L H : 주석 수정
******************************************************************************************/


#include "BluetoothSerial.h"                          // 블루투스 통신 관련 라이브러리

int led_red = D2;                                     // 빨강 LED 핀 지정
int led_blue = D3;                                    // 파랑 LED 핀 지정
int led_green = D4;                                   // 초록 LED 핀 지정
int led_yellow = D5;                                  // 노랑 LED 핀 지정

BluetoothSerial SerialBT("");                         // 블루투스 통신 설정


// 수신 받은 데이터를 처리
void handle_data(const String& msg) {
  // 수신받은 데이터를 시리얼모니터에 출력
  Serial.println("받은 문자열: " + msg);                  

  if (msg == "RBON") {                                // 수신받은 데이터가 "RBON"이라면
    Serial.println("빨강 LED 켜기");                  // 빨강 LED 켜기 
    digitalWrite(led_red, HIGH);
  } else if (msg == "RBOFF") {                        // 수신받은 데이터가 "RBOFF"이라면
    Serial.println("빨강 LED 끄기");                  // 빨강 LED 끄기 
    digitalWrite(led_red, LOW);
  } else if (msg == "BBON") {                         // 수신받은 데이터가 "BBON"이라면
    Serial.println("파랑 LED 켜기");                  // 파랑 LED 켜기 
    digitalWrite(led_blue, HIGH);
  } else if (msg == "BBOFF") {                        // 수신받은 데이터가 "BBOFF"이라면
    Serial.println("파랑 LED 끄기");                  // 파랑 LED 끄기 
    digitalWrite(led_blue, LOW);
  } else if (msg == "GBON") {                         // 수신받은 데이터가 "GBON"이라면
    Serial.println("초록 LED 켜기");                  // 초록 LED 켜기 
    digitalWrite(led_green, HIGH);
  } else if (msg == "GBOFF") {                        // 수신받은 데이터가 "GBOFF"이라면
    Serial.println("초록 LED 끄기");                  // 초록 LED 끄기 
    digitalWrite(led_green, LOW);
  } else if (msg == "YBON") {                         // 수신받은 데이터가 "YBON"이라면
    Serial.println("노랑 LED 켜기");                  // 노랑 LED 켜기 
    digitalWrite(led_yellow, HIGH);
  } else if (msg == "YBOFF") {                        // 수신받은 데이터가 "YBOFF"이라면
    Serial.println("노랑 LED 끄기");                  // 노랑 LED 끄기 
    digitalWrite(led_yellow, LOW);           
  }
}


void setup() {
  pinMode(led_red, OUTPUT);                           // 빨강 LED 출력 모드로 설정
  pinMode(led_blue, OUTPUT);                          // 파랑 LED 출력 모드로 설정
  pinMode(led_green, OUTPUT);                         // 초록 LED 출력 모드로 설정
  pinMode(led_yellow, OUTPUT);                        // 노랑 LED 출력 모드로 설정

  Serial.begin(115200);                               // 통신속도 설정
  SerialBT.begin();                                   // 블루투스 통신 시작
  // 블루투스 이름 출력
  Serial.println("블루투스 이름 : " + SerialBT._ble_name);
  // 수신받은 데이터를 처리하기 위한 함수 연결
  SerialBT.on_received(handle_data);
}


void loop() {
  if (!SerialBT.isConnected()) {                      // 블루투스가 연결되지 않았다면
    Serial.println("연결되지 않았습니다.");           // "연결되지 않았습니다." 출력
    delay(1000);
    return;
  }
}


//=========================================================================================
//
// (주)한국공학기술연구원 http://et.ketri.re.kr
//
//=========================================================================================
