const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<body>
    <center>
        <div>
            <h4>ESP8266 NodeMCU Update Webpage without refresh</h4>
            <label><b>Control value :</b></label>
            <input type="text" maxlength="4" size="2" id="myValue" value="0">
            <button onclick="send()">>></button><br>
            Input Value : <span id="val">NA</span><br>
            Feedback Value : <span id="value">NA</span>
        </div>

        <script>
            function send() {
                var x = document.getElementById("myValue").value;
                document.getElementById("val").innerHTML = x;

                var xhttp = new XMLHttpRequest();
                xhttp.onreadystatechange = function () {
                    if (this.readyState == 4 && this.status == 200) {
                        document.getElementById("value").innerHTML =
                            this.responseText;
                    }
                };
                xhttp.open("GET", "setValue?value=" + x, true);
                xhttp.send();
            }

        </script>
        <h5>Designed by ORY (C) 2019 <a
                href="https://github.com/dcback/ESP8266/tree/master/Example/WebServer/IoT/ESP8266_ajax_textSubmit_STA01">GithubLink.</a>
    </center>
</body>

</html>
)=====";
