/*
  min(bright) : 0
  max(dark)   : 4095
  normal      : 800 - 900
*/

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  int analogLight = analogRead(2);
  Serial.print("Sensor light: ");
  Serial.println(analogLight);
  delay(1000);
}
