const char MAIN_page[] PROGMEM = R"=====(
<!doctype html>
<html>

<head>
    <title>Gauge Value</title>
    <meta charset="utf-8">
    <script src="https://www.gstatic.com/charts/loader.js" type="text/javascript"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/paho-mqtt/1.0.1/mqttws31.js" type="text/javascript"></script>
</head>

<body>
    <center>
        <h2>nodeMCU Gauge without Refresh</h2>

        <div style="color:gray;">
            <b>온도 : <span id="tempVal" style="color:red">0 &#9; &#9; </span></b>
            &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
            <b>습도 : <span id="humiVal" style="color:red">0 &#9; &#9; </span></b>
            &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
            <b>밝기 : <span id="brightVal" style="color:red">0</span></b>
        </div>
        <div id="chart_div" style="width: 600px; height: 180px;"></div>
        <div>
            <b>Variable1 : <span id="Var1" style="color:green">0</span></b>
            &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
            <b>Variable2 : <span id="Var2" style="color:green">0</span></b>
            &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;
            <b>Variable3 : <span id="Var3" style="color:green">0</span></b>
        </div>
        <h5>Designed by ORY (C) 2019 <a
            href="https://github.com/dcback/ESP8266/tree/master/Example/WebServer/IoT/ESP8266_ajax_Graphic_STA02">GithubLink.</a>
    </center>
</body>

<script>
    var temp;   // Global variable
    var humi;   // Global variable
    var bright; // Global variable

    function getData1() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
            if (this.readyState == 4 && this.status == 200) {
                document.getElementById("tempVal").innerHTML = this.responseText;
                temp = document.getElementById("tempVal").innerHTML = this.responseText;
                document.getElementById("Var1").innerHTML = temp;
            }
        };
        xhttp.open("GET", "readSen1", true);   // can Use GET, POST
        xhttp.send();
    }

    function getData2() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
            if (this.readyState == 4 && this.status == 200) {
                document.getElementById("humiVal").innerHTML = this.responseText;
                humi = document.getElementById("humiVal").innerHTML = this.responseText;
                document.getElementById("Var2").innerHTML = humi;
            }
        };
        xhttp.open("GET", "readSen2", true);   // can Use GET, POST
        xhttp.send();
    }

    function getData3() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
            if (this.readyState == 4 && this.status == 200) {
                document.getElementById("brightVal").innerHTML = this.responseText;
                bright = document.getElementById("brightVal").innerHTML = this.responseText;
                document.getElementById("Var3").innerHTML = bright;
            }
        };
        xhttp.open("GET", "readSen3", true);   // can Use GET, POST
        xhttp.send();
    }

    // Google Gauge
    google.charts.load('current', { 'packages': ['gauge'] });
    google.charts.setOnLoadCallback(drawChart);

    function drawChart() {

        var data = google.visualization.arrayToDataTable([
            ['Label', 'Value'],
            ['온도', 50],
            ['습도', 50],
            ['밝기', 50]
        ]);


        var options = {
            width: 600, height: 180,
            redFrom: 90, redTo: 100,
            yellowFrom: 75, yellowTo: 90,
            minorTicks: 5
        };

        var chart = new google.visualization.Gauge(document.getElementById('chart_div'));

        chart.draw(data, options);

        setInterval(function () {
            getData1();
            data.setValue(0, 1, temp);
            chart.draw(data, options);
        }, 1000);

        setInterval(function () {
            getData2();
            data.setValue(1, 1, humi);
            chart.draw(data, options);
        }, 1000);

        setInterval(function () {
            getData3();
            data.setValue(2, 1, bright);
            chart.draw(data, options);
        }, 1000);
    }
</script>

</html>

)=====";
