#include <TinyGPS++.h>
#include <LiquidCrystal_I2C.h>

String str;
LiquidCrystal_I2C lcd(0x27,16,2); 
const char *gpsStream =
  "$GPRMC,045103.000,A,3014.1984,N,09749.2872,W,0.67,161.46,030913,,,A*7C\r\n"
  "$GPGGA,045104.000,3014.1985,N,09749.2873,W,1,09,1.2,211.6,M,-22.5,M,,0000*62\r\n"
  "$GPRMC,045200.000,A,3014.3820,N,09748.9514,W,36.88,65.02,030913,,,A*77\r\n"
  "$GPGGA,045201.000,3014.3864,N,09748.9411,W,1,10,1.2,200.8,M,-22.5,M,,0000*6C\r\n"
  "$GPRMC,045251.000,A,3014.4275,N,09749.0626,W,0.51,217.94,030913,,,A*7D\r\n"
  "$GPGGA,045252.000,3014.4273,N,09749.0628,W,1,09,1.3,206.9,M,-22.5,M,,0000*6F\r\n";

// The TinyGPS++ object
TinyGPSPlus gps;

void setup(){
  Serial.begin(9600);
  lcd.init ();
  lcd.backlight ();

  while (*gpsStream)
    if (gps.encode(*gpsStream++))
      displayInfo();

  Serial.println();
  Serial.println(F("Done."));
}

void loop(){
  displayInfo();
}

void displayInfo()
{
  
  if (gps.location.isValid())
  {
    Serial.print(F("Latitude: ")); 
    lcd.setCursor (0,0);
    lcd.print ("Lat:");
    lcd.print (gps.location.lat(), 6);
    Serial.print(gps.location.lat(), 6);
    Serial.println();  
    Serial.print(F("Longitude: "));
    lcd.setCursor (0,5);
    
    lcd.print ("Long:");
    lcd.print (gps.location.lng(), 6);
    Serial.print(gps.location.lng(), 6);
    Serial.println();
    delay (500);
  }
  else
  {
    Serial.print(F("ERROR"));
  }
  
}
