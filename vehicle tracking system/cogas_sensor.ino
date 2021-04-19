Co gas sensor code 

#include <LiquidCrystal_I2C.h>

String str;
LiquidCrystal_I2C lcd(0x27,16,2); 

void setup() 
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  lcd.init ();
  lcd.backlight ();
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  lcd.setCursor (0,0);
  lcd.print ("Smoke:");
  lcd.print (sensorValue);
  lcd.print ("%");
  delay(2000);
}
