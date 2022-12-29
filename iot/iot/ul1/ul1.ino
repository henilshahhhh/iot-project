#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
Servo servo1;
int trigPin = 9;
int echoPin = 8;
long distance;
long duration;
int sensor = A0;
boolean sensorstatus = true;
int count = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
 servo1.attach(7);//THE NO OF PIN THAT THE SERVO IS ATTACHED TO

  pinMode(trigPin, OUTPUT);//SETS THE TRIGPIN AS OUTPUT
  pinMode(echoPin, INPUT);//SETS THE ECHOPIN AS INPUT
  lcd.init();//INITIALIZE THE LCD
  lcd.clear();//
  lcd.backlight();//OPEN THE BACKLIGHT

}
void loop()
{
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);//SET TRIGPIN ON
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);//SET TRIGPIN OFF
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  servo1.write(0);
  if (distance <= 9)
  {
    servo1.write(30);
  }
  else
  {
    servo1.write(0);
  }
  lcd.setCursor(0, 0);//MOVE CURSOR TO DESIRED POSITION
  lcd.print("No of Vehicle");//PRINT THE MESSAGE
  lcd.setCursor(0, 1);//MOVE CURSOR TO COLUMN=0 AND ROW=1
  lcd.print(count);//PRINT THE VALUE OF COUNT VARIABLE
  sensorstatus = ! digitalRead(sensor);//READ THE VALUE FROM SPECIFIC DIGITAL PIN EITHER HIGH OR LOW
  if (sensorstatus)//IF OBJECT DETECT
  {
    count++;
    while (1)
    {
      if (digitalRead(sensor))
        return;
      delay(100);
    }
  }
}
