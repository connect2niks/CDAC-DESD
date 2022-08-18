#include <stdio.h>
#include "freertos/FreeRTOS.h"
# include "freertos/task.h"
#include "pthread.h"
#include "freertos/semphr.h"

// portTICK_PERIOD_MS => Tick for 1 ms

TaskHandle_t task1handle, task2handle, task3handle, task4handle;
SemaphoreHandle_t serial_counting_sem;

void task1 (void *data)
{
    printf("Task 1 : Started\n");
    printf("Task 1 request for the serial port\n");
    xSemaphoreTake(serial_counting_sem,pdMS_TO_TICKS(20000));
    printf("Task 1 got the serial port\n");
    vTaskDelay(10000/portTICK_PERIOD_MS);
    xSemaphoreGive(serial_counting_sem);
    printf("Task 1 release the serial port\n");
    vTaskDelete(NULL);
}

void task2 (void *data)
{
    printf("Task 2 : Started\n");
    printf("Task 2 request for the serial port\n");
    xSemaphoreTake(serial_counting_sem, pdMS_TO_TICKS(20000));
    printf("Task 2 got the serial port\n");
    vTaskDelay(2000/portTICK_PERIOD_MS);
    xSemaphoreGive(serial_counting_sem);
    printf("Task 2 release the serial port\n");
    vTaskDelete(NULL);
}
void task3 (void *data)
{
    printf("Task 3 : Started\n");
    printf("Task 3 request for the serial port\n");
    xSemaphoreTake(serial_counting_sem, pdMS_TO_TICKS(20000));
    printf("Task 3 got the serial port\n");
    vTaskDelay(3000/portTICK_PERIOD_MS);
    xSemaphoreGive(serial_counting_sem);
    printf("Task 3 release the serial port\n");
    vTaskDelete(NULL);
}
void task4 (void *data)
{
    printf("Task 4 : Started\n");
    printf("Task 4 request for the serial port\n");
    xSemaphoreTake(serial_counting_sem, pdMS_TO_TICKS(20000));
    printf("Task 4 got the serial port\n");
    vTaskDelay(8000/portTICK_PERIOD_MS);
    xSemaphoreGive(serial_counting_sem);
    printf("Task 4 release the serial port\n");
    vTaskDelete(NULL);
}

void app_main()
{
    BaseType_t res;
    UBaseType_t mt_prio;

    printf("MT: DESD RTOS Project\n");
    mt_prio = uxTaskPriorityGet(NULL); 
    printf("Main Thread: Task Created Successfully :prio : %d\n",mt_prio);
       
    serial_counting_sem = xSemaphoreCreateCounting(2,2);   
    res = xTaskCreate(task1, "task1", 2048, NULL, 8, &task1handle);
    res = xTaskCreate(task2, "task2", 2048, NULL, 8, &task2handle);
    res = xTaskCreate(task3, "task3", 2048, NULL, 8, &task3handle);
    res = xTaskCreate(task4, "task4", 2048, NULL, 8, &task4handle);

} 