const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<body>
    <center>
        <div>
            <h4>ESP8266 NodeMCU Update Webpage without refresh</h4>
            <label><b>Control value1 :</b></label>
            <input type="text" maxlength="4" size="2" id="myValue1" value="0">
            <button onclick="send1()">>></button>[<span id="val1">NA</span>][<span id="value1">NA</span>]<br>
            <label><b>Control value2 :</b></label>
            <input type="text" maxlength="4" size="2" id="myValue2" value="0">
            <button onclick="send2()">>></button>[<span id="val2">NA</span>][<span id="value2">NA</span>]<br>
            <label><b>Control value3 :</b></label>
            <input type="text" maxlength="4" size="2" id="myValue3" value="0">
            <button onclick="send3()">>></button>[<span id="val3">NA</span>][<span id="value3">NA</span>]
        
        </div>

        <script>
            function send1() {
                var x = document.getElementById("myValue1").value;
                document.getElementById("val1").innerHTML = x;

                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function () {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("value1").innerHTML =
                            this.responseText;
                    }
                };
                xhttp.open("GET", "setValue1?value1=" + x, true);
                xhttp.send();
            }

            function send2() {
                var x = document.getElementById("myValue2").value;
                document.getElementById("val2").innerHTML = x;

                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function () {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("value2").innerHTML =
                            this.responseText;
                    }
                };
                xhttp.open("GET", "setValue2?value2=" + x, true);
                xhttp.send();
            }

            function send3() {
                var x = document.getElementById("myValue3").value;
                document.getElementById("val3").innerHTML = x;

                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function () {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("value3").innerHTML =
                            this.responseText;
                    }
                };
                xhttp.open("GET", "setValue3?value3=" + x, true);
                xhttp.send();
            }
            
        </script>
        <h5>Designed by ORY (C) 2019 <a
                href="https://github.com/dcback/ESP8266/tree/master/Example/WebServer/IoT/ESP8266_ajax_textSubmit_STA02">GithubLink.</a>
    </center>
</body>

</html>
)=====";
