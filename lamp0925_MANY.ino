int LED1 = 8, LED2 = 9, LED3 = 10, LED4 = 10; 
int sw = 7; 

int ledState = 0;         // LED 상태 저장
int lastSwState = 0;      // 이전 버튼 상태 저장

void setup() { 
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);  //pin모드 입력상태
  pinMode(sw, INPUT_PULLUP);  //아두이노에는 내부저항(가상저항이 딱 연결됨 스위치에) 일 경우input pullup
}

void loop() { 
  int sw_in;
  char ch;

  sw_in = !digitalRead(sw); // 현재 버튼 상태 읽기
  if (sw_in == 1) {//스위치 입력
    Serial.println("ON!");
    digitalWrite(LED1, HIGH); // LED 상태에 따라 켜기 또는 끄기
    delay(100); 
    digitalWrite(LED1, 0); // LED 상태에 따라 켜기 또는 끄기
    delay(100); 
   }
  else {
    Serial.println("OFF");
    digitalWrite(LED1, LOW); 
    
  }

}