// HC-SR04 control library

#include "Arduino.h"
#include "HC-SR04.h"

HCSR04::HCSR04(int echoPin, int triggerPin, HCSR04::Unit unit) :
    _echoPin(echoPin),
    _triggerPin(triggerPin),
    _unit(unit)
{
    // initialize pins
    pinMode(_echoPin, OUTPUT);
    pinMode(_triggerPin, OUTPUT);
}

// returns signal return time in us
int HCSR04::duration() const
{
    long duration;
    
    // trigger measurement
    digitalWrite(_triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(_triggerPin, LOW);

    // trigger duration read
    digitalWrite(_echoPin, LOW);
    delayMicroseconds(2);
    digitalWrite(_echoPin, HIGH);

    delayMicroseconds(5);
    digitalWrite(_echoPin, LOW);
    pinMode(_echoPin, INPUT);

    // get duration
    duration = pulseIn(_echoPin, HIGH);

    //reset
    pinMode(_echoPin, OUTPUT);

    return duration;
}

// returns measured distance
int HCSR04::distance() const
{
    return _duration2Distance(duration());
}

int HCSR04::_duration2Distance(int duration) const
{
    double fac = 1.0;
            
    switch (_unit) {
    case INCH:
        fac = 6.0 * 25.4;
    case INCH10:
        fac = 6.0 * 2.54;
    case MM:
        fac = 6.0;
    case CM:
        fac = 60.0;
    }

    return (int) ((double) duration / fac);
}
