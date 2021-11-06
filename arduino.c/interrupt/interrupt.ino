#define WIRE_PIN 11
#define LIGHT_PIN 5

void setup() {
  pinMode(LIGHT_PIN,OUTPUT);
  pinMode(WIRE_PIN,INPUT_PULLUP);
  Serial.begin(9600);
  //插到接地造成中斷, 插入拔出時被偵測
  attachInterrupt(digitalPinToInterrupt(WIRE_PIN), blinkme, CHANGE);
  //插到接地造成中斷, 插入拔出時被偵測
  //attachInterrupt(digitalPinToInterrupt(WIRE_PIN), blinkme, FALLING);
}

void loop() {
  //這是偵測硬體的中斷,即使這裡delay長時間也是會被偵測到
  delay(10000);
}

void blinkme(){
  Serial.println("HELLO!");
}
