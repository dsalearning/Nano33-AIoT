void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  intervalOne();
}

void intervalOne(){
  //不會從記憶體中消滅，同全域變數的用法
  static unsigned long previousTime = millis();
  unsigned long currentTime;
  currentTime = millis();
  if(currentTime-previousTime >=5000){
    previousTime = currentTime;
    Serial.println("開機到現在已經過了 "+String(long(currentTime/1000))+" 秒");
  }
}
