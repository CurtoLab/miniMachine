#include <WiFi.h>
#include <WebServer.h>

// Definições dos pinos do ESP32
int IN1 = 5;  // Pino de controle do motor A
int IN2 = 18; // Pino de controle do motor B
int IN3 = 19; // Pino de controle da velocidade do motor A
int IN4 = 21; // Pino de controle da velocidade do motor B

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
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void Backward() // Função de controle do robô para trás

{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void TurnRight() // Função de controle do robô para direita

{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void TurnLeft() // Função de controle do robô para esquerda
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void ForwardLeft() // Função de controle do robô para frente e esquerda
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void ForwardRight() // Função de controle do robô para frente e direita
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void BackwardLeft() // Função de controle do robô para trás e esquerda
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void BackwardRight() // Função de controle do robô para trás e direita
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void Stop() // Função de controle do robô parar
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup()
{
  Serial.begin(115200); // Inicializa a comunicação serial
  //** Definição do nome da rede **//
  String ssid = "miniMachine";

  pinMode(IN1, OUTPUT);   // Define os pinos como saída
  pinMode(IN2, OUTPUT);   // Define os pinos como saída
  pinMode(IN3, OUTPUT);   // Define os pinos como saída
  pinMode(IN4, OUTPUT);   // Define os pinos como saída
  digitalWrite(IN1, LOW); // Inicializa os pinos em nível baixo
  digitalWrite(IN2, LOW); // Inicializa os pinos em nível baixo
  digitalWrite(IN3, LOW); // Inicializa os pinos em nível baixo
  digitalWrite(IN4, LOW); // Inicializa os pinos em nível baixo

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