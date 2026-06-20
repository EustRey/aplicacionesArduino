#include <Servo.h>

// =====================================================
// DECLARACIÓN DE PINES
// =====================================================

// Pines del sensor ultrasónico HC-SR04
const int trigPin = 9;
const int echoPin = 10;

// Pin de control del servomotor
const int servoPin = 3;

// Crear objeto Servo
Servo myServo;

// Variable para almacenar la distancia medida
float distance;

// =====================================================
// FUNCIÓN PARA MEDIR LA DISTANCIA
// =====================================================
float medirDistancia() {

  // Generar pulso de disparo del sensor ultrasónico
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Capturar el tiempo de retorno del eco
  long duration = pulseIn(echoPin, HIGH);

  // Calcular distancia en centímetros
  return (duration * 0.034) / 2;
}

// =====================================================
// CONFIGURACIÓN INICIAL
// =====================================================
void setup() {

  // Inicializar comunicación serial
  Serial.begin(9600);

  // Configurar pines del sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Conectar el servomotor
  myServo.attach(servoPin);

  // Posición inicial del servo
  myServo.write(0);
}

// =====================================================
// BUCLE PRINCIPAL
// =====================================================
void loop() {

  // Medir distancia
  distance = medirDistancia();

  // Mostrar distancia en el monitor serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  // =================================================
  // SI EL OBJETO ESTÁ CERCA, EL SERVO GIRA A 180°
  // =================================================
  while (distance < 30) {

    Serial.println("Objeto detectado - Giro a 180°");

    myServo.write(180);

    delay(500);

    // Actualizar distancia para salir del while
    distance = medirDistancia();

    Serial.print("Distancia: ");
    Serial.print(distance);
    Serial.println(" cm");
  }

  // =================================================
  // SI EL OBJETO SE ALEJA, EL SERVO REGRESA A 0°
  // =================================================
  myServo.write(0);

  Serial.println("Sin objeto cercano - Giro a 0°");

  delay(500);
}
