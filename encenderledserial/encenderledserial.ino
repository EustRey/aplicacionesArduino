int led = 10;
int brillo = 0;
String cadena;

void setup() {
 Serial.begin(9600);
 pinMode(led, OUTPUT);
}

void loop() {
  if (Serial.available()>0){
    cadena = Serial.readStringUntil('\n');
    brillo = cadena.toInt();
   
   

    if (brillo>255){
      brillo = 255;
    }
    if (brillo<0){
      brillo = 0;
    }
    Serial.println(brillo);
    analogWrite(led,brillo);
    
    
  }