void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  Serial.print("Hello,World!");
}

void loop() {
  // put your main code here, to run repeatedly:
  //如果沒有東西就執行,先進先出,記得把監控視窗設為沒有行結尾，然後輸入 a，會得到97。
  if(Serial.available()){
    Serial.println(Serial.read());
  }
}
