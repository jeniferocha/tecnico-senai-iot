/*02) Desenvolva um sistema de alarme utilizando um sensor PIR para detectar
  movimento. Quando movimento é detectado, o sistema deve acionar um buzzer*/

int pinoPIR = 9;
int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(pinoPIR, INPUT);
}

void loop() {
  val = digitalRead(pinoPIR);
  if (val == 1) {
    tone(12, 262, 250); // Toca um tom de 262Hz por 0,250 segundos
    Serial.println("Movimento detectado!");
    delay(500);
  } else {
    Serial.println("Nenhum movimento!");
    delay(500);
  }
}

