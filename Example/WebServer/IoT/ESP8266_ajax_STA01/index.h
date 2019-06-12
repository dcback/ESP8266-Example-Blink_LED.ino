const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<body>
    <center>
        <div>
            <h3>nodeMCU Gauge without Refresh</h3>
        </div>
        <div style="color:gray;">
            <b>SENSOR1 Value is : <span id="sen1Value" style="color:red">0</span></b><br>
        </div>

        <script>
            function getData() {
                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function () {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("sen1Value").innerHTML =
                            this.responseText;
                    }
                };
                xhttp.open("GET", "readSen1", true);
                xhttp.send();
            }

            setInterval(function () {
                // Call a function repeatedly with 1 Second interval
                getData();
            }, 1000); //1000mSeconds update rate
        </script>

        <h5>Designed by ORY (C) 2019 <a
                href="https://github.com/dcback/ESP8266/tree/master/Example/WebServer/IoT/ESP8266_ajax_STA01">GithubLink.</a>
        </h5>
    </center>
</body>

</html>
)=====";
