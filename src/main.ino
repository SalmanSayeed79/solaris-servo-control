#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <Servo.h>

  long double optimum_power_per_sqmeter;
  long double optimum_tilt_angle;
  long double profit_percentage;
  long double regular_power_per_sqmeter;
  double SolarisData;


char ssid[] = "SSID"; 
char password[] = "password";
const int servoPin = 9;
Servo SolarisServo;
WiFiClientSecure client;

// Just the base of the URL you want to connect to
#define TEST_HOST "api.coingecko.com"

void setup()
{

  Serial.begin(115200);
  SolarisServo.attach(servoPin);

  // Connect to the WiFI
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);

  //--------

   client.setInsecure();


  makeHTTPRequest();
}

void makeHTTPRequest()
{

  // Opening connection to server (Use 80 as port if HTTP)
  if (!client.connect(TEST_HOST, 443))
  {
    Serial.println(F("Connection failed"));
    return;
  }

  // give the esp a breather
  yield();

  // Send HTTP request to Solaris
  client.print(F("GET "));
  client.print("Solaris"); // %2C == ,

  // HTTP 1.0 is ideal as the response wont be chunked
  // But some API will return 1.1 regardless, so we need
  // to handle both.
  client.println(F(" HTTP/1.0"));

  //Headers
  client.print(F("Host: "));
  client.println(TEST_HOST);

  client.println(F("Cache-Control: no-cache"));

  if (client.println() == 0)
  {
    Serial.println(F("Failed to send request"));
    return;
  }
  //delay(100);
  // Check HTTP status
  char status[32] = {0};
  client.readBytesUntil('\r', status, sizeof(status));

  // Check if it responded "OK" with either HTTP 1.0 or 1.1
  if (strcmp(status, "HTTP/1.0 200 OK") != 0 || strcmp(status, "HTTP/1.1 200 OK") != 0)
  {
    {
      Serial.print(F("Unexpected response: "));
      Serial.println(status);
      return;
    }
  }

  // Skip HTTP headers
  char endOfHeaders[] = "\r\n\r\n";
  if (!client.find(endOfHeaders))
  {
    Serial.println(F("Invalid response"));
    return;
  }

  // For APIs that respond with HTTP/1.1 we need to remove
  // the chunked data length values at the start of the body
  //
  // peek() will look at the character, but not take it off the queue
  while (client.available() && client.peek() != '{' && client.peek() != '[')
  {
    char c = 0;
    client.readBytes(&c, 1);
    Serial.print(c);
    Serial.println("BAD");
  }

  // While the client is still availble read each
  // byte and print to the serial monitor
  while (client.available())
  {
    char c = 0;
    client.readBytes(&c, 1);
    Serial.print(c);
  }
}

void loop()
{
 Serial.println("Sending Request to Solaris Backend");
   SolarisServo.write(optimum_tilt_angle);
    delay(7200); 
    
    }
