#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>

#define ssid      "Backhomenet"     // WiFi SSID
#define password  "1700note"        // WiFi password
#define ledPin    D4                // Led
float   tempValue   = 0;
float   humiValue   = 0;
float   co2Value    = 0;
String  ledState    = "ON";
int     cnt         = 0;

ESP8266WebServer server ( 80 );

String getPage() {
    String page = "<html lang=kr-KR><head><meta http-equiv='refresh' content='10'/>";
    page += "<title>ESP8266 Server Demo</title>";
    page += "<style> body { background-color: #fffff; font-family: Arial, Helvetica, Sans-Serif; Color: #000088; }</style>";
    page += "</head><body><h1>ESP8266 Demo</h1>";
    page += "<h3>BME280</h3>";
    page += "<ul><li>TEMPERATURE : ";
    page += tempValue;
    page += " &#176;C</li>";    // ° -> &#176;
    page += "<li>HUMIDITY &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;: ";
    page += humiValue;
    page += " %</li></ul><h3>MH-Z16</h3>";
    page += "<ul><li>CO2 : ";
    page += co2Value;
    page += " ppm</li></ul>";
    page += "<h3>GPIO</h3>";
    page += "<form action='/' method='POST'>";
    page += "<ul><li>D4 (State : ";
    page += ledState;
    page += ")";
    page += "<INPUT type='radio' name='LED' value='0'>OFF";
    page += "<INPUT type='radio' name='LED' value='1'>ON</li></ul>";
    page += "&nbsp; &nbsp; &nbsp;<INPUT type='submit' value='SUBMIT'>";
    page += "<p><a hrf='https://diyprojects.io/esp8266-web-server-tutorial-create-html-interface-connected-object/#.XK-nvpgzaiM'><h5>Designed by analoglab.com</h5></p>";
    page += "</body></html>";
    return page;
}

void handleRoot() {
    if ( server.hasArg("LED") ) {
        handleSubmit();
    }
    else {
        server.send ( 200, "text/html", getPage() );
    }
}

void handleSubmit() {
    // Refresh the GPIO / GPIO Update
    String LEDValue;
    LEDValue = server.arg("LED");
    Serial.println("Set GPIO "); Serial.print(LEDValue);
    if ( LEDValue == "1" ) {
        digitalWrite(ledPin, 0);
        ledState = "On";
        server.send ( 200, "text/html", getPage() );
    }
    else if ( LEDValue == "0" ) {
        digitalWrite(ledPin, 1);
        ledState = "Off";
        server.send ( 200, "text/html", getPage() );
    }
    else {
        Serial.println("Error Led Value");
    }
}

void setup() {
    Serial.begin ( 115200 );

    pinMode(ledPin, OUTPUT);
    WiFi.begin ( ssid, password );

    // Waiting for the connection to the WiFi / Wait for connection network
    while ( WiFi.status() != WL_CONNECTED ) {
        delay ( 500 ); Serial.print ( "." );
    }

    // WiFi connection established / WiFi connection is OK
    Serial.println ( "" );
    Serial.print ( "Connected to " ); Serial.println ( ssid );
    Serial.print ( "IP address: " ); Serial.println ( WiFi.localIP() );

    // Connect the function that manages the first page / link to the function that manage launch page
    server.on ( "/", handleRoot );

    server.begin();
    Serial.println ( "HTTP server started" );
}

void loop() {
    server.handleClient();

    tempValue = 25.0 + cnt;
    humiValue = 50.0 + cnt;
    co2Value = 1000.0 + cnt;
    cnt++;
    delay(1000);
    if ( cnt == 10 ) cnt = 0;
    Serial.print("T : "); Serial.println(tempValue);
    Serial.print("H : "); Serial.println(humiValue);
    Serial.print("CO2 : "); Serial.println(co2Value);
}
