# Arduino
### Specifications
- Board: Arduino Uno
- Bluetooth module: HC-05

### Circuit:
Two positive end of each side's two motor is shorted to form one single positive end. Same approach is made for negative ends. Pinout Table:
Motor | Motor Driver
-|-
Right Positive End | OUT1
Right Negative End | OUT2
Left Positive End | OUT4
Left Negative End | OUT3

### Movement Logic
Direction | Right side motors | left side motor
-|-|-
Forward | On | On
Backward | On(reverse) | On(reverse)
Turn Left | On | On(reverse)
Turn Right| On(reverse) | On
Forward Left | On | Off
Forward Right | Off | On
Backward Left | On(reverse) | Off
Backward Right | Off | On(reverse)

To customize, follow the instructions written in code comments.