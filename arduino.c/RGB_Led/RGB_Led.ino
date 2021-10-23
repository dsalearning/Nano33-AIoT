#define INPUT_RED A0
#define INPUT_GREEN A1
#define INPUT_BLUE A2
#define OUTPUT_RED 2
#define OUTPUT_GREEN 3
#define OUTPUT_BLUE 5

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(OUTPUT_RED,OUTPUT);
  pinMode(OUTPUT_GREEN,OUTPUT);
  pinMode(OUTPUT_BLUE,OUTPUT);
  
  while(!Serial);

}

void loop() {
  readSensor();
  delay(100);
}

void readSensor(){
  int r = analogRead(INPUT_RED);
  int g = analogRead(INPUT_GREEN);
  int b = analogRead(INPUT_BLUE);

  byte rValue = map(r, 0, 1025, 0, 255);
  byte gValue = map(g, 0, 1025, 0, 255);
  byte bValue = map(b, 0, 1025, 0, 255);

//  Serial.println("紅色：" + String(rValue));
//  Serial.println("綠色：" + String(gValue));
//  Serial.println("藍色：" + String(bValue));
//  Serial.println("-------------------");
  changeColor(rValue,gValue,bValue);
}

void changeColor(byte r, byte g, byte b){
  analogWrite(OUTPUT_RED,r);
  analogWrite(OUTPUT_GREEN,g);
  analogWrite(OUTPUT_BLUE,b);
}
