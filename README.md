## 📌 Como Funciona  

| Etapa | Descrição |
|-------|-----------|
| **1. Configuração da Rede Wi-Fi** | O ESP32 é configurado como Access Point (AP) com o nome `"ESP32_ROBOT"`. |
| **2. Servidor Web** | Um servidor HTTP é iniciado na porta **80** para receber comandos. |
| **3. Comandos de Movimento** | O ESP32 interpreta o parâmetro `State` da requisição HTTP e executa a ação correspondente. |

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
| **Funções de Movimento** | Cada função ativa ou desativa os pinos corretos para realizar o movimento desejado. |
| **Servidor Web** | O servidor recebe requisições HTTP e interpreta o valor do parâmetro `State`. |
| **Loop Principal** | O servidor monitora constantemente novos comandos e executa as ações do robô. |

## 🛠️ Como Usar  

| Passo | Ação |
|-------|---------------------------|
| **1** | Ligue o ESP32 e conecte-se à rede Wi-Fi **"ESP32_ROBOT"**. |
| **2** | Acesse o IP gerado pelo ESP32 no navegador. |
| **3** | Envie comandos via requisição HTTP para controlar o robô. |

🔧 **Dica:** Esse código pode ser expandido para incluir sensores ou controle remoto via aplicativo. 🚀
