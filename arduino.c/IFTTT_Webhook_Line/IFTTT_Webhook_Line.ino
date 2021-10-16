#include <SPI.h>
#include <WiFiNINA.h>

#include "secret.h"

#define CDS A0

char ssid[] = SSIDNAME;
char pass[] = PASSWORD;
char server[] = "maker.ifttt.com";

int status = WL_IDLE_STATUS;
bool sended = false;
unsigned long triggerTime=0;

WiFiSSLClient client;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  //如果連線狀態，不是 WL_CONNECTED，就繼續執行
  while(status != WL_CONNECTED){
    Serial.print("正在連線到 SSID ：");
    Serial.println(ssid);
    status = WiFi.begin(ssid,pass);
    delay(5000);
  }
  Serial.println("已連線成功");

  //也可以用 client.connectSQL()
  if(client.connect(server, 443)){
    Serial.println("已連線到 Server");

    //sendMail("%E7%8E%8B%E5%B0%8F%E6%98%8E","%E9%83%BD%E5%B9%BE%E9%BB%9E%E4%BA%86%E9%82%84%E4%B8%8D%E7%9D%A1","%E8%B6%95%E5%BF%AB%E5%8E%BB%E7%9D%A1%EF%BC%81");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting from server.");
    client.stop();
  }
  
  getCDS();
}

void getCDS(){
  int sensorValue = analogRead(CDS);
  Serial.println(sensorValue);
  delay(1000);
  if(sensorValue >=950 && sended==false){

    // Make a HTTP Get request: 但是中文會亂碼
    //%E7%8E%8B%E5%B0%8F%E6%98%8E
    //王小明
    String v1= "%E7%8E%8B%E5%B0%8F%E6%98%8E"; 
    //%E9%83%BD%E5%B9%BE%E9%BB%9E%E4%BA%86%E9%82%84%E4%B8%8D%E7%9D%A1
    //都幾點了還不睡
    String v2="%E9%83%BD%E5%B9%BE%E9%BB%9E%E4%BA%86%E9%82%84%E4%B8%8D%E7%9D%A1";
    //%E8%B6%95%E5%BF%AB%E5%8E%BB%E7%9D%A1%EF%BC%81
    //趕快去睡！
    String v3="%E8%B6%95%E5%BF%AB%E5%8E%BB%E7%9D%A1%EF%BC%81";
   
    sendMail(v1,v2,v3);
  }
  calculatTime();
}

void calculatTime(){
  unsigned long currentTime = millis();
  if((currentTime - triggerTime)>=10000){
    sended = false;
  }
}

void sendMail(String value1, String value2, String value3){
    Serial.println("發送Line");
    if(client.connectSSL(server, 443)){
      String httprequest = "GET /trigger/over950/with/key/" + String(IFTTTKEY) + "?value1=" + String(value1) + "&value2=" + String(value2) + "&value3=" + String(value3) + " HTTP/1.1";
      client.println(httprequest);
      client.println("Host: " + String(server));
      //client.println("Connection: close");
      client.println();
    }else{
      Serial.println("發送失敗");
    }
  
    sended=true;
    triggerTime = millis();

}
