byte push = 12;
bool lPush = false;
int led =2;

void setup()
{
  Serial.begin(9600);
  pinMode(push, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  lPush =digitalRead(push);
  if(!lPush==HIGH)
  {
    Serial.println("Presionado");
    digitalWrite(led, HIGH);
  }
  else
  {
    Serial.println("No presionado");
    digitalWrite(led, LOW);
  }
}