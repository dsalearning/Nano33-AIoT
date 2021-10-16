#define BTN 2
#define LED 13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(BTN,INPUT_PULLUP); //1.1 上拉電阻
  pinMode(LED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  bool btnState = digitalRead(BTN);
  Serial.println(String(btnState));
  if(btnState==LOW){
    Serial.println("按鈕被按了");
    digitalWrite(LED,HIGH);
  }else{
    Serial.println("沒按按鈕");
    digitalWrite(LED,LOW);
  }
  delay(10);
}
