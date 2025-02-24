# 🤖 Controle de Robô com ESP32 via Wi-Fi  

Este projeto permite controlar um **robô motorizado** utilizando um **ESP32** configurado como **Access Point (AP)**. O ESP32 cria uma rede Wi-Fi própria, permitindo que um usuário envie **comandos HTTP** para movimentar o robô em diferentes direções.  

## 📌 Funcionalidades  

- ✅ Criar um **Access Point (AP)** com um nome de rede definido pelo usuário.  
- ✅ Iniciar um **servidor HTTP** para receber comandos de movimento.  
- ✅ Controlar o **direcionamento dos motores** do robô.  
- ✅ Permitir movimentação em **8 direções** diferentes + parada.  

## 🚀 Como Funciona  

| Etapa | Descrição |
|-------|-----------|
| **1. Configuração da Rede Wi-Fi** | O ESP32 cria um **Access Point** (AP) com um **SSID definido pelo usuário**. |
| **2. Servidor Web** | O ESP32 inicia um **servidor HTTP** na porta **80** para receber comandos de movimento. |
| **3. Comandos de Movimento** | O ESP32 interpreta o parâmetro `State` enviado pela requisição HTTP e executa a ação correspondente. |

## ⚠️ **Atenção: Personalize o Nome da Rede (SSID)**  

O **nome da rede Wi-Fi** precisa ser **definido manualmente** no código.  
Para modificar o **SSID**, edite a seguinte linha no `setup()`:

```cpp
String ssid = "miniMachine"; // Defina o nome da rede aqui

## 🎮 Comandos Disponíveis  

| Comando | Movimento |
|---------|------------------------|
| `F`     | Frente                 |
| `B`     | Trás                   |
| `R`     | Virar Direita          |
| `L`     | Virar Esquerda         |
| `G`     | Frente + Esquerda      |
| `I`     | Frente + Direita       |
| `H`     | Trás + Esquerda        |
| `J`     | Trás + Direita         |
| `S`     | Parar                  |

## ⚙️ Estrutura do Código  

| Componente | Descrição |
|------------|-------------|
| **Definição dos Pinos** | Pinos configurados para controle da direção e velocidade dos motores. |
| **Geração do SSID** | O nome da rede Wi-Fi inclui o Chip ID (`ESP32_ROBOT_<CHIP_ID>`). |
| **Funções de Movimento** | Cada função ativa ou desativa os pinos corretos para realizar o movimento desejado. |
| **Servidor Web** | O servidor recebe requisições HTTP e interpreta o valor do parâmetro `State`. |
| **Loop Principal** | O servidor monitora constantemente novos comandos e executa as ações do robô. |

## 🛠️ Como Usar  

| Passo | Ação |
|-------|---------------------------|
| **1** | Ligue o ESP32 e conecte-se à rede Wi-Fi **"ESP32_ROBOT_<CHIP_ID>"**. |
| **2** | Acesse o IP **`192.168.4.1`** no navegador. |
| **3** | Envie comandos via requisição HTTP para controlar o robô. |

🔧 **Dica:** Esse código pode ser expandido para incluir sensores ou controle remoto via aplicativo. 🚀
