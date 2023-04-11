/******************************************************************************************
 * FileName     : 01._WiFi_IPAddress_print
 * Description  : WiFi에 연결하고 받은 IP주소를 출력 해 보기
 * Author       : 위대원
 * Created Date : 2021.06.02
 * Reference    : ET보드(ESP32)는 2.4GHz WiFi만 지원함
 * Modified     : 2021.06.02 : WDW : 헤더 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
******************************************************************************************/

// WiFi 연결을 위해서는 2.5GHz WiFi가 필수입니다.(5GHz 불가능)
// 이 라이브러리를 통해 Arduino 보드를 인터넷에 연결할 수 있습니다.
#include <WiFi.h>

const char* ssid     = "ssid";             // 와이파이 아이디
const char* password = "password";         // 와이파이 비밀번호


void setup()
{
    Serial.begin(115200);                  // 시리얼 통신속도 설정
    delay(10);                             // 0.01초 기다리기

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);            //ssid와 password를 이용해서 와이파이에 접속을 시도
    
    while (WiFi.status() != WL_CONNECTED) {//연결이 될 때까지 계속 대기
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());        //연결이 됐다면 할당받은 아이피를 출력함
}


void loop()
{
  delay(10);
}

//=========================================================================================
//
// (주)한국공학기술연구원 http://et.ketri.re.kr
//
//=========================================================================================
