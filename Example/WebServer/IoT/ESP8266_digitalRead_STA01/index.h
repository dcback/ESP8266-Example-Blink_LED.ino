const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
    <meta http-equiv="refresh" content="3">
    <title>Analog Monitoring Web Server</title>
    <style>
        table, th, td {
            border: 1px solid gray;
            border-collapse: collapse;
        }
    </style>
</head> 

<body>
    <h2>Digital Monitoring Web Server</h2>
    <p>Digital Pin(D0~D8) Voltage Reading table.</p>
    <table style="width:100%" align="center">
        <tr>
            <th>Pin</th>
            <th>D0</th>
            <th>D1</th>
            <th>D2</th>
            <th>D3</th>
            <th>D4</th>
            <th>D5</th>
            <th>D6</th>
            <th>D7</th>
            <th>D8</th>
        </tr>
        <tr align="center">
            <td>Value</td>
            <td>@@D0@@</td>
            <td>@@D1@@</td>
            <td>@@D2@@</td>
            <td>@@D3@@</td>
            <td>@@D4@@</td>
            <td>@@D5@@</td>
            <td>@@D6@@</td>
            <td>@@D7@@</td>
            <td>@@D8@@</td>
        </tr>
    </table>
</body>

</html>
)=====";
