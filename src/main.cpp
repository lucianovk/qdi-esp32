// Load Wi-Fi library
#include <Arduino.h>
#include <WiFi.h>
#include <SPIFFS.h>
#include <ESPAsyncWebServer.h>
#include <Wire.h>
#include <AsyncJson.h>

// Replace with your network credentials
const char *ssid = "qdi-esp32";
const char *password = "12345678";

// Set web server port number to 80
AsyncWebServer server(80);

// Variable to store the HTTP request
String header;

// Decode HTTP GET value
String valueString = String(5);

// Current time
unsigned long currentTime = millis();
// Previous time
unsigned long previousTime = 0;
// Define timeout time in milliseconds (example: 2000ms = 2s)
const long timeoutTime = 2000;

//Processing HTML TEMPLATE
String index_processor(const String &var)
{
  //Read sensor data here
  if (var == "PLACEHOLDER_TEMPERATURE")
    return String("10.50");
  else if (var == "PLACEHOLDER_HUMIDITY")
    return String("60.10");
  return String();
}

void setup()
{
  Serial.begin(115200);

  // Initialize SPIFFS
  if (!SPIFFS.begin(true))
  {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }

  // Connect to Wi-Fi network with SSID and password
  Serial.print("Setting AP (Access Point)…");
  // Remove the password parameter, if you want the AP (Access Point) to be open
  WiFi.softAP(ssid, password);

  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    request->send(SPIFFS, "/index.html", String(), false, index_processor);

    // Servo 1 control (Vial release)
    if (request->hasParam("servo1"))
    {
      AsyncWebParameter *p = request->getParam("servo1");
      Serial.println("servo1: " + p->value());
    }

    // Servo 2 control (Needle inserttion)
    if (request->hasParam("servo2"))
    {
      AsyncWebParameter *p = request->getParam("servo2");
      Serial.println("servo2: " + p->value());
      //Set servo position here
    }

    // Motor 1 control (Peristaltic pump)
    if (request->hasParam("motor1"))
    {
      AsyncWebParameter *p = request->getParam("motor1");
      if (p->value().length() == 2)
      {
        //Set motor status here
        // digitalWrite(MOTOR_A_IA, String(p->value().charAt(0)).toInt());
        // digitalWrite(MOTOR_A_IB, String(p->value().charAt(1)).toInt());
        Serial.println("motor1: " + p->value());
      }
    } });

  // Route for /main.js file
  server.on("/main.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/main.js"); });

  // Route for /favicon.ico file
  server.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/favicon.ico"); });

  // Route for /sensor data read
  server.on("/sensor", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    StaticJsonDocument<100> data;
    //Read sensor data here
    float t = 25.3;
    float h = 63.5;

    if (!isnan(t))
    {
      Serial.print("Temp *C = ");
      Serial.println(t);
      data["temp"] = t;
    }
    else
    {
      Serial.println("Failed to read temperature");
      data["temp"] = "err";
    }

    if (!isnan(h))
    {
      Serial.print("Hum. % = ");
      Serial.println(h);
      data["hum"] = h;
    }
    else
    {
      Serial.println("Failed to read humidity");
      data["hum"] = "err";
    }

    String response;
    serializeJson(data, response);
    request->send(200, "application/json", response); });
  server.begin();
}

void loop()
{
}
