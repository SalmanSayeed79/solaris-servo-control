#include "ESP8266.h"
#include <Servo.h> 

typedef struct _SolarisData {
  long double optimum_power_per_sqmeter;
  long double optimum_tilt_angle;
  long double profit_percentage;
  long double regular_power_per_sqmeter;
} SolarisData;

const char *SSID     = "";
const char *PASSWORD = "";
const int servoPin = 9;

SoftwareSerial mySerial(10, 11);
Servo SolarisServo;
ESP8266 wifi(mySerial); 

void setup(void)
{

  Serial.begin(115200);
  SolarisServo.attach(servoPin);
  if (!wifi.init(SSID, PASSWORD))
  {
    Serial.println("Wifi Init failed. Check configuration.");
    while (true); 
  }
}


void loop(void)
{   
    Serial.println("Sending Request to Solaris Backend");
    SolarisData data = wifi.httpGet();
    Servo1.write(data.optimum_tilt_angle);
    delay(7200); // check every 2 hours
}







