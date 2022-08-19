#include <stdio.h>
#include "freertos/FreeRTOS.h"
# include "freertos/task.h"
#include "pthread.h"
#include "freertos/event_groups.h"
#include "freertos/queue.h"


#define MQ_SIZE 4
#define MSG_SIZE 64

//char stat_buffer[4096];

// portTICK_PERIOD_MS => Tick for 1 ms

TaskHandle_t pressure_task1handle, temp_task2handle, processing_task3handle;
//QueueHandle_t sensor_q;
EventGroupHandle_t sensor_ef;

void pressure_task1 (void *data)
{
    int pdata = 200;
    printf("pressure_task1 : Started\n");
    while (1)
    {
        pdata++;
        //send the data in the queue
        //xQueueSend(sensor_q, &pdata, pdMS_TO_TICKS(5000));
        // set the event
        xEventGroupSetBits( sensor_ef,(1 << 0));
        printf("pressure task : setting bit --> event generated\n");
        vTaskDelay(pdMS_TO_TICKS(5000));
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
        //xQueueSend(sensor_q, &tdata, pdMS_TO_TICKS(5000));
        // set the event
        xEventGroupSetBits( sensor_ef,(1 << 1));
        printf("temperature task : setting bit --> event generated\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
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
        //xQueueReceive(sensor_q, &buff, portMAX_DELAY);
        // wait for the event 

        xEventGroupWaitBits(sensor_ef,(1<<0)|(1<<1),pdTRUE,pdTRUE,portMAX_DELAY);

        printf("Processing task : Data Received\n");
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
    //sensor_q = xQueueCreate(MQ_SIZE,MSG_SIZE);   
  
    sensor_ef = xEventGroupCreate();
  
    res = xTaskCreate(pressure_task1, "pressure_task1", 2048, NULL, 8, &pressure_task1handle);
    res = xTaskCreate(temp_task2, "temp_task2", 2048, NULL, 8, &temp_task2handle);
    res = xTaskCreate(processing_task3, "processing_task3", 2048, NULL, 8, &processing_task3handle);
/*
    while (1)
    {
        vTaskGetRunTimeStats(stat_buffer);
        printf("Stat Buffer :%s\n",stat_buffer);
        vTaskDelay(pdMS_TO_TICKS(5000));
    }
*/    
} 


