#include <Wire.h>
#include "SparkFunHTU21D.h"

// Create an instance of the object
HTU21D myHumidity;

const int LED1 = 8; // LED 핀 번호
const int LED2 = 9;

void show_yes_no(const char *prefix, int val)
{
  Serial.print(prefix);
  if (val)
    Serial.println("yes");
  else
    Serial.println("no");
}

void dump_user_register()
{
  byte reg = myHumidity.readUserRegister();

  Serial.print("Resolution (Humidity, Temperature): ");
  switch (reg & USER_REGISTER_RESOLUTION_MASK) {
  case USER_REGISTER_RESOLUTION_RH12_TEMP14: Serial.print(12); Serial.print(", "); Serial.println(14); break;
  case USER_REGISTER_RESOLUTION_RH8_TEMP12: Serial.print(8); Serial.print(", "); Serial.println(12); break;
  case USER_REGISTER_RESOLUTION_RH10_TEMP13: Serial.print(10); Serial.print(", "); Serial.println(13); break;
  case USER_REGISTER_RESOLUTION_RH11_TEMP11: Serial.print(11); Serial.print(", "); Serial.println(11); break;
  }

  show_yes_no("End of battery: ", reg & USER_REGISTER_END_OF_BATTERY);
  show_yes_no("Heater enabled: ", reg & USER_REGISTER_HEATER_ENABLED);
  show_yes_no("Disable OTP reload: ", reg & USER_REGISTER_DISABLE_OTP_RELOAD);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("HTU21D Example!");

  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT); // LED1 핀을 출력으로 설정
  myHumidity.begin();
  
  dump_user_register();
}

void loop()
{
  float humd = myHumidity.readHumidity();
  float temp = myHumidity.readTemperature();

  Serial.print("Time:");
  Serial.print(millis());
  Serial.print(" Temperature:");
  Serial.print(temp, 1);
  Serial.print("C");
  Serial.print(" Humidity:");
  Serial.print(humd, 1);
  Serial.print("%");
  Serial.println();

  if (temp >= 30.0 && humd >= 50.0) {
    digitalWrite(LED2, HIGH); // LED2 켜기
  } else {
    digitalWrite(LED2, LOW); // 조건이 만족되지 않으면 LED2 끄기
  }


  // 온도가 30도 이상이고 습도가 70% 이상이면 LED1 깜빡이기
  if (temp >= 30.0 || humd >= 50.0) {
    digitalWrite(LED1, HIGH); // LED1 켜기
    delay(500); // 0.5초 대기
    digitalWrite(LED1, LOW); // LED1 끄기
    delay(500); // 0.5초 대기
  } else {
    digitalWrite(LED1, LOW); // 조건이 만족되지 않으면 LED1 끄기
   
  }
  
  delay(1000); // 1초 대기
}
