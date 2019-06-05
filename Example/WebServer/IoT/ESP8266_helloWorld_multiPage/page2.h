const char htmlPage2[] PROGMEM = R"=====(
<html>

<head>
    <meta http-equiv="content-type" content="text/html;charset=UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/css/bootstrap.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.1/js/bootstrap.min.js"></script>
    <title>nodeMCU Web Server - Page2</title>
</head>

<body>
    <div class="container">
        <h1>nodeMCU Web Page</h1>
        <p style="color:blue;">nodeMCU multiPage Web Server - Page2.</p>
        <p>
            <a class="btn btn-primary" href="/" role="button">nodeMCU site Link</a>
            <a class="btn btn-success disabled" href="/page2" role="button">nodeMCU webPage</a>
            <a class="btn btn-danger" href="/page3" role="button">nodeMCU IoT WebServer</a>
        </p>

        <h1>[H1] 이 가장 큰 문자 Size입니다.</h1>
        <h2>[H2] 는 두 번째로 큰 문자 Size입니다.</h2>
        <h3>[H3] 는 세 번째로 큰 문자 Size입니다.</h3>
        <h4>[H4] 기업/직업선택 기준은 대기업이나 공무원처럼 안정성이나 연봉이 아닌, 언제 어디서나 환영받는
            <b>최고의 생존기술</b>을 배울 수 있는지를 기준으로 삼아야 한다.</h4>
        <h5>[H5] 사후가 있건 없건 내리 사랑과 봉사만이 인간 존재의 이유이다. 이는 세상 모든 종교의
            원리이며 가르침이다. <b>진정한 신은 우리 곁에 어렵고 힘든 이웃</b>이다. 물질이든 시간이든 정신이든
            지식이든 내 가진 모든 것을 헌납하고 삶의 종착지에선 조용히 웃으며 홀연히 떠나는 것이다</h5>
        <h6>[H6] 아낌없이 주는 나무가 있습니다.열매를, 시원한 그늘을, 나중엔 잘려나가,그루터기 의자로 남아 지친
            이의 쉼터가 되어주는.. 어떤 나무도 자신을 위해 자라지 않습니다. 자신을 위해 그늘을 만들지 않습니다</h6>
        <p>[p] Hello from ESP8266 HTTP Server. Selection of <b>Bootstrap</b> CSS styles.</p>
        <h1>Buttons</h1>
        <p>
            <button type="button" class="btn btn-default">Default</button>
            <button type="button" class="btn btn-primary">Primary</button>
            <button type="button" class="btn btn-success">Success</button>
            <button type="button" class="btn btn-info">Info</button>
            <button type="button" class="btn btn-warning">Warning</button>
            <button type="button" class="btn btn-danger">Danger</button>
            <button type="button" class="btn btn-link">Link</button>
        </p>
        <h1>Alerts</h1>
        <div class="alert alert-success" role="alert">
            <strong>Well done!</strong> You successfully read this important alert message.
        </div>
        <div class="alert alert-info" role="alert">
            <strong>Heads up!</strong> This alert needs your attention, but it's not super important.
        </div>
        <div class="alert alert-warning" role="alert">
            <strong>Warning!</strong> Best check yo self, you're not looking too good.
        </div>
        <div class="alert alert-danger" role="alert">
            <strong>Oh snap!</strong> Change a few things up and try submitting again.
        </div>
        <p>Designed by ORY (C) 2019 <a
                href="https://github.com/dcback/ESP8266/tree/master/Example/WebServer/IoT/ESP8266_helloWorld_multiPage">GithubLink.</a>
        </p>
    </div>
</body>

</html>
)=====";
