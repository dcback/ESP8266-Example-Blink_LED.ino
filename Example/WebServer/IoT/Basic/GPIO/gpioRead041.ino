ADC_MODE(ADC_VCC);  // System Voltage Read 

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("System voltage(mV): "); 
  Serial.println(ESP.getVcc());
  delay(1000);
}
