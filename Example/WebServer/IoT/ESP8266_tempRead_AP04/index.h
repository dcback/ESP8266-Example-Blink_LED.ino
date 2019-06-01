const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
    <meta http-equiv="refresh" content="3" charset="utf-8">
    <title>Temperature Monitoring Web Server</title>
</head>

<body>
    <center>
        <h1 style="color:Blue;">온도 모니터링 웹 서버</h1>
        <div>
            <h2 style="color:Green;">온도 : @@temp@@ &deg;C</h2>
        </div>
    </center>
</body>
</html>
)=====";
