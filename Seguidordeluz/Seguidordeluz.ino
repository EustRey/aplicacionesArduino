#include <Servo.h>
Servo servo0;

const int eAnalogica0 = A0;
const int eAnalogica1 = A1;

int lectA0 = 0;
int lectA1 = 0;

void setup()
{
  Serial.begin(9600);
  servo0.attach(11);
}

void loop()
{
 lectA0 = analogRead(eAnalogica0);
 lectA1 = analogRead(eAnalogica1);
  
  Serial.print(lectA0);
  Serial.print("    |    ");
  Serial.println(lectA1);
  
  if(lectA0>lectA1){
    servo0.write(45);
  }
  else if(lectA1>lectA0){
    servo0.write(125);
  }
  else if(lectA0 == lectA1){
    servo0.write(90);
  }

}