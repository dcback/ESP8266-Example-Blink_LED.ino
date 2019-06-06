const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
    <meta http-equiv="refresh" content="60">
    <name="viewport" content="width=device-width, initial-scale=1">
        <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
        <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.1.1/jquery.min.js"></script>
        <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
        <title>ESP8266 Demo</title>
</head>

<body>
    <div class="container">
        <h1>4 LED Control Web Server</h1>
        <div class="row">
            <div class="col-xs-4">
                <h4 class="text-left">D4 <span class="badge">@@ledGpio[1]@@</span></h4>
            </div>
            <div class="col-xs-4">
                <form action="/form" method="GET"><button type="button submit" name="D4" value="ON"
                        class="btn btn-success btn-lg">ON</button></form>
            </div>
            <div class="col-xs-4">
                <form action="/form" method="GET"><button type="button submit" name="D4" value="OFF"
                        class="btn btn-danger btn-lg">OFF</button></form></br>
            </div>
            <div class="col-xs-4">
                <h4 class="text-left">D5 <span class="badge">@@ledGpio[2]@@</span></h4>
            </div>
            <div class="col-xs-4">
                <form action="/form" method="GET"><button type="button submit" name="D5" value="ON"
                        class="btn btn-success btn-lg">ON</button></form>
            </div>
            <div class="col-xs-4">
                <form action="/form" method="GET"><button type="button submit" name="D5" value="OFF"
                        class="btn btn-danger btn-lg">OFF</button></form></br>
            </div>
            <div class="col-xs-4">
                <h4 class="text-left">D6 <span class="badge">@@ledGpio[3]@@</span></h4>
            </div>
            <div class="col-xs-4">
                <form action="/form" method="GET"><button type="button submit" name="D6" value="ON"
                        class="btn btn-success btn-lg">ON</button></form>
            </div>
            <div class="col-xs-4">
                <form action="/form" method="GET"><button type="button submit" name="D6" value="OFF"
                        class="btn btn-danger btn-lg">OFF</button></form></br>
            </div>
            <div class="col-xs-4">
                <h4 class="text-left">D7 <span class="badge">@@ledGpio[4]@@</span></h4>
            </div>
            <div class="col-xs-4">
                <form action="/form" method="GET"><button type="button submit" name="D7" value="ON"
                        class="btn btn-success btn-lg">ON</button></form>
            </div>
            <div class="col-xs-4">
                <form action="/form" method="GET"><button type="button submit" name="D7" value="OFF"
                        class="btn btn-danger btn-lg">OFF</button></form></br>
            </div>
        </div>
        <p>Designed by ORY (C) 2019 <a
                        href="https://github.com/dcback/ESP8266/tree/master/Example/WebServer/IoT/ESP8266_ledControl_STA04">GithubLink.</a>
        </p>
    </div>
</body>

</html>
)=====";
