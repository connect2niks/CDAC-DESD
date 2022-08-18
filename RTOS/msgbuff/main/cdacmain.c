#include <stdio.h>
#include "freertos/FreeRTOS.h"
# include "freertos/task.h"
#include "pthread.h"
#include "freertos/message_buffer.h"

// portTICK_PERIOD_MS => Tick for 1 ms

TaskHandle_t task1handle, task2handle, task3handle, task4handle;
MessageBufferHandle_t mb_t1_t2;

void task1 (void *data)
{
    printf("Task 1 : Started\n");
    printf("Task 1 sending message\n");
    xMessageBufferSend(mb_t1_t2, "1st data\n", 10, pdMS_TO_TICKS(20000));
    xMessageBufferSend(mb_t1_t2, "2nd data\n", 10, pdMS_TO_TICKS(20000));
    xMessageBufferSend(mb_t1_t2, "3rd data\n", 10, pdMS_TO_TICKS(20000));
    printf("Task 1 finished sending message\n");
    vTaskDelete(NULL);
}

void task2 (void *data)
{
    unsigned char buff [200];
    size_t nbytes;
    printf("Task 2 : Started\n");
    while(1)
    {
        printf("Task 2 requesting data to be received\n");
        nbytes = xMessageBufferReceive(mb_t1_t2, buff, 200, pdMS_TO_TICKS(20000));
        printf("Task 2 received data (size in bytes):%s, %d bytes\n",buff,nbytes);
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
       
    mb_t1_t2 = xMessageBufferCreate(200);  
    res = xTaskCreate(task1, "task1", 2048, NULL, 8, &task1handle);
    res = xTaskCreate(task2, "task2", 2048, NULL, 8, &task2handle);
} 