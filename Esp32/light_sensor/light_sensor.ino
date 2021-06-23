/*
  min(bright) : 0
  max(dark)   : 4095
  normal      : 800 - 900
*/

 if (analogValue < 10) {
   Serial.println(" - Dark");
 } else if (analogValue < 200) {
   Serial.println(" - Dim");
 } else if (analogValue < 500) {
   Serial.println(" - Light");
 } else if (analogValue < 800) {
   Serial.println(" - Bright");
 } else {
   Serial.println(" - Very bright");
 }
void setup() {
  Serial.begin(9600);
  
}

void loop() {
  int analogLight = analogRead(2);
  Serial.print("Sensor light: ");
  Serial.println(analogLight);


  if (analogValue > 3000) {
    Serial.println(" - Dark");
  } else if (analogValue > 2000) {
    Serial.println(" - Dim");
  } else if (analogValue > 700) {
    Serial.println(" - Light");
  } else if (analogValue > 300) {
    Serial.println(" - Bright");
  } else {
    Serial.println(" - Very bright");
  }

  delay(1000);
}
