/******************************************************************************************
 * FileName     : 06._Bluetooth_led_control
 * Description  : 블루투스를 이용하여 LED를 켰다 껐다 해 보기
 * Author       : 이인정
 * Created Date : 2021.06.02
 * Reference    : 
 * Modified     : 2021.06.02 : LIJ : 헤더 수정
 * Modified     : 2021.06.03 : WDW : 작동하지 않는 코드 수정
 * Modified     : 2021.06.11 : WDW : 반복되는 if -> else if 로 변경
 * Modified     : 2021.12.16 : LEH : 소스 크린징
******************************************************************************************/

// 블루투스 연결을 위해서는 안드로이드 기기가 필수입니다.(iOS 불가능)

// 시리얼 통신으로 제어
#include "BluetoothSerial.h"

#define led_red D2                      // 빨강 LED
#define led_blue D3                     // 파랑 LED
#define led_green D4                    // 초록 LED
#define led_yellow D5                   // 노랑 LED

BluetoothSerial SerialBT;

char names[] = "your_name";              // 자신의 이름을 적어주세요
void setup() {
  Serial.begin(115200);                  // 통신 속도
  
  pinMode(led_red, OUTPUT);              // 핀 모드 설정
  pinMode(led_blue, OUTPUT);             // 핀 모드 설정
  pinMode(led_green, OUTPUT);            // 핀 모드 설정
  pinMode(led_yellow, OUTPUT);           // 핀 모드 설정
  
  SerialBT.begin(names);                 // 자신의 이름을 적어주세요 !
  
  while(!SerialBT.connected(1000)) {
  Serial.println("연결되지 않았습니다.");
  }
  delay(1000);                            // 제대로 연결이 되어야하니 잠시 대기

  String message = names + String(" : 연결에 성공했습니다!");
  Serial.println(message);                // 시리얼에 연결에 성공했다고 출력
  SerialBT.println(message.c_str());      // 연결된 블루투스에 성공했다고 전송
}


void loop() {
  char cmd = -1;
  
  if(SerialBT.available()){               // 입력받은 값을 저장하고 입력 받은 값 출력 
    cmd =(char)SerialBT.read();
    Serial.print("입력값 = ");
    Serial.println(cmd);
  }
  
  if(cmd == '1'){                         // 1 입력되었을 때 빨강 LED 켜기
    Serial.println("빨강 온 !!!!");
    digitalWrite(led_red, HIGH);
  }  
  else if(cmd == '2'){                    // 2 입력되었을 때 빨강 LED 끄기
    Serial.println("빨강 오프 !!");
    digitalWrite(led_red, LOW);
  }
  else if(cmd == '3'){                    // 3 입력되었을 때 파랑 LED 켜기
    Serial.println("파랑 온 !!!!");
    digitalWrite(led_blue, HIGH);
  }  
  else if(cmd == '4'){                    // 4 입력되었을 때 파랑 LED 끄기
    Serial.println("파랑 오프 !!");
    digitalWrite(led_blue, LOW);
  }
  else if(cmd == '5'){                    // 5 입력되었을 때 초록 LED 켜기
    Serial.println("초록 온 !!!!");
    digitalWrite(led_green, HIGH);
  }  
  else if(cmd == '6'){                    // 6 입력되었을 때 초록 LED 끄기
    Serial.println("초록 오프 !!");
    digitalWrite(led_green, LOW);
  }
  else if(cmd == '7'){                    // 7 입력되었을 때 노랑 LED 켜기
    Serial.println("노랑 온 !!!!");
    digitalWrite(led_yellow, HIGH);
  }  
  else if(cmd == '8'){                    // 8 입력되었을 때 노랑 LED 끄기
    Serial.println("노랑 오프 !!");
    digitalWrite(led_yellow, LOW);
  }
  else if(cmd == '9')
  {
    Serial.println("모두 오프 !!");
    digitalWrite(led_red, LOW);
    digitalWrite(led_blue, LOW);
    digitalWrite(led_green, LOW);
    digitalWrite(led_yellow, LOW);
  }
    else if(cmd == 'A')
  {
    Serial.println("모두 온 !!");
    digitalWrite(led_red, HIGH);
    digitalWrite(led_blue, HIGH);
    digitalWrite(led_green, HIGH);
    digitalWrite(led_yellow, HIGH);
  }
  else
  {
    //그 외에는 아무것도 하지 않음
  }
  delay(20);                              // 0.02초 대기
}

//=========================================================================================
//
// (주)한국공학기술연구원 http://et.ketri.re.kr
//
//=========================================================================================
