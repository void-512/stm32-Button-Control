# stm32-Button-Control

A button is connected to the 4E pin and an LED is connected to the 5E pin of MCU.


When button is pressed, the 4E pin is connected to ground.

The system will wait for 10ms to avoid skaing and then detect the level again.

If 4E is still in low level, the LED at 5E will be turned off.

Use a loop to continuously detech the level of 4E.
