#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_2  // Pino do LED (ajuste conforme necessário)

void blink_led(int duration) {
    gpio_set_level(LED_PIN, 1);
    vTaskDelay(pdMS_TO_TICKS(duration));
    gpio_set_level(LED_PIN, 0);
    vTaskDelay(pdMS_TO_TICKS(300)); // Pequeno intervalo entre os sinais
}

void sos_signal() {
    // Código Morse para SOS: ... --- ...
    int dot = 200;  // Duração do ponto (.)
    int dash = 600; // Duração do traço (-)
    
    for (int i = 0; i < 3; i++) blink_led(dot);  // S: ...
    vTaskDelay(pdMS_TO_TICKS(300));  // Pequeno intervalo entre letras
    for (int i = 0; i < 3; i++) blink_led(dash); // O: ---
    vTaskDelay(pdMS_TO_TICKS(300));  // Pequeno intervalo entre letras
    for (int i = 0; i < 3; i++) blink_led(dot);  // S: ...
    
    vTaskDelay(pdMS_TO_TICKS(3000)); // Pausa maior entre repetições do SOS
}

void app_main(void) {
    // Configura o pino do LED como saída
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
    
    while (1) {
        sos_signal(); // Repetir o sinal SOS continuamente
        vTaskDelay(pdMS_TO_TICKS(1000)); // Pausa antes de repetir
    }
}
// codigo elaborado pelo chatgpt
