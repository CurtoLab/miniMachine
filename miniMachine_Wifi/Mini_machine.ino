#include <WiFi.h>
#include <WebServer.h>

// Definições dos pinos do ESP32
int DIR_A = 5;  // Pino de controle do motor A
int DIR_B = 18; // Pino de controle do motor B
int TA = 19;    // Pino de controle da velocidade do motor A
int TB = 21;    // Pino de controle da velocidade do motor B

String command;

WebServer server(80);

void HTTP_handleRoot() // Função de controle
{
  server.send(200, "text/html", "");
  if (server.hasArg("State"))
  {
    Serial.println(server.arg("State"));
  }
}

void Forward() // Função de controle do robô para frente
{
  digitalWrite(DIR_A, HIGH);
  digitalWrite(DIR_B, LOW);
  digitalWrite(TA, LOW);
  digitalWrite(TB, HIGH);
}

void Backward() // Função de controle do robô para trás

{
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, HIGH);
  digitalWrite(TA, HIGH);
  digitalWrite(TB, LOW);
}

void TurnRight() // Função de controle do robô para direita

{
  digitalWrite(DIR_A, HIGH);
  digitalWrite(DIR_B, LOW);
  digitalWrite(TA, HIGH);
  digitalWrite(TB, LOW);
}

void TurnLeft() // Função de controle do robô para esquerda
{
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, HIGH);
  digitalWrite(TA, LOW);
  digitalWrite(TB, HIGH);
}

void ForwardLeft() // Função de controle do robô para frente e esquerda
{
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, LOW);
  digitalWrite(TA, LOW);
  digitalWrite(TB, HIGH);
}

void ForwardRight() // Função de controle do robô para frente e direita
{
  digitalWrite(DIR_A, HIGH);
  digitalWrite(DIR_B, LOW);
  digitalWrite(TA, LOW);
  digitalWrite(TB, LOW);
}

void BackwardLeft() // Função de controle do robô para trás e esquerda
{
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, HIGH);
  digitalWrite(TA, LOW);
  digitalWrite(TB, LOW);
}

void BackwardRight() // Função de controle do robô para trás e direita
{
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, LOW);
  digitalWrite(TA, HIGH);
  digitalWrite(TB, LOW);
}

void Stop() // Função de controle do robô parar
{
  digitalWrite(DIR_A, LOW);
  digitalWrite(DIR_B, LOW);
  digitalWrite(TA, LOW);
  digitalWrite(TB, LOW);
}

void setup()
{
  Serial.begin(115200); // Inicializa a comunicação serial
  //** Definição do nome da rede **//
  String ssid = "miniMachine";

  pinMode(DIR_A, OUTPUT);   // Define os pinos como saída
  pinMode(DIR_B, OUTPUT);   // Define os pinos como saída
  pinMode(TA, OUTPUT);      // Define os pinos como saída
  pinMode(TB, OUTPUT);      // Define os pinos como saída
  digitalWrite(DIR_A, LOW); // Inicializa os pinos em nível baixo
  digitalWrite(DIR_B, LOW); // Inicializa os pinos em nível baixo
  digitalWrite(TA, LOW);    // Inicializa os pinos em nível baixo
  digitalWrite(TB, LOW);    // Inicializa os pinos em nível baixo

  Serial.println("Conectando ao WiFi..."); // Mensagem de conexão
  WiFi.mode(WIFI_AP);                      // Modo de conexão
  WiFi.softAP(ssid.c_str());               // Nome da rede
  Serial.println("\nModo AP ativado!");    // Mensagem de conexão
  Serial.print("IP AP: ");                 // Mensagem de conexão do IP
  Serial.println(WiFi.softAPIP());         // Mensagem de conexão do IP
  server.on("/", HTTP_handleRoot);         // Função de controle
  server.onNotFound(HTTP_handleRoot);      // Função de controle
  server.begin();                          // Inicializa o servidor
}

void loop()
{
  server.handleClient();         // Função de controle para manter o server rodando
  command = server.arg("State"); // Função de controle para receber o comando
  if (command == "F")
    Forward();
  else if (command == "B")
    Backward();
  else if (command == "R")
    TurnRight();
  else if (command == "L")
    TurnLeft();
  else if (command == "G")
    ForwardLeft();
  else if (command == "H")
    BackwardLeft();
  else if (command == "I")
    ForwardRight();
  else if (command == "J")
    BackwardRight();
  else if (command == "S")
    Stop();
}