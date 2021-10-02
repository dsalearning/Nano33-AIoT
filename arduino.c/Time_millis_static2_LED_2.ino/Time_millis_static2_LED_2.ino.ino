#define RED 2
#define YELLOW 3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(RED,OUTPUT);
  pinMode(YELLOW,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  intervalOne();
  intervalTwo();
}


void intervalOne(){
  static bool ledState = false;
  static unsigned long previousTime = millis();
  unsigned long currentTime;
  currentTime = millis();
  if(currentTime-previousTime >= 1000){
    previousTime = currentTime;
    Serial.println("每隔1秒執行一次");
    ledState = !ledState;
    if(ledState == false){
      digitalWrite(RED,HIGH);
    }else{
      digitalWrite(RED,LOW);
    }
  }
}

void intervalTwo(){
  static bool ledState = false;
  static unsigned long previousTime = millis();
  unsigned long currentTime;
  currentTime = millis();
  if(currentTime-previousTime >= 2000){
    previousTime = currentTime;
    Serial.println("每隔 2 秒執行一次");
    ledState = !ledState;
    if(ledState == false){
      digitalWrite(YELLOW,HIGH);
    }else{
      digitalWrite(YELLOW,LOW);
    }
  }
}
