/*
  Calibrated Analog Input

  On Arduino boards, the function analogRead usually returns an integer 
  value betwen 0 and 1023 corresponding the voltage on the pin. With this example, 
  the read raw value is mapped to 0.0 to 5.0.

  Attention: there are boards which are running on 3.3V instead of 5.0V. 
  Don't connect the pin to a voltage higher than 3.3V on these boards (and maybe 
  change this example calibration to an output range between 0.0 and 3.3).    

  created by Stefan Trippler

  This example code is in the public domain.
*/

#include <Arduino.h>
#include <linearcalib.h>

int sensorPin = A0;   // select the input pin for the potentiometer
LinearCalib myCalib;


void setup() {
  float InMin=0;     // for excample a messured raw value where 0 is expected
  float InMax=1023;  // for excample a messured raw value where 80 is expected
  float OutMin=0.0;  // expected value
  float OutMax=5.0;  // expected value

  // set calibration values
  myCalib.setParams(InMin, InMax, OutMin, OutMax);

  // setup serial device - use 115.200 baud, 8N1
  Serial.begin(115200);
}

void loop() {
  int rawSensorValue;
  float calibratedSensorValue;
  // read the raw value from the sensor:
  rawSensorValue = analogRead(sensorPin);
  // calibrate the data
  calibratedSensorValue = myCalib.calc(rawSensorValue);
  // print the value on serial device
  Serial.println(calibratedSensorValue);
  // stop the program for 500 milliseconds:
  delay(500);
}
