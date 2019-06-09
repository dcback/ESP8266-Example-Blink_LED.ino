const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<body>
    <center>
        <div>
            <h4>ESP8266 nodeMCU Update Webpage without refresh</h4>
        </div>
        <div style="color:gray;">
            <b>SENSOR1 Value is : <span id="sen1Value" style="color:red">0</span></b><br>
            <b>SENSOR2 Value is : <span id="sen2Value" style="color:red">0</span></b><br>
            <b>SENSOR3 Value is : <span id="sen3Value" style="color:red">0</span></b><br>
        </div>

        <script>
            function getData1() {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function () {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("sen1Value").innerHTML = this.responseText;
                    }
                };
                xhttp.open("GET", "readSen1", true);
                xhttp.send();
            }

            function getData2() {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function () {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("sen2Value").innerHTML = this.responseText;
                    }
                };
                xhttp.open("GET", "readSen2", true);
                xhttp.send();
            }

            function getData3() {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function () {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("sen3Value").innerHTML = this.responseText;
                    }
                };
                xhttp.open("GET", "readSen3", true);
                xhttp.send();
            }

            setInterval(function () {
                // Call a function repeatedly with 1 Second interval
                getData1();
                getData2();
                getData3();
            }, 1000); //1000mSeconds update rate
        </script>
        <h5>Designed by ORY (C) 2019 <a
                href="https://github.com/dcback/ESP8266/tree/master/Example/WebServer/IoT/ESP8266_ajax_STA02">GithubLink.</a>
        </h5>
    </center>
</body>

</html>
)=====";
