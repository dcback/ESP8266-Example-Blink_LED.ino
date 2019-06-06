const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<body>

    <h2>Input Type Text, Password<h2>
            <h3> HTML Form ESP8266</h3>

            <form action="/form" method="post">
                User name:</br>
                <input type="text" name="username" value=""></br>
                Password:</br>
                <input type="password" name="psw" value=""></br> </br>
                <input type="submit" value="Submit">
            </form>
            <div>
                <p>Username = @@username@@</p>
                <p>Password = @@psw@@</p>
            </div>

</body>

</html>
)=====";
