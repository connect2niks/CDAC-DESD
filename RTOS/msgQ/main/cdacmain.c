#include <stdio.h>
#include "freertos/FreeRTOS.h"
# include "freertos/task.h"
#include "pthread.h"
#include "freertos/queue.h"

#define MQ_SIZE 4
#define MSG_SIZE 64


// portTICK_PERIOD_MS => Tick for 1 ms

TaskHandle_t pressure_task1handle, temp_task2handle, processing_task3handle, highprio_task4handle;
QueueHandle_t sensor_q;
void pressure_task1 (void *data)
{
    int pdata = 200;
    printf("pressure_task1 : Started\n");
    while (1)
    {
        pdata++;
        //send the data in the queue
        xQueueSend(sensor_q, &pdata, pdMS_TO_TICKS(5000));
        vTaskDelay(pdMS_TO_TICKS(500));
    }
    
    vTaskDelete(NULL);
}

void temp_task2 (void *data)
{
    int tdata = 100;
    printf("temperature_task2 : Started\n");
    while (1)
    {
        tdata++;
        //send the data in the queue
        xQueueSend(sensor_q, &tdata, pdMS_TO_TICKS(5000));
        vTaskDelay(pdMS_TO_TICKS(100));
    }
    vTaskDelete(NULL);
}

void processing_task3 (void *data)
{
    int buff;
    printf("processing_task3 : Started\n");
    while (1)
    {
        //send the data in the queue
        xQueueReceive(sensor_q, &buff, portMAX_DELAY);
        printf("Processing task : Data Received : %d\n",buff);
    }
    vTaskDelete(NULL);
}

void highprio_task4 (void *data)
{
    int count = 0;
    int buff;
    printf("High prio_task4 : Started\n");
    while (1)
    {
        //Receive the data to the queue
        xQueueReceive(sensor_q, &buff, pdMS_TO_TICKS(1000));
        printf("High Prio:Data Received : %d\n",buff);
        count++;
        if (count > 50)
        {
            vTaskDelay(pdMS_TO_TICKS(10000));
        }
        
    }
    vTaskDelete(NULL);
}


void app_main()
{
    BaseType_t res;
    UBaseType_t mt_prio;

    printf("MT: DESD RTOS Project\n");
    mt_prio = uxTaskPriorityGet(NULL); 
    printf("Main Thread: Task Created Successfully :prio : %d\n",mt_prio);
       
    // creating queue
    sensor_q = xQueueCreate(MQ_SIZE,MSG_SIZE);   

    res = xTaskCreate(pressure_task1, "pressure_task1", 2048, NULL, 8, &pressure_task1handle);
    res = xTaskCreate(temp_task2, "temp_task2", 2048, NULL, 8, &temp_task2handle);
    res = xTaskCreate(processing_task3, "processing_task3", 2048, NULL, 8, &processing_task3handle);
    res = xTaskCreate(highprio_task4, "highprio_task4", 2048, NULL, 10, &highprio_task4handle);
} 


