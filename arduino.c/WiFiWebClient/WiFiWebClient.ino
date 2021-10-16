#include <SPI.h>
#include <WiFiNINA.h>
#include "secretData.h"

char ssid[] = SSIDNAME;
char pass[] = PASSWORD;
int status = WL_IDLE_STATUS;
int keyIndex = 0;  
char server[] = "www.google.com";  
WiFiClient client;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);

  if(WiFi.status() == WL_NO_MODULE){
    Serial.println("沒有這個網路模組wifinina");
  }
  Serial.println("檢查完成");

  String fv = WiFi.firmwareVersion();
  if (fv < WIFI_FIRMWARE_LATEST_VERSION) {
    Serial.println("Please upgrade the firmware");
  }

  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  Serial.println("連線成功");
  printWifiStatus();

  Serial.println("開始連線至google...");
  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    Serial.println("連線到server");
    // Make a HTTP request:
    client.println("GET /search?q=arduino HTTP/1.1");
    client.println("Host: www.google.com");
    client.println("Connection: close");
    client.println();
  }
  
  Serial.println("檢查完成");
}

void loop() {
  // if there are incoming bytes available
  // from the server, read them and print them:
  while (client.available()) {
    char c = client.read();
    Serial.write(c);
  }

  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("停止連線至 google");
    client.stop();

    // do nothing forevermore:
    while (true);
  }
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your board's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
