# include <stdio.h>
#include "freertos/FreeRTOS.h"
# include "freertos/task.h"

TaskHandle_t serial_task_handle;

void serail_task(void *data)
{
    printf("Serial Task : Started\n");

}
void app_main()
{
    BaseType_t res;
    printf("Main Thread:DESD RTOS Project\n");

    res = xTaskCreate(serail_task,"serail_task",2048,NULL,5,&serial_task_handle);

    if(res == pdPASS)
    {
        printf("MT:Task Created successfully\n");
    }
}