#include <Arduino_FreeRTOS.h>
//#include <croutine.h>
#include <event_groups.h>
#include <FreeRTOSConfig.h>
#include <FreeRTOSVariant.h>
#include <list.h>
#include <mpu_wrappers.h>
#include <portable.h>
#include <portmacro.h>
#include <projdefs.h>
#include <queue.h>
#include <semphr.h>
#include <stack_macros.h>
#include <task.h>
#include <timers.h>
#include <avr/sleep.h> // Include sleep functions for AVR boards

// define two tasks for Blink and AnalogRead
void TaskBlink( void *pvParameters );
void TaskAnalogRead( void *pvParameters );
void vBuzzTask(void *pvParameters);
 
// the setup function runs once when you press reset or power the board
void setup()
{
// Now set up two tasks to run independently.
xTaskCreate(
TaskBlink
, "Blink" // A name just for humans
, 128      // This stack size can be checked and adjusted by reading the Stack Highwater
, NULL
, 2        // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
, NULL );
 
xTaskCreate(
TaskAnalogRead
, "AnalogRead"
, 128      // Stack size
, NULL
, 1        // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
, NULL );

xTaskCreate(vBuzzTask, "Buzzer", 128, NULL, 3, NULL);
 
// Now the task scheduler, which takes over control of scheduling individual tasks, is automatically started.
}
 
void loop()
{
// Empty. Things are done in Tasks. Never Block or delay.
}
 
/*--------------------------------------------------*/
/*---------------------- Tasks ---------------------*/
/*--------------------------------------------------*/
 
void TaskBlink(void *pvParameters) // This is a task.
{
(void) pvParameters;
 
// initialize digital pin 13 as an output.
pinMode(13, OUTPUT);
 
for (;;) // A Task shall never return or exit.
{
digitalWrite(13, HIGH); // turn the LED on (HIGH is the voltage level)
vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
digitalWrite(13, LOW); // turn the LED off by making the voltage LOW
vTaskDelay( 1000 / portTICK_PERIOD_MS ); // wait for one second
}
}
 
void TaskAnalogRead(void *pvParameters) // This is a task.
{
(void) pvParameters;
 
// initialize serial communication at 9600 bits per second:
Serial.begin(9600);
 
for (;;)
{
// read the input on analog pin 0:
int sensorValue = analogRead(A0);
// print out the value you read:
Serial.println(sensorValue);
vTaskDelay(1); // one tick delay (15ms) in between reads for stability
}
}

void vBuzzTask(void *pvParameters){
  (void) pvParameters;
  int buzzerValue = 1;
  pinMode(3, OUTPUT);
  while(1){
    digitalWrite(3, HIGH); // turn the LED on (HIGH is the voltage level)
    vTaskDelay( 10 / portTICK_PERIOD_MS ); // wait for one second
    digitalWrite(3, LOW); // turn the LED off by making the voltage LOW
    vTaskDelay( 20 / portTICK_PERIOD_MS ); // wait for one second
  }
}
