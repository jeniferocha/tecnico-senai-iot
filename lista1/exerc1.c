/* 01) Elabore um programa em que o dispositivo solicita ao usuário que insira seu
  nome. Após a entrada do nome pelo usuário, o programa deve exibir uma
  mensagem de boas-vindas, incluindo o nome fornecido, através da saída serial*/


void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("Digite seu nome:" );



}

void loop() {
  while (Serial.available() == 0) {
    delay(100);
  }

  String nome = Serial.readString();

  Serial.print("Bem-vindo, ");
  Serial.println(nome);
}


