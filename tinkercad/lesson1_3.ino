// C++ code
//
void setup()
{
  int eng_score;
  
  Serial.begin(9600);
  Serial.println("English Score:");
  while(true){
    if(Serial.available()>0){
      eng_score = Serial.parseInt();
      break;
    }
  }
  Serial.print("Hello! Your english is ");
  Serial.println(eng_score);
}

void loop()
{
 
}