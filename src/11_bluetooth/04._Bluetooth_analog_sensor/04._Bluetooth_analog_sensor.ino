/******************************************************************************************
 * FileName     : 04._Bluetooth_analog_sensor
 * Description  : 블루투스 통신으로 아날로그 센서 값 전송해 보기
 * Author       : 이인정
 * Created Date : 2021.06.03
 * Reference    : 
 * Modified     : 2021.06.03 : LIJ : 헤더 수정
 * Modified     : 2021.06.03 : WDW : 필요없는 코드 삭제, 출력문구 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
 * Modified     : 2024.07.30 : L H : 주석 수정
 ******************************************************************************************/
 

#include "BluetoothSerial.h"                               // 블루투스 통신 관련 라이브러리

int sensor1 = A0;                                          // 가변저항 핀 지정
int sensor2 = A1;                                          // 조도 센서 핀 지정
int sensor3 = A2;                                          // 온도 센서 핀 지정

BluetoothSerial SerialBT("");                              // 블루투스 통신 설정


void setup() {
  Serial.begin(115200);                                    // 통신속도 설정
  SerialBT.begin();                                        // 블루투스 통신 시작
  Serial.println("블루투스 이름 : " + SerialBT._ble_name); // 블루투스 이름 출력
}


void loop() {
  if (!SerialBT.isConnected()) {                           // 블루투스가 연결되지 않았다면
    Serial.println("연결되지 않았습니다.");                // "연결되지 않았습니다." 출력
    delay(1000);
    return;
  }

  String topic_msg = "T:/et/smpl/tele/sensor";
  Serial.println(topic_msg);    
  SerialBT.send(topic_msg);
  
  int sensor_result = analogRead(sensor1);                 // 가변저항 값 저장
  // 가변저항 값 메시지 저장
  String data_msg = "D:{\"VR\":" + String(sensor_result) + "}"; 
  Serial.println(data_msg);
  SerialBT.send(data_msg);                                 // 가변저항 값 메시지 전송

  topic_msg = "T:/et/smpl/tele/sensor";
  Serial.println(topic_msg);
  SerialBT.send(topic_msg);

  sensor_result = analogRead(sensor2);                     // 조도 센서 값 저장
  
  data_msg = "D:{\"CDS\":" + String(sensor_result) + "}";  // 조도 센서 값 메시지 저장 
  Serial.println(data_msg);
  SerialBT.send(data_msg);                                 // 조도 센서 값 메시지 전송
  
  topic_msg = "T:/et/smpl/tele/sensor";
  Serial.println(topic_msg);
  SerialBT.send(topic_msg);

  sensor_result = analogRead(sensor3);                     // 온도 센서 값 저장
  data_msg = "D:{\"TEMP\":" + String(sensor_result) + "}"; // 온도 센서 값 메시지 저장
  Serial.println(data_msg);
  SerialBT.send(data_msg);                                 // 온도 센서 값 메시지 전송

  delay(1000);
}


//=========================================================================================
//
// (주)한국공학기술연구원 http://et.ketri.re.kr
//
//=========================================================================================
