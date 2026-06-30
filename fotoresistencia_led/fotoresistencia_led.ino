const int lectFot=A0;
int valAnalogico = 0;
const int led = 11;
int mapeo = 0;

void setup()
{
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  valAnalogico = analogRead(lectFot);
  mapeo = map(valAnalogico, 3, 35, 0, 255);
  if (mapeo>150){
  	analogWrite(led, mapeo);
  }else{
    analogWrite(led, LOW);
  }
  Serial.print(valAnalogico);
  Serial.print(" ");
  Serial.println(mapeo);
}
