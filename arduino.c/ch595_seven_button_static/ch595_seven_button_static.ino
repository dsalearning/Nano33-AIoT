#define BLYNK_PRINT Serial
#include "secret.h"
#include "ch595.h"
#include "releaseButton.h"
#include <SPI.h>
#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>

#define dataPin 2
#define latchPin 3
#define clockPin 4
#define button 5

int count = 0; //計算按鈕狀態改變的次數
int displayNumberState;

BlynkTimer timer;
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = SSIDNAME;
char pass[] = PASSWORD;

void setup() {
  Serial.begin(9600); 
  displayNumberState = displayNum(count,9);
  setNumberCH595(0,latchPin,dataPin,clockPin);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(1000, myTimerEvent);
}

void loop() {    
  Blynk.run();
  timer.run();
  count += button_release(button);    
  int displayNumber = displayNum(count,9);
  if(displayNumber != displayNumberState){
     displayNumberState = displayNumber;
     setNumberCH595(displayNumberState,latchPin,dataPin,clockPin);
     Serial.println(displayNumber);  
  }
}

void myTimerEvent(){
  Blynk.virtualWrite(V1,displayNumberState);
}
