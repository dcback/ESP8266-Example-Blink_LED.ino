const char MAIN_page[] PROGMEM = R"=====(
<!doctype html>
<html>

<head>
    <title>Gauge Value</title>
    <script src="https://www.gstatic.com/charts/loader.js" type="text/javascript"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/paho-mqtt/1.0.1/mqttws31.js" type="text/javascript"></script>
</head>

<body>
    <center>
        <h4>nodeMCU Update Gauge without Refresh</h4>

        <div style="color:gray;">
            <b>SENSOR1 Value : <span id="sen1Value" style="color:red">0</span></b><br>
        </div>
        <div id="chart_div" style="height: 200px; width: 200px;"></div>
            <b>Variable Read : <span id="Variable" style="color:green">0</span></b><br>
    </center>
</body>

<script>
    var myInfo;  // Global variable

    function getData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function () {
            if (this.readyState == 4 && this.status == 200) {
                document.getElementById("sen1Value").innerHTML = this.responseText;
                myInfo = document.getElementById("sen1Value").innerHTML = this.responseText;
                document.getElementById("Variable").innerHTML = myInfo;
            }
        };
        xhttp.open("GET", "readSen1", true);   // can Use GET, POST
        xhttp.send();
    }

    // Google Gauge
    google.charts.load('current', { 'packages': ['gauge'] });
    google.charts.setOnLoadCallback(drawChart);

    function drawChart() {

        var data = google.visualization.arrayToDataTable([
            ['My Value', 'Value'],
            ['Value', 0],
        ]);

        var options = {
            min: 0, max: 10,
            width: 200, height: 200,
            greenFrom: 7.0, greenTo: 8.0,
            yellowFrom: 8.0, yellowTo: 9.0,
            redFrom: 9.0, redTo: 10,
            minorTicks: 2,
            majorTicks: ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10"]
        };

        var chart = new google.visualization.Gauge(document.getElementById('chart_div'));

        chart.draw(data, options);

        setInterval(function () {
            getData();
            data.setValue(0, 1, myInfo);
            chart.draw(data, options);
        }, 1000);
    }
</script>

</html>

)=====";
