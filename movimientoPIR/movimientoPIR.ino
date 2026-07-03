/*Este programa, cada vez que el sensor de movimiento
* detecta movimiento, hace parpadear el LED del pin 13 de la placa
* del Arduino UNO.
*/
void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  int value = digitalRead(2);
  if (value == HIGH) {
    digitalWrite(13, HIGH);
    delay(50);
    digitalWrite(13, LOW);
    delay(50);
  } else {
    digitalWrite(13, LOW);
  }
  
}
