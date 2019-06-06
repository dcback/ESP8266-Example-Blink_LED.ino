const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<body>
    <h2 style="color:gray;">Submit text by Button</h2>
    <hr>
    <p style="color:blue;">Client send data(TEXT) to ESP Board<p>
    <form action="/form">
        <label>Control value :</label>
        <input type="text" maxlength="4" size="2" name="conValue" value="">
        <input type="submit" value=">>">[@@value@@]</br>
    </form> 

</body>

</html>
)=====";
