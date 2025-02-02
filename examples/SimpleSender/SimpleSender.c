#include <stdio.h>
#include <stdint.h>
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/ledc.h"
#include "irsnd.h"

#define IR_SEND_PERIOD_US   (1000000 / F_INTERRUPTS)

IRMP_DATA irmp_data;

esp_timer_handle_t ir_send_task_handle;

void app_main(void)
{   
    irsnd_init();
    esp_timer_create_args_t ir_send_timer_args;
    ir_send_timer_args.callback = (void*) &irsnd_ISR;
    ir_send_timer_args.name = "irsnd_ISR";
    esp_timer_create(&ir_send_timer_args, &ir_send_task_handle);
    esp_timer_start_periodic(ir_send_task_handle, IR_SEND_PERIOD_US);

    while (1)
    {
        irmp_data.protocol = IRMP_NEC_PROTOCOL;                             // use NEC protocol
        irmp_data.address  = 0x00FF;                                        // set address to 0x00FF
        irmp_data.command  = 0x0001;                                        // set command to 0x0001
        irmp_data.flags    = 0;                                             // don't repeat frame

        irsnd_send_data (&irmp_data, TRUE);                                 // send frame, wait for completion
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
