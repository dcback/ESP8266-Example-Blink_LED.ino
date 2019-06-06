const char htmlPage3[] PROGMEM = R"=====(
<html>

<head>
    <meta http-equiv="content-type" content="text/html;charset=UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
    <title>nodeMCU Web Server - Page3</title>
</head>

<body>
    <div class="container">
        <h1>nodeMCU Web Server</h1>
        <p style="color:blue;">nodeMCU multiPage Web Server - Page3.</p>
        <p>
            <a class="btn btn-primary" href="/" role="button">nodeMCU site Link</a>
            <a class="btn btn-success" href="/page2" role="button">nodeMCU webPage</a>
            <a class="btn btn-danger disabled" href="/page3" role="button">nodeMCU IoT WebServer</a>
        </p>
        <div class='row'>
            <div class='col-md-12'>
                <h3>Sensing & Control Mini station </h3>
                <ul class='nav nav-pills'>
                    <li class='active'>
                        <a href='#'> <span class='badge pull-right'>25 &deg;C</span> Temperature</a>
                    </li>
                    <li class='active'>
                        <a href='#'> <span class='badge pull-right'>40 %</span> Humidity</a>
                    </li>
                    <li class='active'>
                        <a href='#'> <span class='badge pull-right'>450 ppm</span> Value of CO2</a></li>
                </ul>
                <table class='table'>
                    <thead>
                        <tr class='active'>
                            <th>Sensor</th>
                            <th>Measure</th>
                            <th>Value</th>
                            <th>Previous Value</th>
                        </tr>
                    </thead>
                    <tbody>
                        <tr>
                            <td>BME280</td>
                            <td>Temperature</td>
                            <td>25 &deg;C</td>
                            <td>20 &deg;C</td>
                        </tr>
                        <tr>
                            <td>BME280</td>
                            <td>Humidity</td>
                            <td>40 %</td>
                            <td>35 %</td>
                        </tr>
                        <tr>
                            <td>MH-Z16</td>
                            <td>CO2</td>
                            <td>450 ppm</td>
                            <td>500 ppm</td>
                        </tr>
                    </tbody>
                </table>
                <h3>GPIO</h3>
                <div class='row'>
                    <div class='col-md-4'>
                        <h4 class='text-left'>D4<span class='badge'>ON</span></h4>
                    </div>
                    <div class='col-md-4'>
                        <form action='/' method='POST'><button type='button submit' name='D4' value='1'
                                class='btn btn-success btn-lg'>ON</button></form>
                    </div>
                    <div class='col-md-4'>
                        <form action='/' method='POST'><button type='button submit' name='D4' value='0'
                                class='btn btn-danger btn-lg'>OFF</button></form>
                    </div>
                    <div class='col-md-4'>
                        <h4 class='text-left'>D5<span class='badge'>OFF</span></h4>
                    </div>
                    <div class='col-md-4'>
                        <form action='/' method='POST'><button type='button submit' name='D5' value='1'
                                class='btn btn-success btn-lg'>ON</button></form>
                    </div>
                    <div class='col-md-4'>
                        <form action='/' method='POST'><button type='button submit' name='D5' value='0'
                                class='btn btn-danger btn-lg'>OFF</button></form>
                    </div>
                    <div class='col-md-4'>
                        <h4 class='text-left'>D6<span class='badge'>OFF</span></h4>
                    </div>
                    <div class='col-md-4'>
                        <form action='/' method='POST'><button type='button submit' name='D6' value='1'
                                class='btn btn-success btn-lg'>ON</button></form>
                    </div>
                    <div class='col-md-4'>
                        <form action='/' method='POST'><button type='button submit' name='D6' value='0'
                                class='btn btn-danger btn-lg'>OFF</button></form>
                    </div>
                    <div class='col-md-4'>
                        <h4 class='text-left'>D7<span class='badge'>OFF</span></h4>
                    </div>
                    <div class='col-md-4'>
                        <form action='/' method='POST'><button type='button submit' name='D7' value='1'
                                class='btn btn-success btn-lg'>ON</button></form>
                    </div>
                    <div class='col-md-4'>
                        <form action='/' method='POST'><button type='button submit' name='D7' value='0'
                                class='btn btn-danger btn-lg'>OFF</button></form>
                    </div>
                </div>
                <p>Designed by ORY (C) 2019 <a
                        href="https://github.com/dcback/ESP8266/tree/master/Example/WebServer/IoT/ESP8266_helloWorld_multiPage">GithubLink.</a>
                </p>
            </div>
        </div>
</body>

</html>
)=====";
