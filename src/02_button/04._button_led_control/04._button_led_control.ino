/******************************************************************************************
 * FileName     : 04._led_button_control
 * Description  : 빨강 버튼을 눌러 빨강 LED를 켜보기
 * Author       : 이인정
 * Created Date : 2021.10.15
 * Reference    : 
 * Modified     : 2021.06.02 : LIJ : 헤더 수정
 * Modified     : 2021.12.22 : LEH : 소스 크린징
******************************************************************************************/

int led_red    = D2;             // 빨강 LED
int button_red    = D6;          // 빨강 버튼

int button_red_value = 0;        // 빨강 버튼의 상태
int button_red_old_value = 1;    // 빨강 버튼의 이전 상태
int led_red_status = 0;          // 빨강 LED 상태


void setup() {
  pinMode(led_red, OUTPUT);      // 핀 모드 설정  
  pinMode(button_red, INPUT);    // 핀 모드 설정
}


void loop() { 
  // 빨강 버튼 으로 빨강 LED 제어
  button_red_value = digitalRead(button_red);
  
  if(button_red_value == LOW && button_red_old_value == HIGH){
    led_red_status = !led_red_status;
  }
  button_red_old_value = button_red_value;
  if(led_red_status == HIGH){
    digitalWrite(led_red, HIGH);
  }else{
    digitalWrite(led_red, LOW);
  }
}

//=========================================================================================
//                                                    
// (주)한국공학기술연구원 http://et.ketri.re.kr       
//                                                    
//=========================================================================================
