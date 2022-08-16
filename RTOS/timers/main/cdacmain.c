#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"
#include "pthread.h"


// portTICK_PERIOD_MS => Tick for 1 ms

TaskHandle_t serial_task_handle;
TimerHandle_t serial_timer_handle;

void serial_timer_callback(TimerHandle_t xTimer)
{
    printf("timer fired\n");
}

void serial_task(void *data)
{
    printf("starting the serial task\n");

    printf("creating the timer\n");

    serial_timer_handle = xTimerCreate("one_shot_timer", 5000/portTICK_PERIOD_MS, pdTRUE, 0, serial_timer_callback);
    
    printf("starting the timer\n");
    xTimerStart(serial_timer_handle, 0);
    vTaskDelete(serial_task_handle);
    
    //vTaskDelay(1000/portTICK_PERIOD_MS)
}


void app_main()
{
    BaseType_t res;
    UBaseType_t mt_prio;

    printf("MT: DESD RTOS Project\n");
    mt_prio = uxTaskPriorityGet(NULL); 
    printf("Main Thread: Task Created Successfully :prio : %d\n",mt_prio);
       
    res = xTaskCreate(serial_task, "serial_task", 2048, NULL, 5, &serial_task_handle);
/*Higher priority task take the control and lower priority task never get the CPU and it is in 
starving state.
if the priorities of the tasks is same then the scheduling algorithm is change to 
something called as ROUND ROBIN means for sometime one task is executed and then other execute 
for sometime.
*/

}