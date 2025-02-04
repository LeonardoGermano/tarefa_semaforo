#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// Definição dos pinos dos LEDs
#define LED_RED 11
#define LED_YELLOW 12
#define LED_GREEN 13

// Variável para rastrear o estado atual do semáforo
int estado = 0;

// Função callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Desliga todos os LEDs antes de ativar o próximo
    gpio_put(LED_RED, 0);
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_GREEN, 0);

    // Alterna entre os estados do semáforo
    if (estado == 0) {
        gpio_put(LED_RED, 1);
    } else if (estado == 1) {
        gpio_put(LED_YELLOW, 1);
    } else {
        gpio_put(LED_GREEN, 1);
    }

    // Atualiza estado para o próximo ciclo
    estado = (estado + 1) % 3;
    return true;
}

int main() {
    stdio_init_all();

    // Configuração dos pinos dos LEDs como saída
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);

    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);

    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Inicializa o temporizador com intervalo de 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (1) {
        printf("Semáforo em funcionamento...\n");
        sleep_ms(1000);  // Mensagem na porta serial a cada 1 segundo
    }
}
