const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<body>
    <center>
        <div>
            <h4>ESP8266 NodeMCU Update Webpage without refresh</h4>
            <button type="button" onclick="sendData(1)">LED ON</button>
            <button type="button" onclick="sendData(0)">LED OFF</button></br>
        </div>

        <div>
            LED State is : <span id="LEDState">NA</span>
        </div>
        <script>
            function sendData(led) {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function () {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("LEDState").innerHTML =
                            this.responseText;
                    }
                };
                xhttp.open("GET", "setLED?LEDstate=" + led, true);
                xhttp.send();
            }
        </script>
        <h5>Designed by ORY (C) 2019 <a
                href="https://github.com/dcback/ESP8266/tree/master/Example/WebServer/IoT/ESP8266_ajax_STA03">GithubLink.</a>
    </center>
</body>

</html>
)=====";
