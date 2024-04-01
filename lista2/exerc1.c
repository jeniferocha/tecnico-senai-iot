/*01) Utilize um sensor de temperatura (como o DHT11 ou DHT22) para monitorar a
temperatura em tempo real apresentando a temperatura e umidade na saída serial.*/


#include <DHT.h>; //INCLUSÃO DE BIBLIOTECA
 
#define DHTPIN 7 //PINO DIGITAL UTILIZADO PELO DHT22
#define DHTTYPE DHT22 //DEFINE O MODELO DO SENSOR (DHT22 / AM2302)
 
DHT dht(DHTPIN, DHTTYPE); //PASSA OS PARÂMETROS PARA A FUNÇÃO
 
void setup(){
  Serial.begin(9600); //INICIALIZA A SERIAL
  dht.begin(); //INICIALIZA A FUNÇÃO
  delay(2000); //INTERVALO DE 2 SEGUNDO ANTES DE INICIAR
}
void loop(){
    Serial.print("Umidade: "); //IMPRIME O TEXTO NA SERIAL
    Serial.print(dht.readHumidity()); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO
    Serial.print("%"); //IMPRIME O TEXTO NA SERIAL 
    Serial.print(" / Temperatura: "); //IMPRIME O TEXTO NA SERIAL
    Serial.print(dht.readTemperature(), 0); //IMPRIME NA SERIAL O VALOR DE UMIDADE MEDIDO E REMOVE A PARTE DECIMAL
    Serial.println("ºC"); //IMPRIME O TEXTO NA SERIAL
    delay(2000); //INTERVALO DE 2 SEGUNDOS * NÃO DIMINUIR ESSE VALOR
}