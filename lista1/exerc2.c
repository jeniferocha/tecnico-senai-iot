// 02) Faça um LED piscar a cada segundo na ESP32 usando a linguagem C.

int led = 26;


void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);
}

void loop() {
  digitalWrite(led, HIGH);
  delay(300);
  digitalWrite(led, LOW);
  delay(700);
}
