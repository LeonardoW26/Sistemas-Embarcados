#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#define LED_PIN_1 11
#define LED_PIN_2 12

//Prototipos de tarefas
void TaskBlink1(void *pvParameters);
void TaskBlink2(void *pvParameters);

void setup (){

//inicializar os pinos dos LES como saidas
pinMode(LED_PIN_1, OUTPUT);
pinMode(LED_PIN_2, OUTPUT);

//cria as tarefas
xTaskCreate(
    TaskBlink1, //função da tarefas - Ponteiro
    "Blink1",
    128, //tamanho da pilha
    NULL, //Parametro da Tarefa
    2, //prioridade - numeros mais altos - proporcional ao numero
    NULL ); //agendar tarefa

    xTaskCreate(
    TaskBlink2, //função da tarefas - Ponteiro
    "Blink2",
    128, //tamanho da pilha
    NULL, //Parametro da Tarefa
    1, //prioridade - numeros mais altos - proporcional ao numero
    NULL ); //agendar tarefa
}

void loop (){
//nada aqui
}

void TaskBlink1(void *pvParameters){
    (void) pvParameters;
    for (;;){//loop infinito
        digitalWrite(LED_PIN_1, HIGH);
        vTaskDelay(1000 / portTICK_PERIOD_MS); //
        digitalWrite(LED_PIN_1, LOW);
        vTaskDelay(1000 / portTICK_PERIOD_MS); //
    }
}

void TaskBlink2(void *pvParameters){
    (void) pvParameters;
    for (;;){//loop infinito
        digitalWrite(LED_PIN_2, HIGH);
        vTaskDelay(500 / portTICK_PERIOD_MS); //
        digitalWrite(LED_PIN_2, LOW);
        vTaskDelay(500 / portTICK_PERIOD_MS); //
    }
}