# 🤖 Controle de Robô com ESP32 via Bluetooth Low Energy (BLE)

Este projeto permite controlar um **robô motorizado** utilizando um **ESP32** configurado como dispositivo **BLE**. O ESP32 cria um serviço BLE próprio, permitindo que um usuário envie **comandos via Bluetooth** para movimentar o robô em diferentes direções.

## 📌 Funcionalidades

- ✅ Cria um **serviço BLE** com nome definido pelo usuário.
- ✅ Recebe comandos BLE para movimentação do robô.
- ✅ Controla o **direcionamento dos motores** do robô.
- ✅ Permite movimentação em **8 direções** diferentes + parada.

## 🚀 Como Funciona

| Etapa | Descrição |
|-------|-----------|
| **1. Inicialização do BLE** | O ESP32 inicia um serviço BLE com um **nome definido pelo usuário**. |
| **2. Recepção de Comandos** | O ESP32 recebe comandos BLE enviados por um aplicativo ou dispositivo BLE. |
| **3. Comandos de Movimento** | O ESP32 interpreta o comando recebido e executa a ação correspondente nos motores. |

## ⚠️ **Atenção: Personalize o Nome do Serviço BLE**

O **nome do serviço BLE** pode ser **definido manualmente** no código.  
Para modificar, edite a seguinte linha no `setup()`:

```cpp
String bleServerName = "miniMachineBLE"; // Defina o nome do serviço BLE aqui
```

## ⚙️ Esquema de Ligações

| Pino ESP32 | Nome da Variável | Função                           | Descrição                      |
|------------|------------------|----------------------------------|--------------------------------|
| `22`        | `IN1`            | Controle de direção do Motor A   | Define o sentido do motor A    |
| `23`       | `IN2`            | Controle de direção do Motor B   | Define o sentido do motor B    |
| `12`       | `IN3`            | Controle de velocidade do Motor A| Controla a intensidade do motor A |
| `13`       | `IN4`            | Controle de velocidade do Motor B| Controla a intensidade do motor B |

## 🎮 Comandos Disponíveis

| Comando | Movimento           |
|---------|---------------------|
| `F`     | Frente              |
| `B`     | Trás                |
| `R`     | Virar Direita       |
| `L`     | Virar Esquerda      |
| `G`     | Frente + Esquerda   |
| `I`     | Frente + Direita    |
| `H`     | Trás + Esquerda     |
| `J`     | Trás + Direita      |
| `S`     | Parar               |

## ⚙️ Estrutura do Código

| Componente           | Descrição                                                                 |
|----------------------|--------------------------------------------------------------------------|
| **Definição dos Pinos**    | Pinos configurados para controle da direção e velocidade dos motores.      |
| **Funções de Movimento**   | Cada função ativa ou desativa os pinos corretos para realizar o movimento desejado. |
| **Serviço BLE**            | O ESP32 recebe comandos BLE e interpreta o valor recebido.                  |
| **Loop Principal**         | O ESP32 monitora constantemente novos comandos e executa as ações do robô.  |

## 🛠️ Como Usar

| Passo | Ação                                                                 |
|-------|----------------------------------------------------------------------|
| **1** | Ligue o ESP32 e procure pelo serviço BLE com o nome definido no código. |
| **2** | Conecte-se ao serviço BLE usando um aplicativo BLE (ex: nRF Connect). |
| **3** | Envie comandos para controlar o robô.                                 |

## 📦 Dependências

Para utilizar a **miniMachineBLE**, instale as seguintes bibliotecas pelo **Gerenciador de Bibliotecas** do Arduino IDE:

- [NimBLE-Arduino](https://github.com/h2zero/NimBLE-Arduino) (autor: h2zero)
- [ArduinoJson](https://github.com/bblanchon/ArduinoJson) (autor: Benoit Blanchon)

**Como instalar:**
1. Abra o Arduino IDE.
2. Vá em **Ferramentas > Gerenciar Bibliotecas...**
3. Pesquise por **NimBLE-Arduino** e instale.
4. Pesquise por **ArduinoJson** e instale.

Pronto! Agora você pode usar a **miniMachineBLE** para controlar seu robô via Bluetooth Low Energy (BLE).
