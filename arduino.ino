// Sisimpur-SoccerBot © 2024 by Sisimpur is licensed under CC BY-NC-SA 4.0

//========================================
// Pinout Declarations
// -=-
// Change it according to your circuit.
// IN1 = OUT1. Same logic for other pins.
//========================================
uint8_t out1 = 3;
uint8_t out2 = 4;
uint8_t out3 = 5;
uint8_t out4 = 6;
//==------------------------------------==

//===================================================
// MAIN CODE
// -=-
// No changes required unless explicitely mentioned.
//===================================================
void setup()
{
    Serial.begin(9600); // By Default, HC-05 Recieves Signals in 9600 baud rate channel. Changes needed if your module uses aother channel.
    pinMode(out1, OUTPUT);
    pinMode(out2, OUTPUT);
    pinMode(out3, OUTPUT);
    pinMode(out4, OUTPUT);
}

char btSignal = 0;
void loop()
{
    if (Serial.available())
    {
        btSignal = Serial.read();
        Serial.println(btSignal);
        if (btSignal == 'F')
        {
            moveForward();
        }
        else if (btSignal == 'B')
        {
            moveBackward();
        }
        else if (btSignal == 'R')
        {
            turnRight();
        }
        else if (btSignal == 'L')
        {
            turnLeft();
        }
        else if (btSignal == 'G')
        {
            moveForwardLeft();
        }
        else if (btSignal == 'I')
        {
            moveForwardRight();
        }
        else if (btSignal == 'H')
        {
            moveBackwardLeft();
        }
        else if (btSignal == 'J')
        {
            moveBackwardRight();
        }
        else if (btSignal == 'S')
        {
            stopAllMotors();
        }
        // else { stop(); } // Remove this if you want to stop.
    }
}
//==------------------------------------==

//=======================================================
// Motor Spin Directions
// -=-
// Test if these 6 functions works as expected.
// HIGH-LOW can be completely opposite for your circuit.
//=======================================================
void spin_right_motors()
{
    digitalWrite(out1, LOW);
    digitalWrite(out2, HIGH);
}

void reverse_spin_right_motors()
{
    digitalWrite(out1, HIGH);
    digitalWrite(out2, LOW);
}

void stop_right_motors()
{
    digitalWrite(out1, LOW);
    digitalWrite(out2, LOW);
}

void spin_left_motors()
{
    digitalWrite(out3, HIGH);
    digitalWrite(out4, LOW);
}

void reverse_spin_left_motors()
{
    digitalWrite(out3, LOW);
    digitalWrite(out4, HIGH);
}

void stop_left_motors()
{
    digitalWrite(out3, LOW);
    digitalWrite(out4, LOW);
}
//==---------------------------------==

//===============================
// Moving Directions
// -=-
// No Changes required
//===============================
void moveForward()
{
    spin_right_motors();
    spin_left_motors();
}

void moveBackward()
{
    reverse_spin_right_motors();
    reverse_spin_left_motors();
}

void turnRight()
{
    reverse_spin_right_motors();
    spin_left_motors();
}

void turnLeft()
{
    spin_right_motors();
    reverse_spin_left_motors();
}

void moveForwardLeft()
{
    spin_right_motors();
    stop_left_motors();
}
void moveForwardRight()
{
    spin_left_motors();
    stop_right_motors();
}
void moveBackwardRight()
{
    reverse_spin_left_motors();
    stop_right_motors();
}
void moveBackwardLeft()
{
    reverse_spin_right_motors();
    stop_left_motors();
}

void stopAllMotors()
{
    stop_right_motors();
    stop_left_motors();
}
//==-----------------------------==