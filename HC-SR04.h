// HC-SR04 control library

class HCSR04 {
 public:
    enum Unit {
        INCH, // distance in inch (imperial)
        INCH10, // distance in 1/10 inch (imperial)
        MM,  // distance in mm (metric)
        CM,  // distance in mm (metric)
    };

    /* initialize HC-SR04 board
       echoPin: Pin number connected to 'Echo'
       triggerPin: Pin number connected to 'Trig'
       unit: Unit for distance measurement
    */
    HCSR04(int echoPin, int triggerPin, Unit unit);

    // get the signal travelling time (sensor <-> object)
    int duration() const;
    // get the distance between sensor and object
    int distance() const;

 private:
    int _duration2Distance(int duration) const;

    int _echoPin;
    int _triggerPin;
    Unit _unit;
};
