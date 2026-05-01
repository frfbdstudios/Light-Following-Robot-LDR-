# Light-Following-Robot-LDR-
We are build a Light Following Robot using (LDR)


📌 Project Overview

This project is a Light Following Robot using an Arduino, three LDR sensors, and a dual motor driver. The robot detects light intensity and moves toward the strongest light source.

⚙️ Components Required:
Arduino (Uno/Nano)
3 × LDR sensor modules
Motor Driver (L298N / L293D)
2 × DC Motors
Robot chassis + wheels
Power supply (Battery pack)

🔌 Pin Configuration:
Component............	......Arduino Pin
Left LDR	.....................8
Center LDR	...................7
Right LDR	.....................9
Left Motor IN1..............	10
Left Motor IN2	..............11
Right Motor IN3	..............12
Right Motor IN4	..............13

💡 Sensor Behavior:
Most LDR modules output LOW when light is detected
If your sensor outputs HIGH instead, change:
#define LIGHT_ACTIVE_STATE HIGH

🤖 Working Logic:
If center sensor detects light → Move Forward
If left sensor detects light → Turn Left
If right sensor detects light → Turn Right
If no sensor detects light → Stop

🧪 Testing Instructions:
Upload the code to Arduino
Open Serial Monitor (9600 baud)
Use a flashlight to test each sensor
Observe sensor values and robot movement

⚠️ Troubleshooting:
Robot moving opposite direction → Swap motor wires
Sensors not responding → Check LIGHT_ACTIVE_STATE
Motors not working → Check driver connections and power supply
