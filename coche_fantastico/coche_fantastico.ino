/*El coche fantastico 3*/
int pinArray[]={7,8,9,10,11,12};
int tiempo = 30;
int count=0;

void setup()
{
 for(count=0; count<=6; count++)
 {
  pinMode(pinArray[count], OUTPUT);
 }
}

void loop()
{
  secuencia_uno();
  secuencia_dos();
}
  
//subrutinas
void secuencia_uno()
{
 for(count=0; count<=6; count++)
 {
  digitalWrite(pinArray[count], HIGH);
  delay(tiempo); 
  /*digitalWrite(pinArray[count+1], HIGH);
  delay(tiempo); */
  digitalWrite(pinArray[count],LOW);
  delay(tiempo*2);
 }
}
  
void secuencia_dos()
{
 for(count=5; count>=0; count--)
 {
  digitalWrite(pinArray[count], HIGH);
  delay(tiempo); 
  /*digitalWrite(pinArray[count-1], HIGH);
  delay(tiempo); */
  digitalWrite(pinArray[count],LOW);
  delay(tiempo*2);
 }
}