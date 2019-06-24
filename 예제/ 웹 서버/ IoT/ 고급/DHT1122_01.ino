// Vcc = 3.3V, DTH11(D3). DHT22(D4)
#include "DHT.h"

//DHT11
#define DHTPIN11 D3         // what pin we're connected to
#define DHTTYPE11 DHT11     // DHT 11
DHT dht11(DHTPIN11, DHTTYPE11);

//DHT22
#define DHTPIN22 D4         // what pin we're connected to
#define DHTTYPE22 DHT22     // DHT 22
DHT dht22(DHTPIN22, DHTTYPE22);

void setup() {
    Serial.begin(115200);
    dht11.begin();
    dht22.begin();
}

void loop() {
    // Wait a few seconds between measurements.
    delay(2000);

    // Read DHT11 temperature as Celsius
    float tempDHT11 = dht11.readTemperature();
    float humiDHT11 = dht11.readHumidity();
    float f1 = dht11.readTemperature(true);

    // Check if any reads failed and exit early (to try again).
    if (isnan(humiDHT11) || isnan(tempDHT11) || isnan(f1)) {
        Serial.println("Failed to read from DHT22 sensor!");
        return;
    }

    // Compute heat index in Fahrenheit (the default)
    float hif1 = dht11.computeHeatIndex(f1, humiDHT11);
    // Compute heat index in Celsius (isFahreheit = false)
    float hic1 = dht11.computeHeatIndex(tempDHT11, humiDHT11, false);

    Serial.print("DHT11 Temperature: ");
    Serial.print(tempDHT11); Serial.print(" *C");
    Serial.print("\t Humidity: ");
    Serial.print(humiDHT11); Serial.println(" %");

    // Read DHT22 temperature as Celsius
    float tempDHT22 = dht22.readTemperature();
    float humiDHT22 = dht22.readHumidity();
    float f2 = dht22.readTemperature(true);

    // Check if any reads failed and exit early (to try again).
    if (isnan(humiDHT22) || isnan(tempDHT22) || isnan(f2)) {
        Serial.println("Failed to read from DHT22 sensor!");
        return;
    }

    // Compute heat index in Fahrenheit (the default)
    float hif2 = dht11.computeHeatIndex(f2, humiDHT22);
    // Compute heat index in Celsius (isFahreheit = false)
    float hic2 = dht11.computeHeatIndex(tempDHT22, humiDHT22, false);

    Serial.print("DHT22 Temperature: ");
    Serial.print(tempDHT22); Serial.print(" *C");
    Serial.print("\t Humidity: ");
    Serial.print(humiDHT22); Serial.println(" %");
}
