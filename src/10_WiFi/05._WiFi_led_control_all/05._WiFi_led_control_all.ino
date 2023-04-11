/******************************************************************************************
 *FileName     : 14._WiFi_led_control
 *Description  : WiFi 연결 후 웹에서 LED 켰다 꺼 보기
 *Author       : 포휴먼 이인정
 *Created Date : 2021.05.28
 *Reference    : ET보드(ESP32)는 2.4GHz WiFi만 지원함
 *Modified     : 2021.12.16 : LEH : 소스 크린징
 ******************************************************************************************/
// WiFi 연결을 위해서는 2.5GHz WiFi가 필수입니다.(5GHz 불가능)
// 이 라이브러리를 통해 Arduino 보드를 인터넷에 연결할 수 있습니다. 
#include <WiFi.h> 

int led2 = D2;                                         // 빨강 LED
int led3 = D3;                                         // 파랑 LED
int led4 = D4;                                         // 초록 LED
int led5 = D5;                                         // 노랑 LED

 
const char* ssid     = "ssid";                         // 와이파이 이름
const char* password = "password";                     // 와이파이 비번

// 지정된 포트에서 들어오는 연결을 수신하는 서버를 만듭니다.
WiFiServer server(80); 

 
void setup() {
    Serial.begin(115200);                              // 통신
    pinMode(led2, OUTPUT);                             // 핀 모드 설정
    pinMode(led3, OUTPUT);                             // 핀 모드 설정
    pinMode(led4, OUTPUT);                             // 핀 모드 설정
    pinMode(led5, OUTPUT);                             // 핀 모드 설정
 
    delay(10);                                         // 0.01초 대기
 
                                                       // WiFi network에 접속
 
    Serial.println();                                  // 한줄
    Serial.println();                                  // 한줄
    Serial.print("Connecting to ");                    // 출력
    Serial.println(ssid);                              // 출력
 
    WiFi.begin(ssid, password);                        // WIFI.begin 은 와이파이 접속 함수
 
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    } 
    // 만약 wifi 상태가 연결이 되지 않았다면 반복 딜레이는 500으로 시리얼에서 출력 .
 
    Serial.println("");                                 // 한줄
    Serial.println("WiFi connected.");                  // 출력
    Serial.print("IP address: ");                       // 출력 
    Serial.println(WiFi.localIP());                     // 와이파이 로컬 아이피 출력
    
    server.begin();                                     // 수신 대기중
}
 
int value = 0;

 
void loop(){
 WiFiClient client = server.available();                // 새로운 클라이언트 생성
 
  if (client) {                                         // 클라이언트가 만들어지고
    Serial.println("New Client.");                      // 시리얼 포트에 쓰고
    String currentLine = "";                            // 클라이언트에서 받을 문자열 변수준비
    while (client.connected()) {                        // 연결될 때까지...
      if (client.available()) {                         // 클라이언트에서 문자를 받으면
        char c = client.read();                         // 문자를 byte 단위로 읽고, 문자로 저장
        Serial.write(c);                                // 시리얼 모니터에 표시
        if (c == '\n') {                                // 문자가 개행문자이면..
 
            // 현재 라인에 아무것도 없으면,  행당 2개라인을 가짐
            // 이는 client HTTP 응답의 마지막이라는 것이므로 응답을 전송할 수 있다:
          if (currentLine.length() == 0) {
            // HTTP 헤더는 항상 응답코드 (e.g. HTTP/1.1 200 OK)로 시작하고
            // content-type이 나오고 빈칸이 나옴
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();
 
            // HTTP 응답은 다음과 같은 헤더를 가진다:
            client.print("<meta charset=\"UTF-8\">");
            client.print("<font size=16>Click <a href=\"/red_on\"> red On </a> to turn On LED<br></font>");
            client.print("<font size=16>Click <a href=\"/red_off\"> red Off</a> to turn Off LED<br></font>");
            client.print("<font size=16>Click <a href=\"/blue_on\"> blue On</a> to turn On LED<br></font>");
            client.print("<font size=16>Click <a href=\"/blue_off\"> blue Off</a> to turn Off LED<br></font>");
            client.print("<font size=16>Click <a href=\"/green_on\"> green On</a> to turn On LED<br></font>");
            client.print("<font size=16>Click <a href=\"/green_off\"> green Off</a> to turn Off LED<br></font>");
            client.print("<font size=16>Click <a href=\"/yellow_on\"> yellow On</a> to turn On LED<br></font>");
            client.print("<font size=16>Click <a href=\"/yellow_off\"> yellow Off</a> to turn Off LED<br></font>");            
 
            // HTTP 응답은 빈칸으로 끝난다.
            client.println();
            // while loop를 종료
            break;
          } else {                                       // 새로운 라인을 가지면, 현재라인 지움:
            currentLine = "";
          }
        } else if (c != '\r') {                          // carriage return 문자라면
          currentLine += c;                              // 현재라인 뒤에 붙임
        } 
 
        // 클라이언트 응답이 "GET /H" 또는 "GET /L" 였는지 확인:
        // 레드
        if (currentLine.endsWith("GET /red_on")) {
          digitalWrite(led2, HIGH);                      // GET /H LED 켬
        }
        if (currentLine.endsWith("GET /red_off")) {
          digitalWrite(led2, LOW);                       // GET /L LED 끔
        }
        // 블루
        if (currentLine.endsWith("GET /blue_on")) {
          digitalWrite(led3, HIGH);                      // GET /L LED 끔
        }
        if (currentLine.endsWith("GET /blue_off")) {
          digitalWrite(led3, LOW);                       // GET /L LED 끔
        }
        // 그린
        if (currentLine.endsWith("GET /green_on")) {
          digitalWrite(led4, HIGH);                      // GET /L LED 끔
        }
        if (currentLine.endsWith("GET /green_off")) {
          digitalWrite(led4, LOW);                       // GET /L LED 끔
        }
        // 옐로우
        if (currentLine.endsWith("GET /yellow_on")) {
          digitalWrite(led5, HIGH);                      // GET /L LED 끔
        }
        if (currentLine.endsWith("GET /yellow_off")) {
          digitalWrite(led5, LOW);                       // GET /L LED 끔
        }
      }
    }
    // 연결 종료:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
