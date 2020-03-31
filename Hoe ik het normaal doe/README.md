# UWE Bristol Creative Technology Toolkit session seven

https://github.com/uwe-creative-technology/CT_toolkit_sessions


example code for the Creative Technology Toolkit module on Creative Technology MSc at UWE Bristol

video walk throughs of all code examples here can be found on YouTube at

https://www.youtube.com/playlist?list=PL6QF0yo3Zj7ALxV4MyOJ9oSFsV-Mo39R2


http://uwecreativetechnology.com

Dan Buzzo, November 2018

https://github.com/danbz

https://buzzo.com


# Session 7

• serial input and output with oF and arduino

• send values to serial port

• retrieve values from serial port


![screenshot](screenshot-session7.jpg)

use this script for your arduino sketch

--------
```
/*
  Ultra-simple sketch to demonstrate the use of Arduino with
  openFrameworks.

  This sketch is written to be used with the UWE Creative Technology Toolkit course serialExample or can work with the
   serialExample program that comes with the openFrameworks library. It initializes a serialport
   with a speed of 9600 baud, then waits for serialExample to send a character ('a' by default), then responds with three dollar signs.

  To use this sketch with oF, program your Arduino, make sure the Arduino is the only
  virtual COM device in use, and then build and run the serialExample example in openFrameworks.

  Released under the Creative Commons Share-Alike License 10/2011
  
  modifed by Dan Buzzo 11/2018
*/

int ledPin = 13;
int greenLedPin = 12;
int redLedPin = 11;
int sensorPin = 0;
int sensorValue = 0;

void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600);
  pinMode (ledPin, OUTPUT);
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  char inByte = 0;
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();

    if (inByte == 'a') {
      digitalWrite(greenLedPin, HIGH);
      delay(500);
      digitalWrite(greenLedPin, LOW);
    }

    if (inByte == 'b') {   
        digitalWrite(redLedPin, HIGH);
        delay(500);
        digitalWrite(redLedPin, LOW);
    }

    if (inByte == 'c') {
      for (int i = 0; i < 4; i++) {
        digitalWrite(ledPin, HIGH);
        delay(sensorValue+50);
        digitalWrite(ledPin, LOW);
        delay(sensorValue+50);
      }
    }
    // byte read, send three characters
    // Serial.print("£");
    // Serial.print("£");
    // Serial.print(inByte);

  }
   Serial.write(sensorValue);
}
```
