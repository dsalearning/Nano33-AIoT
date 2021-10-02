long inputValue;
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
    //輸入 123，此時用 parseInt讀取時，輸出不再是 1,2,3 而是 123，數字大小可以控制燈的亮度
    inputValue = Serial.parseInt();
    Serial.println("您要輸出的字元是"+String(inputValue));
    analogWrite(LED,inputValue);
  }
}
