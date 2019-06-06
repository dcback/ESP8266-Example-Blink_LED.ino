const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
    <title>LED Control Web Server</title>
</head>

<body>
    <center>
        <h2>2 LED Control Web Server</h2>
        <form method="post" action="/form">
            <label>LED1 : </label>
            <input type="submit" name="button1" value="ON">
            <input type="submit" name="button1" value="OFF">
            <label> LED1 Status: @@status1@@</label></br></br>
            <label>LED2 : </label>
            <input type="submit" name="button2" value="ON">
            <input type="submit" name="button2" value="OFF">
            <label>LED2 Status: @@status2@@</label>
        </form>
        <p>Designed by ORY (C) 2019 <a
                href="https://github.com/dcback/ESP8266/tree/master/Example/WebServer/IoT/ESP8266_ledControl_STA03">GithubLink.</a>
        </p>
    </center>
</body>

</html>
)=====";
