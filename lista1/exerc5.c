/*05) Faça um código onde lê os dados analógicos capturados em um potenciômetro
  e apresente na saída serial*/


#include <Wire.h>// Biblioteca utilizada para fazer a comunicação com o I2C
#include <LiquidCrystal_I2C.h> // Biblioteca utilizada para fazer a comunicação com o display 

#define coluna 16
#define linha  2
#define endereco 0x27
// Chamada da funcação LiquidCrystal para ser usada com o I2C
LiquidCrystal_I2C lcd(endereco, coluna, linha);

int potencia;
float tensao;

#define led 2

void setup() {
  Serial.begin(115200);
  pinMode(led, INPUT);
  lcd.init();
  lcd.setBacklight(HIGH);
}

void loop() {
  lcd.setCursor(0, 0);
  potencia = analogRead(led);
  tensao = (3, 3 * potencia / 4095);
  lcd.setCursor(0, 0);
  lcd.print("Poten:");
  lcd.setCursor(7, 0);
  lcd.println(potencia);
  lcd.setCursor(0, 1);
  lcd.print("Tensao:");  
  lcd.setCursor(8, 1);
  lcd.println(tensao);
  delay(10);
}
