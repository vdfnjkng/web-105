#include <LiquidCrystal_I2C.h>

String str;
LiquidCrystal_I2C  lcd(0x27,16,2);

int vib = 7;


void setup() {
  Serial.begin(9600);
  pinMode(vib, OUTPUT);
  lcd.init ();
  lcd.backlight();
}

void loop() {
  int sensorValue = analogRead(A0);
  Serial.println(sensorValue);
  if(sensorValue<1000) {
    tone(vib, 1000);
    Serial.println(sensorValue);
  lcd.setCursor (0,0);
  lcd.print ("VIB:");
  lcd.print (sensorValue);
  lcd.print ("%");
    delay(500);
  }
  noTone(vib);
  lcd.clear();
  lcd.setBacklight(HIGH);
}
