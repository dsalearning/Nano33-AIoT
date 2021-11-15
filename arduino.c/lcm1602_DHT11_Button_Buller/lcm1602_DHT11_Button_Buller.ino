#include "releaseButton.h"
#include <sound.h>
#define BUTTON 5
#define BUZZER 4
#include <SimpleTimer.h>
SimpleTimer timer;
SimpleTimer timer60;

#include "DHT.h"
#define DHTTYPE DHT11
#define DHTPIN 2
DHT dht(DHTPIN, DHTTYPE);

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,20,2);


unsigned int stateChangeCount =0;
bool isOpen = false;
Sound sound(BUZZER);
int timerId;
int timerId60;
bool alertState = false;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  pinMode(BUTTON,INPUT_PULLUP);
  pinMode(BUZZER,OUTPUT);
  dht.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello, world!");
  lcd.setCursor(2,1);
  lcd.print("Ywrobot Arduino!");
  timerId = timer.setInterval(2000, workOfSecond);
  timer.disable(timerId);
}

void loop() {
  timer.run();
  timer60.run();
  stateChangeCount += button_release(BUTTON);
  bool switchState = displayNum(stateChangeCount,1);
  if(switchState){
    //1
    buttonOpen();
  }else{
    //0
    buttonClose();
  }
}

void buttonOpen(){
  if(isOpen==false){
    isOpen = true;
    Serial.println("Open");
//    digitalWrite(BUZZER,true);
//    delay(1000);
//    digitalWrite(BUZZER,false);
//    tone(BUZZER,4978,1000);
//    sound.beep(1000);
//    sound.melodySound();
    sound.phone();
//    sound.bee();
    timer.enable(timerId);
//    lcd.clear();
//    lcd.setCursor(5,0);
//    lcd.print("Open!");
  }
}

void buttonClose(){
  if(isOpen == true){
    isOpen = false;
    Serial.println("關");
    lcd.clear();
    lcd.setCursor(5,0);
    lcd.print("Close!");
//    digitalWrite(BUZZER,true);
//    delay(1000);
//    digitalWrite(BUZZER,false);
//    tone(BUZZER,4978,1000);
//    sound.beep(1000);
//    sound.melodySound();
    sound.phone();
//    sound.bee();
    timer.disable(timerId);
  }
}

void workOfSecond(){
  float h = dht.readHumidity();
    float t = dht.readTemperature();
    if (isnan(h) || isnan(t)) {
    Serial.println("測試失敗");
      return;
    }
    Serial.print(F("Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.println(F("°C "));
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("H:"+String(h)+" %");
    lcd.setCursor(0,1);
    lcd.print("T:"+String(t)+" C");

    if(t > 27.0){
      alert();
    }
}

void alert(){
    if(alertState == false){
        timerId60 = timer60.setInterval(1000*10,caculateTime);  
        alertState = true;
        Serial.println("alert");
        sound.melodySound();
    }
        
}

void caculateTime(){
  Serial.println("計時");
  timer60.disable(timerId60);
  alertState = false;
}
