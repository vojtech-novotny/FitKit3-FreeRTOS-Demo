/// @author Vojtěch Novotný - xnovot1f
/// @changes 50%
/// Implementation of LED blinking tasks as Deffered Interrupt Handler tasks.
///	Implementation of GPIO port E Interrupt Service Routine for buttons.
/// Program start.
/// @date 23.12.2019

/*
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    MK60DN512xxx10_Project.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK60D10.h"
#include "fsl_debug_console.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "timers.h"

// Taken from: Fitkit3 demo application.
// Edited by xnovot1f
// {
/* Mapping of LEDs and buttons to specific port pins: */
// Note: only D9, SW3 and SW5 are used in this sample app
#define LED_D9  0x20      // Port B, bit 5
#define LED_D10 0x10      // Port B, bit 4
#define LED_D11 0x8       // Port B, bit 3
#define LED_D12 0x4       // Port B, bit 2

#define BTN_SW2 0x400     // Port E, bit 10
#define BTN_SW3 0x1000    // Port E, bit 12
#define BTN_SW4 0x8000000 // Port E, bit 27
#define BTN_SW5 0x4000000 // Port E, bit 26
#define BTN_SW6 0x800     // Port E, bit 11

// Speaker is not used.
#define SPK 0x10          // Speaker is on PTA4
// }

// Priority used by all user created tasks. No need for multiple priorities.
#define task_PRIORITY (configMAX_PRIORITIES - 1)

// Clears all interrupt flags for GPIO port E
void prvClearInterruptSource(){
	//PORTB->ISFR = 0xFFFFFFFF;
	//NVIC_ClearPendingIRQ(PORTE_IRQn);
	GPIO_ClearPinsInterruptFlags(GPIOE, 0xFFFFFFFF);
}

// Deffered Interrupt Handler Task handles.
TaskHandle_t flash_D9_task_handler = NULL;
TaskHandle_t flash_D10_task_handler = NULL;
TaskHandle_t flash_D11_task_handler = NULL;
TaskHandle_t flash_D12_task_handler = NULL;

// Inicialization task.
// This task is probably not needed but I couldn't figure out
// what to change in pin_mux to make the default value 0.
// (it is set to 0 and they still start on...)
void led_init_task(void * pvParameters) {
	GPIOB->PDOR ^= LED_D9;
	GPIOB->PDOR ^= LED_D10;
	GPIOB->PDOR ^= LED_D11;
	GPIOB->PDOR ^= LED_D12;
	vTaskSuspend(NULL);
}

// Taken from: https://www.freertos.org/RTOS_Task_Notification_As_Counting_Semaphore.html
// Edited by xnovot1f
// {
void flash_D9_task(void * pvParameters) {
	const TickType_t xBlockTime = pdMS_TO_TICKS(20000);

	// Number of interrupts waiting.
	uint32_t ulNotifiedValue;

	for( ;; ) {
		// Wait for semaphore notification.
		ulNotifiedValue = ulTaskNotifyTake( pdFALSE, xBlockTime );

		if( ulNotifiedValue > 0 ) {
			// Blink led for 1 second.
			GPIOB->PDOR ^= LED_D9;
			vTaskDelay(pdMS_TO_TICKS(1000));
			GPIOB->PDOR ^= LED_D9;
		}
	}
}
// }

// Taken from: https://www.freertos.org/RTOS_Task_Notification_As_Counting_Semaphore.html
// Edited by xnovot1f
// {
void flash_D10_task(void * pvParameters) {
	const TickType_t xBlockTime = pdMS_TO_TICKS(20000);

	// Number of interrupts waiting.
	uint32_t ulNotifiedValue;

	for( ;; ) {
		// Wait for semaphore notification.
		ulNotifiedValue = ulTaskNotifyTake( pdFALSE, xBlockTime );

		if( ulNotifiedValue > 0 ) {
			// Blink led for 1 second.
			GPIOB->PDOR ^= LED_D10;
			vTaskDelay(pdMS_TO_TICKS(1000));
			GPIOB->PDOR ^= LED_D10;
		}
	}
}
// }

