# ProofingBox
Arduino project to build box with ideal temperature for dough proofing

The microcontroller reads the ambient temperature from the AM2320 sensor (using Adafruit's Sensor and AM2320 libraries).
A relay is then activated to heat up a heating pad to keep the temperature in a set temperature range. The temperature range is between 25 and 35 degrees Celsius, as this is the optimal temperature for yeast to grow, which is the aim of the proofing box.

This is a very simple temperature control, which only involves turning the relay on or off according to the current temperature and the target temperature range. This is not a PID control (for a more complex PID control example, see my other project PID_oven). For this reason, I have kept the temperature target range quite large in order to avoid excessive wear of the relay from switching on and off.

For I2C communication between the microcontroller and the sensor, do not forget to add pull-up resistors on SDA and SCL lines according to I2C specifications (4.7k or 10k will work).


