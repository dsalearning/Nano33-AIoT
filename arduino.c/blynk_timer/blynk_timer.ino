#include <BlynkSimpleWiFiNINA.h>

BlynkTimer timer1;
BlynkTimer timer2;
BlynkTimer timer3;

void setup() {
  Serial.begin(9600);
  timer1.setInterval(1000,oneSecond);
  timer1.setInterval(2000,twoSecond);
  timer1.setInterval(3000,thirdSecond);

}

void loop() {
  timer1.run();
  timer2.run();
  timer3.run();
}

void oneSecond(){
  Serial.println("過1秒");
}

void twoSecond(){
  Serial.println(" 過2秒");
}

void thirdSecond(){
  Serial.println("  過3秒");
}
