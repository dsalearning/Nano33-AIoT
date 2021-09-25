// 在監控視窗要能看到 setup 裡的 print，一定要加上 while(！Serial) 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Hello,Word!");
}

void loop() {
  // put your main code here, to run repeatedly:
}
