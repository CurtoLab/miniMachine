# 🤖 miniMachineBLE

Controle seu robô miniMachine via **Bluetooth Low Energy (BLE)** usando ESP32!

---

## ✨ Funcionalidades

- Cria um serviço BLE customizado para comandos de movimento
- Recebe comandos de apps BLE (ex: nRF Connect, aplicativos próprios)
- Movimentação em 8 direções + parada
- Fácil integração com automações e apps mobile

---

## 🎮 Comandos BLE

Envie um caractere para o serviço BLE:

| Comando | Movimento           |
|:-------:|:-------------------:|
| `F`     | Frente              |
| `B`     | Trás                |
| `R`     | Direita             |
| `L`     | Esquerda            |
| `G`     | Frente + Esquerda   |
| `I`     | Frente + Direita    |
| `H`     | Trás + Esquerda     |
| `J`     | Trás + Direita      |
| `S`     | Parar               |

---

## ⚡ Como Usar

1. Faça upload do código para o ESP32.
2. Ligue o robô e procure pelo serviço BLE chamado **miniMachineBLE**.
3. Conecte-se usando um app BLE e envie os comandos acima.
4. O robô irá executar o movimento correspondente!

---

## 📂 Arquivos

- `miniMachineBLE.ino` — Código principal do robô BLE
- `miniMachineBLE.cpp` / `.h` — Implementação das funções BLE

---

## 💡 Dicas

- Use o app [nRF Connect](https://play.google.com/store/apps/details?id=no.nordicsemi.android.mcp) para testar rapidamente.
- Personalize o nome do serviço BLE alterando a variável `bleServerName` no código.

---

Feito com ❤️ para makers e entusiastas de robótica!