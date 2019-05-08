// HC-SR04 library test

#include "HC-SR04.h"

HCSR04 sensor(6, 7, HCSR04::MM);

// setup
void setup()
{
    Serial.begin(115200);
    Serial.println("*** HC-SR04 Test ***");
};

// main
void loop()
{
    Serial.print("Duration [us]: ");
    Serial.println(sensor.duration());
    Serial.print("Distance [mm]: ");
    Serial.println(sensor.distance());
    delay(2000);
}
