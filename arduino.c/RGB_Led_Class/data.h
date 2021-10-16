#include <arduino.h>

class RGB_LED{
  public:
    int inputPin;
    int outputPin;

    RGB_LED(int,int);
    void run();
};

RGB_LED::RGB_LED(int in, int out){
  inputPin = in;
  outputPin = out;
  
  pinMode(outputPin,OUTPUT);
}

void RGB_LED::run(){
  int v = analogRead(inputPin);
  byte vValue = map(v, 0, 1023, 0, 255);
  analogWrite(outputPin,vValue);
}
