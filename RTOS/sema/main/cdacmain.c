#include <stdio.h>
#include "freertos/FreeRTOS.h"
# include "freertos/task.h"
#include "pthread.h"
#include "freertos/semphr.h"

// portTICK_PERIOD_MS => Tick for 1 ms

TaskHandle_t adc_task_handle, processing_task_handle;
SemaphoreHandle_t adc_handle ;

void adc_task(void *data)
{
    printf("ADC Task : Started\n");
    vTaskDelay(5000/portTICK_PERIOD_MS);
    xSemaphoreGive(adc_handle);
    printf("ADC Task : Posted signal to processing task\n");
    vTaskDelete(NULL);
}

void processing_task(void *data)
{
    printf("Processing Task : Started\n");
    xSemaphoreTake(adc_handle,0);
    printf("Processing Task : Got the signal\n"); 
    vTaskDelete(NULL);
}

void app_main()
{
    BaseType_t res;
    UBaseType_t mt_prio;

    printf("MT: DESD RTOS Project\n");
    mt_prio = uxTaskPriorityGet(NULL); 
    printf("Main Thread: Task Created Successfully :prio : %d\n",mt_prio);
       
    adc_handle = xSemaphoreCreateBinary();   
    res = xTaskCreate(adc_task, "adc_task", 2048, NULL, 5, &adc_task_handle);
    res = xTaskCreate(processing_task, "processing_task", 2048, NULL, 5, &processing_task_handle);

}