const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<body>
    <center>
        <h4>ESP8266 NodeMCU Update Webpage without refresh</h4>
        <div>
            <button type="button" onclick="sendData1(1)">LED1 ON</button>
            <button type="button" onclick="sendData1(0)">LED1 OFF</button>
            LED1 State is : <span id="LEDState1">NA</span>
        </div>
        <div>
            <button type="button" onclick="sendData2(1)">LED2 ON</button>
            <button type="button" onclick="sendData2(0)">LED2 OFF</button>
            LED2 State is : <span id="LEDState2">NA</span>
        </div>
        <div>
            <button type="button" onclick="sendData3(1)">LED3 ON</button>
            <button type="button" onclick="sendData3(0)">LED3 OFF</button>
            LED3 State is : <span id="LEDState3">NA</span>
        </div>

        <script>
            function sendData1(led1) {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function () {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("LEDState1").innerHTML =
                            this.responseText;
                    }
                };
                xhttp.open("GET", "setLED1?LEDstate1=" + led1, true);
                xhttp.send();
            }
            function sendData2(led2) {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function () {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("LEDState2").innerHTML =
                            this.responseText;
                    }
                };
                xhttp.open("GET", "setLED2?LEDstate2=" + led2, true);
                xhttp.send();
            }
            function sendData3(led3) {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function () {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("LEDState3").innerHTML =
                            this.responseText;
                    }
                };
                xhttp.open("GET", "setLED3?LEDstate3=" + led3, true);
                xhttp.send();
            }

        </script>
        <h5>Designed by ORY (C) 2019 <a
                href="https://github.com/dcback/ESP8266/tree/master/Example/WebServer/IoT/ESP8266_ajax_STA04">GithubLink.</a>
    </center>
</body>

</html>
)=====";
