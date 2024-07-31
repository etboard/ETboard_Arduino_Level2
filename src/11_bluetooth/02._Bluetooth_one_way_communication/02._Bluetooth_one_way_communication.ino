/******************************************************************************************
 * FileName     : 02._Bluetooth_one_way_communication
 * Description  : PC에서 데이터를 입력받아 블루투스를 통해 메시지 전송해 보기
 * Author       : 이인정
 * Created Date : 2021.06.03
 * Reference    : 
 * Modified     : 2021.06.03 : LIJ : 헤더 수정
 * Modified     : 2021.06.03 : WDW : 필요없는 코드 삭제, 출력문구 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
 * Modified     : 2024.07.30 : L H : 주석 수정
 ******************************************************************************************/

 
#include "BluetoothSerial.h"                                // 블루투스 통신 관련 라이브러리


BluetoothSerial SerialBT("");                               // 블루투스 통신 설정


void setup() {
  Serial.begin(115200);                                     // 통신속도 설정
  SerialBT.begin();                                         // 블루투스 통신 시작
  Serial.println("블루투스 이름 : " + SerialBT._ble_name);  // 블루투스 이름 출력
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
