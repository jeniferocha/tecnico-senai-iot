#include<WiFi.h>
#include<ESPping.h>

const char* rede = "Wokwi-GUEST";
const char* senha = "";
const char* url = "www.google.com";

                  //Status wi-fi: 6 conectando
                  //status wi-fi 3 conectado
                  //WL_CONNECTED == 3

void setup() {
  Serial.begin(115200);

  //conectando com o wifi
  Serial.println("Iniciando conexao WiFi...");
  WiFi.begin(rede, senha);
  Serial.println(WL_CONNECTED);
  Serial.println(WiFi.status());

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("Conectando");

}

void loop() {

  bool fezPing = Ping.ping(url);
  if (fezPing) {
    Serial.println("Conectado!!");
  } else {
    Serial.println("Desconectado.");
  }

}
