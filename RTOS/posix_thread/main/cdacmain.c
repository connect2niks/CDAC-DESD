# include <stdio.h>
#include "freertos/FreeRTOS.h"
# include "freertos/task.h"
#include "pthread.h"

//TaskHandle_t serial_task_handle;

void *serial_task(void *data)
{
    while (1)
    {
        printf("Serial Task : Started\n");
    }
    
    

}
void app_main()
{
    //BaseType_t res;
    printf("Main Thread:DESD RTOS Project\n");
    pthread_t sid;
    pthread_create(&sid, NULL, serial_task, NULL);
    pthread_join(sid, NULL);

   /* res = xTaskCreate(serail_task,"serail_task",2048,NULL,5,&serial_task_handle);

    if(res == pdPASS)
    {
        printf("MT:Task Created successfully\n");
    }
    */


}