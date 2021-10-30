#include "ch595.h"
#define dataPin 2
#define latchPin 3
#define clockPin 4

byte i = 0;

void setup() {
  // put your setup code here, to run once:
//  Serial.begin(9600);
//  while(!Serial);
//初始化測試顯示 8
//  pinMode(dataPin, OUTPUT);
//  pinMode(latchPin, OUTPUT);
//  pinMode(clockPin, OUTPUT);
//  digitalWrite(latchPin, LOW);
//  byte number = B01111111;
//  shiftOut(dataPin,clockPin,LSBFIRST,number);
//  digitalWrite(latchPin,HIGH);

//  #ifdef MAC
//  Serial.println("MAC");
//  #else
//  Serial.println("WINDOWS");
//  #endif
  
//  setNumberCH595(8,latchPin, dataPin, clockPin);
}

void loop() {
  if(i >= 10) i = 0;  
  setNumberCH595(i,latchPin,dataPin,clockPin);
  i++;
  delay(1000);
}
