const char MAIN_page[] PROGMEM = R"=====(
<html>

<head>
    <meta http-equiv="refresh" content="5">
    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
    <script type="text/javascript">
        google.charts.load('current', { 'packages': ['gauge'] });
        google.charts.setOnLoadCallback(drawChart);
        function drawChart() {

            var data = google.visualization.arrayToDataTable([
                ['Label', 'Value'],
                ['Analog', @@value@@],
            ]);

            var options = {
                width: 200, height: 200,
                greenFrom: 500, greenTo: 900,
                redFrom: 900, redTo: 1024,
                yellowFrom: 750, yellowTo: 900,
                minorTicks: 5,
                max: 1024
            };

            var chart = new 
            google.visualization.Gauge(document.getElementById('chart_div'));
            chart.draw(data, options);
        } 
    </script>
</head>

<body>
    <center>
        <h2>google.visualization.Gauge</h2>
        <div id="chart_div" style="width:200px; height: 200px;"></div>
        <h5>Designed by ORY (C) 2019 <a
                href="https://github.com/dcback/ESP8266/tree/master/Example/WebServer/IoT/ESP8266_Graphic_STA01">GithubLink.</a>
        </h5>
    </center>
</body>

</html>
)=====";
