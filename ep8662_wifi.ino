
#include <ESP8266WiFi.h> // ESP8266WiFi 라이브러리 삽입
#include <WiFiUdp.h>
#include <NTPClient.h>

const char* ssid = "MY2"; //WiFi 네트워크 이름
const char* password = "plc88888"; // WiFi 네트워크 비번

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, 32400);

void setup() {
  Serial.begin(115200); // 통신속도 설정
  delay(10);            // 10ms 대기
  WiFi.mode(WIFI_STA);  // WiFi를 STA모드로 설정
  WiFi.begin(ssid, password);
  Serial.println("");
  Serial.println(ssid);
  while( WiFi.status() != WL_CONNECTED ) {
    delay(200);
    Serial.print(".");  
  }

  Serial.println("");
  Serial.print("Wifi connected to "); Serial.println(ssid);
  Serial.print("IP address "); 
  Serial.println(WiFi.localIP()); //공유기 DHCP에 의해 ESP 모듈에 할당된 IP 출력

  timeClient.begin();
}

void loop() {
  timeClient.update();
  Serial.print("KOREA Time "); 
  Serial.println(timeClient.getFormattedTime());
  delay(1000);
}




