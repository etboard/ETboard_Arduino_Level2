/******************************************************************************************
 * FileName     : 03._Bluetooth_two_way_communication
 * Description  : PC와 블루투스로 연결된 기기간 블루투스 통신해 보기
 * Author       : 이인정
 * Created Date : 2021.06.03
 * Reference    : 
 * Modified     : 2021.06.03 : LIJ : 헤더 수정
 * Modified     : 2021.06.03 : WDW : 필요없는 코드 삭제, 출력문구 수정
 * Modified     : 2024.07.30 : L H : 주석 수정
 *******************************************************************************************/


#include "BluetoothSerial.h"                                // 블루투스 통신 관련 라이브러리


BluetoothSerial SerialBT("");                               // 블루투스 통신 설정


void handle_data(const String& msg) {
  Serial.println("받은 문자열: " + msg);                    // 수신받은 데이터를 출력
}


void setup() {
  Serial.begin(115200);                                     // 통신속도 설정
  SerialBT.begin();                                         // 블루투스 통신 시작
  Serial.println("블루투스 이름 : " + SerialBT._ble_name);  // 블루투스 이름 출력

  // 수신받은 데이터를 처리하기 위한 함수 연결
  SerialBT.on_received(handle_data);                       
}


void loop() {
  if (!SerialBT.isConnected()) {                            // 블루투스가 연결되지 않았다면
    Serial.println("연결되지 않았습니다.");                 // "연결되지 않았습니다." 출력
    delay(1000);
    return;
  }

  if (Serial.available()) {                                 // 메시지가 입력되었다면
    String data = Serial.readString();                      // 입력된 메시지를 저장
    SerialBT.send(data);                                    // 메시지를 전송
  }
}


//=========================================================================================
//
// (주)한국공학기술연구원 http://et.ketri.re.kr
//
//=========================================================================================