// Taken from: https://www.freertos.org/RTOS_Task_Notification_As_Counting_Semaphore.html
// Edited by xnovot1f
// {
void flash_D11_task(void * pvParameters) {
	const TickType_t xBlockTime = pdMS_TO_TICKS(20000);

	// Number of interrupts waiting.
	uint32_t ulNotifiedValue;

	for( ;; ) {
		// Wait for semaphore notification.
		ulNotifiedValue = ulTaskNotifyTake( pdFALSE, xBlockTime );

		if( ulNotifiedValue > 0 ) {
			// Blink led for 1 second.
			GPIOB->PDOR ^= LED_D11;
			vTaskDelay(pdMS_TO_TICKS(1000));
			GPIOB->PDOR ^= LED_D11;
		}
	}
}
// }

// Taken from: https://www.freertos.org/RTOS_Task_Notification_As_Counting_Semaphore.html
// Edited by xnovot1f
// {
void flash_D12_task(void * pvParameters) {
	const TickType_t xBlockTime = pdMS_TO_TICKS(20000);

	// Number of interrupts waiting.
	uint32_t ulNotifiedValue;

	for( ;; ) {
		// Wait for semaphore notification.
		ulNotifiedValue = ulTaskNotifyTake( pdFALSE, xBlockTime );

		if( ulNotifiedValue > 0 ) {
			// Blink led for 1 second.
			GPIOB->PDOR ^= LED_D12;
			vTaskDelay(pdMS_TO_TICKS(1000));
			GPIOB->PDOR ^= LED_D12;
		}
	}
}
// }

// Taken from: https://www.freertos.org/RTOS_Task_Notification_As_Counting_Semaphore.html
// Edited by xnovot1f
// {
// PORT E Interrupt Service Routine.
void IRQ_SWITCHES(void) {
	BaseType_t xHigherPriorityTaskWoken;

	// Remove bounce.
	//delay(200);

	// Whether the task that was notified (unblocked) has higher priority, than currently interrupted task.
	xHigherPriorityTaskWoken = pdFALSE;

	// Determine which pin caused interrupt and unblock a task.
	if (!(GPIOE->PDIR & BTN_SW2))
		vTaskNotifyGiveFromISR( flash_D9_task_handler, &xHigherPriorityTaskWoken );

	else if (!(GPIOE->PDIR & BTN_SW3))
		vTaskNotifyGiveFromISR( flash_D10_task_handler, &xHigherPriorityTaskWoken );

	else if (!(GPIOE->PDIR & BTN_SW4))
		vTaskNotifyGiveFromISR( flash_D11_task_handler, &xHigherPriorityTaskWoken );

	else if (!(GPIOE->PDIR & BTN_SW5))
		vTaskNotifyGiveFromISR( flash_D12_task_handler, &xHigherPriorityTaskWoken );


	// Clear interrupt flags.
	prvClearInterruptSource();

	// If unblocked task has higher priority, currently interrupted task needs to yield.
	portYIELD_FROM_ISR( xHigherPriorityTaskWoken );
}
// }

/*
 * @brief   Application entry point.
 */
int main(void) {

  	/* Init board hardware. */
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

  	/* Init FSL debug console. */
    // BOARD_InitDebugConsole();
    // PRINTF("Hello World\n");

    // Create tasks, save handlers for Deffered Interrupt Handler tasks.
    xTaskCreate(led_init_task, "led_init_task", configMINIMAL_STACK_SIZE, NULL, task_PRIORITY, NULL);
    xTaskCreate(flash_D9_task, "flash_D9_task", configMINIMAL_STACK_SIZE, NULL, task_PRIORITY, &flash_D9_task_handler);
    xTaskCreate(flash_D10_task, "flash_D10_task", configMINIMAL_STACK_SIZE, NULL, task_PRIORITY, &flash_D10_task_handler);
    xTaskCreate(flash_D11_task, "flash_D11_task", configMINIMAL_STACK_SIZE, NULL, task_PRIORITY, &flash_D11_task_handler);
    xTaskCreate(flash_D12_task, "flash_D12_task", configMINIMAL_STACK_SIZE, NULL, task_PRIORITY, &flash_D12_task_handler);

    vTaskStartScheduler();

    /* Force the counter to be placed into memory. */
    volatile static int i = 0 ;
    /* Enter an infinite loop, just incrementing a counter. */
    while(1) {
        i++ ;
        __asm volatile ("nop");
    }

    return 0 ;
}
