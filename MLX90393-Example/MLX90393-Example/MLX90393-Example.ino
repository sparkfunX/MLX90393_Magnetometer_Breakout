/* 
 HTU21D Humidity Sensor Example Code
 By: Nathan Seidle
 SparkFun Electronics
 Date: September 15th, 2013
 License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).
 
 Get humidity and temperature from the HTU21D sensor.
 
 Hardware Connections (Breakoutboard to Arduino):
 -VCC = 3.3V
 -GND = GND
 -SDA = A4
 -SCL = A5
 
 Serial.print it out at 9600 baud to serial monitor.
 */

#include <Wire.h>

#define MLX90393_ADDRESS 0x0C  //Unshifted 7-bit I2C address for the sensor

void setup()
{
  Serial.begin(9600);
  Serial.println("MLX90393 Example!");

  Wire.begin();
}

void loop()
{
  Serial.println("1");

  Wire.beginTransmission(MLX90393_ADDRESS);
  Wire.write(0b01001000); //Read measurement, Z axis
  Wire.endTransmission();

  Serial.println("2");

  Wire.requestFrom(MLX90393_ADDRESS, 3);

  Serial.println("3");

  int status = Wire.read();
  int response2 = Wire.read();
  int response3 = Wire.read();
    
  Serial.print("status: 0x");
  Serial.print(status, HEX);
  Serial.print(" response2: ");
  Serial.print(response2);
  Serial.print(" response3: ");
  Serial.print(response3);
  Serial.println();

  Serial.println("Stopped");
  while(1) ;
}



