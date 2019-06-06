const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
    <title>LED Control Web Server</title>
</head>

<body>
    <center>
        <h2>LED Control Web Server</h2>
        <form method="get" action="/form">
            <input type="submit" name="button" value="ON">
            <input type="submit" name="button" value="OFF">
        </form>
        LED Status: @@status@@ </br>
        <p>Designed by ORY (C) 2019 <a
                href="https://github.com/dcback/ESP8266/tree/master/Example/WebServer/IoT/ESP8266_ledControl_STA01">GithubLink.</a>
        </p>
    </center>
</body>

</html>
)=====";
