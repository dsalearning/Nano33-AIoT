// C++ code
//
#define redled 12

void setup()
{
  pinMode(redled,OUTPUT);
}

void loop()
{
  digitalWrite(redled,HIGH);
  delay(1000);
  digitalWrite(redled,LOW);
  delay(1000);
}