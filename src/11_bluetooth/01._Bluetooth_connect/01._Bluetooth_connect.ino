/******************************************************************************************
 * FileName     : 01._Bluetooth_connect
 * Description  : 블루투스 연결 해 보기(시리얼 모니터 출력)
 * Author       : 이인정
 * Created Date : 2021.06.03
 * Reference    : 
 * Modified     : 2021.06.03 : LIJ : 헤더 수정
 * Modified     : 2021.06.03 : WDW : 필요없는 코드 삭제, 출력문구 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
 ******************************************************************************************/
 
// 블루투스 연결을 위해서는 안드로이드 기기가 필수입니다.(iOS 불가능)

#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

char names[] = "your_name";                         // 블루투스의 이름을 적어주세요

void setup() {
  Serial.begin(115200);                             // 통신속도 설정
  SerialBT.begin(names);                            // 자신의 이름으로 된 블루투스 생성
  
  while(!SerialBT.connected(1000)) {
    Serial.println("연결되지 않았습니다.");
  }
  delay(1000);                                      // 제대로 연결이 되어야하니 잠시 대기

  String message = names + String(" : 연결에 성공했습니다!");
  Serial.println(message);                          // 시리얼에 연결에 성공했다고 출력
  SerialBT.println(message.c_str());                // 연결된 블루투스에 성공했다고 전송
}

void loop() {
  
}

//=========================================================================================
//
// (주)한국공학기술연구원 http://et.ketri.re.kr
//
//=========================================================================================
