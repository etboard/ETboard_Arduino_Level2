/******************************************************************************************
 * FileName     : 03._WiFi_web_server_variable_resistance
 * Description  : 가변저항 값을 보여주는 웹서버 만들어 보기
 * Author       : 위대원
 * Created Date : 2021.06.02
 * Reference    : ET보드(ESP32)는 2.4GHz WiFi만 지원함
 * Modified     : 2021.06.02 : WDW : 헤더 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
******************************************************************************************/

// WiFi 연결을 위해서는 2.5GHz WiFi가 필수입니다.(5GHz 불가능)
// 이 라이브러리를 통해 Arduino 보드를 인터넷에 연결할 수 있습니다.
#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>

const char* ssid = "ssid";                      // 와이파이 아이디
const char* password = "password";              // 와이파이 비밀번호

WebServer server(80);                           // 서버에서 사용할 포트 설정

const int led = D2;                             // 빨강 LED의 핀번호


void handleRoot() {                             // root(/)로 접속했을 때 처리하는 함수
  digitalWrite(led, HIGH);                      // LED를 켜기
  Serial.println("root call!");                 // 페이지로 접속했다고 시리얼로 알려줌
  server.send(200, "text/plain", "hello from ET-board!");
  digitalWrite(led, LOW);                       // LED를 끄기
}


void handleA0() {                               // read_a0(/read_a0)로 접속했을 때 처리하는 함수
  int sensorValue = analogRead(A0);             // 가변 저항의 값을 읽어옴
  String sendData = "variable_resistance : ";   // 단순 문자열 저장
  sendData = sendData + String(sensorValue);    // 출력할 값을 만들어냄
  Serial.println("A0 call!");                   // 페이지로 접속했다고 시리얼로 알려줌
  server.send(200, "text/plain", sendData);
}


void setup(void) {
  pinMode(led, OUTPUT);                         // LED를 출력상태로 설정
  digitalWrite(led, LOW);                       // LED를 끈 상태로 설정
  Serial.begin(115200);                         // 시리얼 통신속도 설정
  WiFi.mode(WIFI_STA);                          // 연결모드로 설정
  WiFi.begin(ssid, password);                   // WiFi에 접속을 시도
  Serial.println("");
  
  while (WiFi.status() != WL_CONNECTED) {       // 연결이 될 때까지 계속 대기
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());                // 연결이 됐다면 할당받은 아이피를 출력함

  server.on("/", handleRoot);                    // root(/)로 접속했을 때 처리하는 함수랑 연결
  server.on("/read_a0", handleA0);               // read_a0(/read_a0)

  server.begin();                                // 서버 시작
  Serial.println("HTTP server started");
}


void loop(void) {
  server.handleClient();                         // 클라이언트의 접속을 받음
  delay(2);
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
