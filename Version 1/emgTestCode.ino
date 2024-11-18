int value;
int static_variable = 500;

void setup() {
  Serial.begin(9600);
}

void loop() {
  value = analogRead(A0);
  Serial.print("Sensor Value:"); // Send the label
  Serial.print(value); // Send the value
  Serial.print(",");
  Serial.print("Static_variable:");
  Serial.print(static_variable); //Send the static variable reference line
  Serial.println(); // End the line for the next data point
  delay(10); // Wait 100 milliseconds before the next read
}