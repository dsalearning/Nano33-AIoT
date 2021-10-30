#ifndef __CH595_H__  //如果沒有定義 __CH595_H__
#define __CH595_H__  //就立刻定義 __CH595_H__

#include <arduino.h>
/*
 * setNumberCH595(顯示的數字, latchPin, dataPin, clockPin）
*/
void setNumberCH595(byte n,byte latch, byte data,byte clk){
  pinMode(data, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(clk, OUTPUT);
  
  byte numbers[10] = {B01111110,B00110000,B01101101,B01111001,B00110011,B01011011,B01011111,B01110000,B01111111,B01111011};
  digitalWrite(latch, LOW);
  shiftOut(data,clk,LSBFIRST,numbers[n]);
  digitalWrite(latch, HIGH);
}

#endif
