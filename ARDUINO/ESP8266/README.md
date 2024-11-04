I'm using ESP8266 or known as NODEMCU as the main component, connected to wifi to link with the blynk website and mobile app for control.

# COMPONENTS LIST 
1.Nodemcu board x 1 
2.Flame sensor x1 
3.Ultrasonic sensor x 1 
 4.DHT11 sensor x 1
5.MQ2 sensor x 1 
6.PIR sensor x 1 
7.Two-channel relay module 5V x 1 
8.LCD display x 1 
9.I2C module x 1 
10.5V Buzzer x 1 
11.Breadboard LARGE x 1 
12.Jumper wires (M-F) & (M-M)

# CONNECTION
1.	NODEMCU
VC -- (+)
GND -- (-)

2.	BUZZER
(+) -- DO
GND -- (-)

3.	LCD & IC2
GND – (-)
VCC – (+)
SDA – D2
SCL – D1

4.	DHT11 (TEMPERATURE MAX=50, IDEAL=20 TO 22)(HUMIDITY MAX=100, IDEAL 20<H<80)*IF H>60, USE DEHUMIDIFIER/IMPROVE VENTILATION.
(-) – (-)
OUT – D3
(+) – (+)

5.	MQ2 SENSOR (GAS MAX=10, CUT OFF POINT=60)
VCC – (+)
(BROWN>+VE, RED>GREEN)
GND – (-)
(GREEN>-VE, ORANGE>BLUE)
AO – AO
(GREY>AO, YELLOW>PURPLE)

6.	ULTRASONIC SENSOR (WATER LEVEL MAX=50, IDEAL= 30 TO 50)
VCC – (+) YELLOW
TRIG – D4 ORANGE
ECHO – D5 RED
GND – (-) BROWN

7.	PIR SENSOR
VCC – (+)
OUT – D6
GND – (-)

8.	RELAY (EXCLUDED)
GND – (-)
IN1 – D7
IN2 – D8
VCC – (+)

