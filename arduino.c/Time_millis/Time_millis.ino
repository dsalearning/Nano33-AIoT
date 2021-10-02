unsigned long previousTime;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  previousTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long currentTime;
  currentTime = millis();
  if(currentTime-previousTime >=5000){
    previousTime = currentTime;
    Serial.println("開機到現在已經過了 "+String(long(currentTime/1000))+" 秒");
  }
}
