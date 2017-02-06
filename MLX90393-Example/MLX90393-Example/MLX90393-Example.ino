/* 
 MLX90393 Magnetometer Example Code
 By: Nathan Seidle
 SparkFun Electronics
 Date: February 6th, 2017
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).
 
 Read the mag fields on three XYZ axis
 
 Hardware Connections (Breakoutboard to Arduino):
 3.3V = 3.3V
 GND = GND
 SDA = A4
 SCL = A5
 
 Serial.print it out at 9600 baud to serial monitor.
 */

#include <Wire.h>

#define MLX90393_ADDRESS 0x0C  //Unshifted 7-bit I2C address for the sensor

void setup()
{
  Serial.begin(9600);
  Serial.println("MLX90393 Example");

  Wire.begin();
}

void loop()
{
  Wire.beginTransmission(MLX90393_ADDRESS);
  Wire.write(0b01001000); //Read measurement command, Z axis
  Wire.endTransmission();

  Wire.requestFrom(MLX90393_ADDRESS, 3);

  int status = Wire.read();
  byte zMSB = Wire.read();
  byte zLSB = Wire.read();

  int zReading = ((int)zMSB << 8) | zLSB;
    
  Serial.print("status: 0x");
  Serial.print(status, HEX);
  Serial.print(" z: ");
  Serial.print(zReading);
  Serial.println();

  delay(1000);
}
