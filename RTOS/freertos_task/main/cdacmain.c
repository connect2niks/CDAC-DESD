# include <stdio.h>
#include "freertos/FreeRTOS.h"
# include "freertos/task.h"
#include "pthread.h"

// portTICK_PERIOD_MS => Tick for 1 ms

TaskHandle_t serial_task_handle,ether_handle;

void serial_task(void *data)
{
    UBaseType_t prio;
    while(1)
    {
        prio = uxTaskPriorityGet(serial_task_handle);
        printf("Serial Task : Started %d\n",prio);
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
    vTaskDelete(serial_task_handle);
}

void ethernet_task(void *data)
{
    UBaseType_t prio;
    while(1)
    {
        prio = uxTaskPriorityGet(ether_handle);
        printf("ether Task : Started %d\n",prio);
        vTaskDelay(1000 / portTICK_PERIOD_MS);

    }
    vTaskDelete(serial_task_handle);
}

void app_main()
{
    BaseType_t res;
    UBaseType_t mt_prio;

    printf("MT: DESD RTOS Project\n");
    mt_prio = uxTaskPriorityGet(NULL); 
    printf("Main Thread: Task Created Successfully :prio : %d\n",mt_prio);
       
    res = xTaskCreate(serial_task, "serial_task", 2048, NULL, 5, &serial_task_handle);
    res = xTaskCreate(ethernet_task, "ethernet_task", 2048, NULL, 8, &ether_handle);
/*Higher priority task take the control and lower priority task never get the CPU and it is in 
starving state.
if the priorities of the tasks is same then the scheduling algorithm is change to 
something called as ROUND ROBIN means for sometime one task is executed and then other execute 
for sometime.
*/

}