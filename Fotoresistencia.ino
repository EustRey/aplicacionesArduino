int SENSOR = 0;
int LED = 3;
int VALOR;
int PWM;

void setup() {
  pinMode(LED, OUTPUT);
  

}

void loop() {
 VALOR = analogRead(SENSOR);

 PWM = map(VALOR, 0, 1023, 0, 255);
 analogWrite(LED, PWM);
 
 /*if (VALOR<200){
  digitalWrite(LED,HIGH);
  delay(1000);
 }
 digitalWrite(LED, LOW);*/
 
}
