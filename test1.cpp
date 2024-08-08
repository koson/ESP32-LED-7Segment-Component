#include <stdio.h>
#include "LED.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

LED seg_a(16);
LED seg_b(17);
LED seg_c(5);
LED seg_d(18);
LED seg_e(19);
LED seg_f(21);
LED seg_g(22);
LED digit_1(0);
LED digit_2(4);


void HardwareTest()
{
    digit_1.ON();
    digit_2.OFF();    
    seg_a.ON();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_b.ON();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_c.ON();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_d.ON();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_e.ON();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_f.ON();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_g.ON();
    vTaskDelay(500/portTICK_PERIOD_MS);
 
 

    vTaskDelay(500/portTICK_PERIOD_MS);
    digit_1.OFF(); 
    digit_2.ON(); 
    vTaskDelay(500/portTICK_PERIOD_MS);

    seg_a.OFF();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_b.OFF();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_c.OFF();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_d.OFF();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_e.OFF();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_f.OFF();
    vTaskDelay(500/portTICK_PERIOD_MS);
    seg_g.OFF();
    vTaskDelay(500/portTICK_PERIOD_MS);
}

extern "C" void app_main(void)
{

    while(1)
    {
        HardwareTest();
        vTaskDelay(500/portTICK_PERIOD_MS);
    } 

}