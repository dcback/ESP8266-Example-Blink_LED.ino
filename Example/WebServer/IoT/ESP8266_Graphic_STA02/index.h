const char MAIN_page[] PROGMEM = R"=====(
<html>

<head>
    <title>Google Gauge with ESP8266 Web Server</title>
    <meta http-equiv="refresh" content="10" charset="utf-8">
    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
    <script type="text/javascript">
        google.charts.load('current', { 'packages': ['gauge'] });
        google.charts.setOnLoadCallback(drawChart);

        function drawChart() {

            var data = google.visualization.arrayToDataTable([
                ['Label', 'Value'],
                ['온도', @@temp@@],
                ['습도', @@humi@@],
                ['밝기', @@bright@@]
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
                data.setValue(0, 1, @@temp@@);
                chart.draw(data, options);
            }, 1000);
            setInterval(function () {
                data.setValue(1, 1, @@humi@@);
                chart.draw(data, options);
            }, 1000);
            setInterval(function () {
                data.setValue(2, 1, @@bright@@);
            chart.draw(data, options);
            }, 1000);
        }
    </script>
</head>

<body>
    <center>
        <h2>Google Gauge with ESP8266 Web Server</h2>
        <div id="chart_div" style="width: 600px; height: 180px;"></div>
        <h5>Designed by ORY (C) 2019 <a
                href="https://github.com/dcback/ESP8266/tree/master/Example/WebServer/IoT/ESP8266_Graphic_STA02">GithubLink.</a>
        </h5>
    </center>
</body>

</html>
)=====";
