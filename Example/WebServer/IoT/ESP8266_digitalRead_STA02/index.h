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
    <h2 style="color:blue;">Digital Monitoring Web Server</h2>
    <p style="color:green;">Digital Pin(D0~D8) Voltage Reading table.</p>
    <table style="width:20%" align="left">
        <tr align="center">
            <th bgcolor="#DDDDDD">Pin</th>
            <td bgcolor="#DDDDDD">Value</td>
        </tr>
        <tr align="center">
            <th>D0</th>
            <td>@@D0@@</td>
        </tr>
        <tr align="center">
            <th>D1</th>
            <td>@@D1@@</td>
        </tr>
        <tr align="center">
            <th>D2</th>
            <td>@@D2@@</td>
        </tr>
        <tr align="center">
            <th>D3</th>
            <td>@@D3@@</td>
        </tr>
        <tr align="center">
            <th>D4</th>
            <td>@@D4@@</td>
        </tr>
        <tr align="center">
            <th>D5</th>
            <td>@@D5@@</td>
        </tr>
        <tr align="center">
            <th>D6</th>
            <td>@@D6@@</td>
        </tr>
        <tr align="center">
            <th>D7</th>
            <td>@@D7@@</td>
        </tr>
        <tr align="center">
            <th>D8</th>
            <td>@@D8@@</td>
        </tr>
    </table>
</body>

</html>
)=====";
