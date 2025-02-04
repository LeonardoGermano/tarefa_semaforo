# Atividade 1: Temporizador Periódico (Semáforo)

## Descrição
Este projeto implementa um semáforo utilizando a Raspberry Pi Pico W e a biblioteca Pico SDK. O semáforo alterna entre os LEDs vermelho, amarelo e verde a cada 3 segundos usando um temporizador periódico (`add_repeating_timer_ms()`).

## Componentes Necessários
- Raspberry Pi Pico W
- 3 LEDs (Vermelho, Amarelo e Verde)
- 3 Resistores de 330 Ω


## Como Funciona
1. O código inicia com o LED vermelho ligado.
2. A cada 3 segundos, ele alterna para o próximo LED (amarelo, verde e retorna ao vermelho).
3. O estado do semáforo é atualizado na função callback do temporizador.
4. O sistema imprime uma mensagem na porta serial a cada segundo.

## Como Executar
1. Configure o ambiente de desenvolvimento no VS Code com o Pico SDK.
2. Clone este repositório e compile o código.
3. Conecte a Raspberry Pi Pico e envie o binário compilado.
4. Abra um monitor serial para visualizar as mensagens.

## Vídeo Demonstrativo
[---]

