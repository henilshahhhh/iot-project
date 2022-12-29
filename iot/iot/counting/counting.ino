#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int sensor = A0;
boolean sensorstatus = true;
int count = 0;
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{

  lcd.init();
  lcd.clear();
  lcd.backlight();
}


void loop() 
{

  lcd.setCursor(0, 0);
  lcd.print("No of Vehicle");
  lcd.setCursor(0, 1);
  lcd.print(count);
  sensorstatus = ! digitalRead(sensor);
  if (sensorstatus)
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
