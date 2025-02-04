#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED_PIN GPIO_NUM_2  // Defina o pino do LED

void blink_led() {
    for (int i = 0; i < 3; i++) {
        gpio_set_level(LED_PIN, 1);  // Liga o LED
        vTaskDelay(pdMS_TO_TICKS(3000));  // Aguarda 500ms
        gpio_set_level(LED_PIN, 0);  // Desliga o LED
        vTaskDelay(pdMS_TO_TICKS(200));  // Aguarda 500ms

    }
    vTaskDelete(NULL); // Encerra a task após piscar 3 vezes
}

void app_main() {
    // Configura o pino do LED como saída
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);

    // Cria uma task para piscar o LED
    xTaskCreate(blink_led, "blink_led", 1024, NULL, 1, NULL);
}
    
    by chatgpt 