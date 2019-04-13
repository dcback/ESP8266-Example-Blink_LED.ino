#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

    const char htmlPage[] PROGMEM = R"=====(
    <html>

    <head>
    <meta http-equiv="content-type" content="text/html;charset=UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
    <title>Hello from HTTP Server ESP8266</title>
    </head>

    <body>
    <div class="container">
        <h1>H1 ESP8266 KiET HTTP Server</h1>
        <p>Hello from ESP8266 HTTP Server. Selection of <b>Bootstrap</b> CSS styles.</p>
        <h2>H2 KiET Sever designed by ORY</h2>
        <h3>H3 무한 봉사 무한 행복 무한 생명</h3>
        <h4>H4 사후가 있건 없건 내 내리사랑과 봉사만이 우리의 존재의 이유이다. 이는 세상 모든 종교의
        원리이며 가르침이다. 진정한 신은 우리 곁에 어렵고 힘든 이웃이다. 물질이든 시간이든 정신이든
        지식이든 내 가진 모든 자산을 봉사하고 삶의 종착지에선 조용히 웃으며 홀연히 떠나는 것이다</h4>
        <h5>H5 물은 인간이다.. 안개를 이루는 물 입자는 습을 유지하여 자연을 살 찌우고 구름을 만들어 
        비를 내리고 흐르는 강물이 되어 바다로 바다로 흘러 순환한다. 비단, 물 뿐만 아니라 내 모든 구성요소 
        아니 모든 자연의 생물, 무생물이 모두 이렇게 환원한다. 내 현재 몸은 이들의 결합이고 너무나도 운좋게 
        정신과 자아를 가졌기에 세상에 모든 구성원에게 봉사와 희생은 지극히 당연한 것이다. 단지 인간만이 
        철저히 자기를 위해서만 산다</h5>
        <h6>H6 아낌없이 주는 나무가 있습니다.열매를, 시원한 그늘을, 나중엔 잘려나가,그루터기 의자로 남아 지친
        이의 쉼터가 되어주는.. 어떤 나무도 자신을 위해 자라지 않습니다. 자신을 위해 그늘을 만들지 않습니다</h6>

        <h1>Buttons</h1>
        <p>
            <button type="button" class="btn btn-default">Default</button>
            <button type="button" class="btn btn-primary">Primary</button>
            <button type="button" class="btn btn-success">Success</button>
            <button type="button" class="btn btn-info">Info</button>
            <button type="button" class="btn btn-warning">Warning</button>
            <button type="button" class="btn btn-danger">Danger</button>
            <button type="button" class="btn btn-link">Link</button>
        </p>

        <h1>Alerts</h1>
        <div class="alert alert-success" role="alert">
            <strong>Well done!</strong> You successfully read this important alert message.
        </div>
        <div class="alert alert-info" role="alert">
            <strong>Heads up!</strong> This alert needs your attention, but it's not super important.
        </div>
        <div class="alert alert-warning" role="alert">
            <strong>Warning!</strong> Best check yo self, you're not looking too good.
        </div>
        <div class="alert alert-danger" role="alert">
            <strong>Oh snap!</strong> Change a few things up and try submitting again.
        </div>

        <p>Designed by ORY (C) 2019 <a href="https://github.com/dcback/ESP8266/blob/master/Example/WebServer/esp8266_Server2.ino">GithubLink.</a></p>
    </div>
    </body>

    </html>
    )=====";

void handleRoot() {
    Serial.println("GET /");
    server.send(200, "text/html", htmlPage);
}

// Replace with your network credentials
const char* ssid     = "Backhomenet";
const char* password = "1700note";

unsigned long preMillis = 0;
#define ledPin  D4
int ledState = LOW;

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, password);
    Serial.println("");

    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);

    // Wait for connection
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to ");
    Serial.println(ssid);
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());

    server.on("/", handleRoot);

    server.begin();
    Serial.println("HTTP server started");
    digitalWrite(ledPin, LOW);
}

void loop() {
    server.handleClient();

    unsigned long curMillis = millis();

    if ( curMillis - preMillis >= 1000 ) {  // delay(1000);
        preMillis = curMillis;
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
        Serial.print(ledState);
    }
    delay(1000);
}
