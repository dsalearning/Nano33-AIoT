char inputValue;
#define LED A2  //digital 16

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED,OUTPUT);
  while(!Serial);
  Serial.print("輸入 1 開燈, 不是 1 關燈");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    inputValue = Serial.read();
    if(inputValue == '1'){
      Serial.println("您輸入的是 1 --> 開燈");
      digitalWrite(LED,HIGH);
    }
    else{
      Serial.println("您輸入的不是 1 --> 關燈");
      digitalWrite(LED,LOW);
    }
  }
  analogWrite(LED,255);
}
