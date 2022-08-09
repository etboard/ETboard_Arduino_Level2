/******************************************************************************************
 * FileName     : 05._led_button_control_2
 * Description  : 버튼과 같은 색의 LED 켰다 꺼보기
 * Author       : 이인정
 * Created Date : 2021.05.28
 * Reference    : 
 * Modified     : 2021.06.02 : LIJ : 헤더 수정
 * Modified     : 2021.12.16 : LEH : 소스 크린징
******************************************************************************************/

int led_red    = D2;             // 빨강 LED
int led_blue   = D3;             // 파랑 LED
int led_green  = D4;             // 초록 LED
int led_yellow = D5;             // 노랑 LED

int button_red    = D6;          // 빨강 버튼
int button_blue   = D7;          // 파랑 버튼
int button_green  = D8;          // 초록 버튼
int button_yellow = D9;          // 노랑 버튼

int button_red_value = 0;        // 빨강 버튼의 상태
int button_red_old_value = 1;    // 빨강 버튼의 이전 상태
int led_red_status = 0;          // 빨강 LED 상태

int button_blue_value = 0;        // 파랑 버튼의 상태
int button_blue_old_value = 1;    // 파랑 버튼의 이전 상태
int led_blue_status = 0;          // 파랑 LED 상태

int button_green_value = 0;       // 초록 버튼의 상태
int button_green_old_value = 1;   // 초록 버튼의 이전 상태
int led_green_status = 0;         // 초록 LED 상태

int button_yellow_value = 0;      // 노랑 버튼의 상태
int button_yellow_old_value = 1;  // 노랑 버튼의 이전 상태
int led_yellow_status = 0;        // 노랑 LED 상태


void setup() {
  pinMode(led_red, OUTPUT);       // 핀 모드 설정
  pinMode(led_blue, OUTPUT);      // 핀 모드 설정
  pinMode(led_green, OUTPUT);     // 핀 모드 설정
  pinMode(led_yellow, OUTPUT);    // 핀 모드 설정
  
  pinMode(button_red, INPUT);     // 핀 모드 설정
  pinMode(button_blue, INPUT);    // 핀 모드 설정
  pinMode(button_green, INPUT);   // 핀 모드 설정
  pinMode(button_yellow, INPUT);  // 핀 모드 설정
}


void loop() { 
  // 빨강 버튼 으로 빨강 LED 제어
  button_red_value = digitalRead(button_red);
  
  if(button_red_value == 0 && button_red_old_value == 1){
    led_red_status = 1 - led_red_status;
  }
  button_red_old_value = button_red_value;
  if(led_red_status == 1){
    digitalWrite(led_red, HIGH);
  }else{
    digitalWrite(led_red, LOW);
  }

  // 파랑 버튼 으로 파랑 LED 제어
  button_blue_value = digitalRead(button_blue);
  
  if(button_blue_value == 0 && button_blue_old_value == 1){
    led_blue_status = 1 - led_blue_status;
  }
  button_blue_old_value = button_blue_value;
  if(led_blue_status == 1){
    digitalWrite(led_blue, HIGH);
  }else{
    digitalWrite(led_blue, LOW);
  }

  // 초록 버튼 으로 초록 LED 제어
  button_green_value = digitalRead(button_green);
  
  if(button_green_value == 0 && button_green_old_value == 1){
    led_green_status = 1 - led_green_status;
  }
  button_green_old_value = button_green_value;
  if(led_green_status == 1){
    digitalWrite(led_green, HIGH);
  }else{
    digitalWrite(led_green, LOW);
  }

  // 노랑 버튼 으로 노랑 LED 제어
  button_yellow_value = digitalRead(button_yellow);
  
  if(button_yellow_value == 0 && button_yellow_old_value == 1){
    led_yellow_status = 1 - led_yellow_status;
  }
  button_yellow_old_value = button_yellow_value;
  if(led_yellow_status == 1){
    digitalWrite(led_yellow, HIGH);
  }else{
    digitalWrite(led_yellow, LOW);
  }
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
