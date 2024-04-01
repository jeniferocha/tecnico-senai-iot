
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const int sensorMovimentoPIR = 11;
const int ledSonsor = 13;
const int ledRele = 12;
const int relePin = 9;
int incomingByte;
int val = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(ledSonsor, OUTPUT);
  pinMode(sensorMovimentoPIR, INPUT);
  pinMode(relePin, OUTPUT);
  digitalWrite(relePin, LOW);
}


float calculoTemperatura() {
  const float BETA = 3950; // Deve corresponder ao coeficiente beta do termistor
  int analogValue = analogRead(A0);
  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
  return celsius;
}

void loop() {
  float temperaturaExterna = calculoTemperatura();
  Serial.print("Temperatura Externa: ");
  Serial.println(temperaturaExterna);


  val = digitalRead(sensorMovimentoPIR);
  if (val == 1) {
    digitalWrite(ledSonsor, HIGH);
    digitalWrite(relePin, HIGH);
    digitalWrite(ledRele, HIGH);
    Serial.println("Movimento detectado!");
    if (temperaturaExterna > 10.00 && temperaturaExterna < 20.00) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temperatura:");
      lcd.setCursor(0, 1);
      lcd.print("24.00");
      delay(5000);
    } else if (temperaturaExterna > 20.01 && temperaturaExterna < 25.00) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temperatura:");
      lcd.setCursor(0, 1);
      lcd.print("21.00");
      delay(5000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temperatura:");
      lcd.setCursor(0, 1);
      lcd.print("24.00");
      delay(5000);
    } else if (temperaturaExterna > 25.01 && temperaturaExterna < 32.00) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temperatura:");
      lcd.setCursor(0, 1);
      lcd.print("19.00");
      delay(5000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temperatura:");
      lcd.setCursor(0, 1);
      lcd.print("24.00");
      delay(5000);
    } else if (temperaturaExterna >= 32.01) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temperatura:");
      lcd.setCursor(0, 1);
      lcd.print("17.00");
      delay(5000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temperatura:");
      lcd.setCursor(0, 1);
      lcd.print("24.00");
      delay(5000);
    }
  } else {
    Serial.println("Nenhum movimento na sala!");
    digitalWrite(ledSonsor, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("AC Desligado");
    digitalWrite(ledRele, LOW);
    digitalWrite(relePin, LOW);
    delay(1000);
  }

}
