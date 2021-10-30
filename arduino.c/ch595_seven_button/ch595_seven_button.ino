#include "ch595.h"
#define dataPin 2
#define latchPin 3
#define clockPin 4
#define button 5

unsigned long switchCount=0; //狀態改變的次數
int i = 0; //按下和放開的次數
bool buttonState;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  pinMode(button,INPUT_PULLUP);
  
  buttonState = digitalRead(button);
  
//  setNumberCH595(8,latchPin, dataPin, clockPin);
}

void loop() {
  bool currentButtonState = digitalRead(button);
  if(currentButtonState != buttonState){
    delay(30); //解決彈跳
    if(currentButtonState != buttonState){
      buttonState=currentButtonState;
      switchCount++;
      if(switchCount % 2 ==0){
        i = switchCount / 2;
        if(i==10){
          switchCount=0;
          i=0;
        }
        Serial.println(i);
      }
    }
  }
}
