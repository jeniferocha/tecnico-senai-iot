/*06) Crie um sistema para monitorar a disponibilidade de vagas de estacionamento
  usando sensores de ultrassom para detectar se uma vaga está ocupada ou não, o
  estacionamento possui 10 vagas.*/

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

#define ECHO_PIN 2
#define TRIG_PIN 3
int vagas = 0;

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Vagas livres:");
}

float readDistanceCM() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  int duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

void loop() {

  float distance = readDistanceCM();
  Serial.println(distance);

  if (distance < 3.00) {
    vagas = 0;
  }
  else if (distance >= 3.00 && distance < 10.00) {
    vagas = 1;
  }
  else if (distance >= 10.00 && distance < 100.00) {
    vagas = 2;
  }
  else if (distance >= 100.00 && distance < 200.00) {
    vagas = 4;
  }
  else if (distance >= 200.00 && distance < 270.00) {
    vagas = 6;
  }
  else if (distance >= 270.00 && distance < 310.00) {
    vagas = 8;
  }
  else if (distance >= 310.05) {
    vagas = 10;
  }

  lcd.setCursor(0, 1); // Posição corrigida para ajustar a exibição das vagas
  lcd.print("   "); // Limpar os caracteres anteriores
  lcd.setCursor(0, 1); // Reposicionar o cursor
  lcd.print(vagas);

  delay(1000);
}
