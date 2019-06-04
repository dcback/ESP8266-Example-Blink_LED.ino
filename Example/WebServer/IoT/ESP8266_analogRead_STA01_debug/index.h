const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
    <meta http-equiv="refresh" content="3">
    <title>Analog Monitoring Web Server</title>
    <style>
        table, th, td {
            border: 1px solid black;
        }
    </style>
</head> 

<body>
    <h2>Analog Monitoring Web Server</h2>
    <p>Analog Pin(A0) Voltage Reading table.</p>
    <table style="width:100%" align="center">
        <tr>
            <th>Analog Pin</th>
            <th>Reading Value</th>
        </tr>
        <tr align="center">
            <td>A0 Pin</td>
            <td>@@temp@@</td>
        </tr>
    </table>
</body>

</html>
)=====";
