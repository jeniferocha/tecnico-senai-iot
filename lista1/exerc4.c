//04) Imprima "Ola Mundo!!" em um display LCD.


#include <Wire.h>// Biblioteca utilizada para fazer a comunicação com o I2C
#include <LiquidCrystal_I2C.h> // Biblioteca utilizada para fazer a comunicação com o display 

#define coluna 16
#define linha  2
#define endereco 0x27 
// Chamada da funcação LiquidCrystal para ser usada com o I2C
LiquidCrystal_I2C lcd(endereco, coluna, linha);



void setup() {
  lcd.init();
  lcd.begin(16, 2);  
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("Hello, world!");
  delay(1000); 
}

void loop() {
 

}
