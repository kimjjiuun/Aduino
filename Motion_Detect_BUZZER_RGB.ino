// RGB 핀 번호 설정
int redPin = 8;     // 빨간색 LED 핀
int greenPin = 9;   // 녹색 LED 핀
int bluePin = 10;   // 파란색 LED 핀
int inputPin = 11;  // 움직임 센서 핀
int buzzerPin = 7;  // 부저 핀
int val = 0;

void setup() {
  // 핀 모드 설정
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(inputPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(inputPin);  // 움직임 감지

  if (val == HIGH) {
    // 움직임이 감지되면 빨간색 LED 점등 (LOW로 설정) 및 부저 울림
    setColor(0, 255, 255);  // 빨간색 (애노드형)
    tone(buzzerPin, 1000);  // 부저 주파수 1000Hz로 울림
    Serial.println("침입 발생! 침입 발생!");
  } else {
    // 움직임이 감지되지 않으면 RGB LED 끄기 (HIGH로 설정) 및 부저 멈춤
    setColor(255, 255, 255);  // LED OFF (애노드형)
    noTone(buzzerPin);        // 부저 멈춤
    Serial.println("움직임이 없습니다.");
  }

  delay(1000);  // 1초 대기 후 반복
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
