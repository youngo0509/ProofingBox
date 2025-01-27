#include "Adafruit_Sensor.h"
#include "Adafruit_AM2320.h"

#define RELAY 12

Adafruit_AM2320 am2320 = Adafruit_AM2320(); //create instance of sensor
bool prevState = 0; //state to decide whether relay should be ON or OFF in wanted temperature range (heating up or cooling down)

void setup() {
  Serial.begin(9600);
  digitalWrite(RELAY, HIGH); //this is to avoid unnecessary switching of relay at initialisation
  pinMode(RELAY, OUTPUT);
  while (!Serial) {
    delay(10); // hang out until serial port opens
  }

  am2320.begin(); //initialise sensor
}


void loop() {

  delay(2000);
  //read and print temperature and humidity
  float temperature = am2320.readTemperature();
  delay(2000);
  float humidity = am2320.readHumidity();
  Serial.print("Temp: "); Serial.println(temperature);
  Serial.print("Hum: "); Serial.println(humidity);
  delay(2000);


  //if temperature is below target, activate relay
  if (temperature < 25)
  { Serial.print("It is cold!\n");
    digitalWrite(RELAY, HIGH);
    prevState = 1;
  }

  //if temperature is above target, deactivate relay
  if (temperature > 35)
  { Serial.print("It is hot!\n");
    digitalWrite(RELAY, LOW);
    prevState = 0;
  }

  //if temperature is within range, fluctuate between min and max
  if (temperature > 25 && temperature < 35)
  { if (prevState == 0)
    { Serial.print("Cooling down!\n");
      digitalWrite(RELAY, LOW);
    }
    else {
      Serial.print("Heating up!\n");
      digitalWrite(RELAY, HIGH);
    }
  }

}
