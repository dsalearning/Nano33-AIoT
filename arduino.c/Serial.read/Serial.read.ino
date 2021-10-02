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
    //輸入 a，此時用變數時，輸出不再是 97 而是 a, 當輸入 123時，收到會是各字元分開
    inputValue = Serial.read();
    Serial.println(inputValue);
  }
}
