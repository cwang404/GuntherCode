#include <LiquidCrystal.h>
#include <Servo.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
Servo Valve;

int moistPin = 0;
int WetVal = 0;
int percent =0;
int tooDry = 150; 
int Dry = 187;
int Wet = 281;
int tooWet = 375;
 
void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.print("Moisture Level:");
  Valve.attach(6);
  Valve.write(90);
}

void loop()
{
  WetVal = analogRead(moistPin);
  Serial.println(WetVal);
  int percent = WetVal/375; 
  Serial.print(percent);
  lcd.clear();

  if (WetVal <= tooDry) {
    lcd.print("Moisture Level:");
    lcd.setCursor(0, 1);
    lcd.print("Water me now!");
     Valve.write(0);
  }
 
  else if ((tooDry < WetVal) and (WetVal <= Dry)) {
    lcd.print("Moisture Level:");    
    lcd.setCursor(0, 1);
    lcd.print("Still need water!");
    Valve.write(0);
  }
  
  else if ((Dry < WetVal) and (WetVal <= Wet)) {
    lcd.print("Moisture Level:");
    lcd.setCursor(0, 1);
    lcd.print("jus vibin' :)");
    Valve.write(90);
  }
   else if ((Wet < WetVal) and (WetVal <= tooWet)) {
    lcd.print("Moisture Level:");
    lcd.setCursor(0, 1);
    lcd.print("Too much! Stop!");
    Valve.write(90);
  }
  else {
    lcd.print("Moisture Level:");    
    lcd.setCursor(0, 1);
    lcd.print("I'm drowning! :(");
    Valve.write(90);
  }
  delay(50);
}
