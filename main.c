/*
 * File:   main.c
 * Author: hossa
 *
 * Created on 25 ??????, 2023, 10:38 ?
 */

#define F_CPU 16000000UL

#include <avr/io.h>
#include "FreeRTOSConfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "mUART.h"

typedef struct{
    char x;
    char y;
    
}mData; 

void tF_1(void * anydata){
    
    char* pC = (char*) anydata;
    

    while(1){
        UART_send_str(pC);
        vTaskDelay(50);
    }
    
}
void tF_2(void * anydata){
    char *pC = (char *) anydata;
    
    while(1){
        UART_send_str(pC);
        vTaskDelay(50);

    }
    
}


int main(void) {
    /* Replace with your application code */
    
    mData para;
    para.x = 'A';
    para.y = 'B';
    
    init_UART(9600);
    char str1[]= "Task1 is running\r";
    char str2[]= "Task2 is running\r";
//    char x ='A';
//    char y ='B';
    xTaskCreate(tF_1, // Task Code
            "Task1",  // pcName
            100,      // StackDepth
            (void *)str1, // Data to function
            1,         // priority
            NULL       // Task Handler
            );
    xTaskCreate(tF_2,
            "Task2",
            100,
            (void *)str2,
            1,
            NULL
            );
    
    
    
    // Start Scheduler....
    vTaskStartScheduler();
    
    while (1);
}
