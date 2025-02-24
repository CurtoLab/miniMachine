# 🚀 Controle de Robô com ESP32 via Wi-Fi  

Este projeto utiliza um **ESP32** configurado como **Access Point (AP)** para receber comandos via **servidor HTTP** e controlar um robô. A comunicação ocorre através de requisições HTTP contendo comandos que definem o movimento do robô.  

## 📌 Como Funciona  

| Etapa | Descrição |
|-------|-----------|
| **1. Configuração da Rede Wi-Fi** | O ESP32 é configurado como Access Point (AP) com um **SSID único** baseado no Chip ID. |
| **2. Servidor Web** | Um servidor HTTP é iniciado na porta **80** para receber comandos. |
| **3. Comandos de Movimento** | O ESP32 interpreta o parâmetro `State` da requisição HTTP e executa a ação correspondente. |

## 📡 Nome da Rede (SSID)  

O nome da rede agora inclui o **Chip ID do ESP32**, tornando cada AP único.  
O formato do SSID gerado será:

Por exemplo, se o **Chip ID** for `126F2812`, o **SSID** da rede Wi-Fi será:

Isso garante que múltiplos ESP32 não entrem em conflito na mesma rede.

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
