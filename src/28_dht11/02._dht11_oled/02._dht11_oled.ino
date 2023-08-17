/******************************************************************************************
 * FileName     : 02._dht11_oled
 * Description  : 온습도 센서의 값을 시리얼 모니터에 출력해 보기
 * Author       : 박은정
 * Created Date : 2023.08.17
 * Reference    : 
 * Modified     : 
 ******************************************************************************************/
 
#include "dht11.h"
#include"oled_u8g2.h"
#define DHT11PIN D2

dht11 DHT11;
OLED_U8G2 oled;

void setup() {
  oled.setup();
  Serial.begin(115200);
}

void loop() {  
  DHT11.read(DHT11PIN);                                         // 온습도 센서(DTH11) 값 측정

  Serial.print(DHT11.temperature);                              // 온도 값 출력
  Serial.print("℃ ");
  Serial.print(DHT11.humidity);                                 // 습도 값 출력
  Serial.println("%");

  oled.setLine(1, "DHT11 sensor");                              // OLED 모듈 1번째 줄에 저장
  oled.setLine(2, "temp: " + String(DHT11.temperature) + "c");  // OLED 모듈 2번째 줄에 온도 값 저장
  oled.setLine(3, "humi: " + String(DHT11.humidity) + "%");     // OLED 모듈 3번째 줄에 습도 값 저장
  oled.display();                                               // OLED 모듈 출력

  delay(1000);                                                  // 1초 대기
}

//=========================================================================================
//
// (주)한국공학기술연구원 http://et.ketri.re.kr
//
//=========================================================================================
