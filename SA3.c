
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
Servo myservo;

LiquidCrystal_I2C lcd (0x27, 16, 2);

#define ECHO_PIN 2
#define TRIG_PIN 3
#define SERVO_PIN 5
#define LED 13


const float temperaturaMaxima = 33.00;
const float distanciaFimEsteira = 40.00;
float temperatura;
float distancia;
int valorSensorMovimento = 0;

float erro = 0.0;
int valorSaidaServo = 0;
float kp = 1.0;


void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.begin(16, 2);
  pinMode(SERVO_PIN, OUTPUT);
  myservo.attach(SERVO_PIN);
  lcd.clear();
}

float calculoTemperatura() {
  const float BETA = 3950;
  int analogValue = analogRead(A0);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  return celsius;
}


float calculoDistancia() {
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int duration = pulseIn(ECHO_PIN, HIGH);
  float distancia = (duration / 58);
  return distancia;
}

void loop() {
  temperatura = calculoTemperatura();
  erro = (temperatura - temperaturaMaxima);
  valorSaidaServo = map(erro * kp, -24.00, 30, 0, 180);
  myservo.write(valorSaidaServo);

  lcd.setCursor(0, 0);
  lcd.print("Temper: ");
  lcd.print(temperatura);
  lcd.print("  ");

  distancia = calculoDistancia();
  Serial.print("Distância: ");
  Serial.println(distancia);

  if (distancia < distanciaFimEsteira) {
    tone(12, 262, 500);
    Serial.println("Peça no fim da esteira!");
    delay(1000);
  } else if (temperatura > temperaturaMaxima) {
    tone(12, 262, 500);
    Serial.println("Esteira parada!");
    digitalWrite(LED, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("Valvula: ");
    lcd.print("Aberta");
    lcd.print("  ");
    delay(1000);
  } else {
    digitalWrite(LED, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Valvula: ");
    lcd.print("Fechada");
    lcd.print("  ");
    Serial.println("Esteira rolando!");
    delay(2000);
  }

}
