// Define pin numbers
const int soilMoisturePin = A0;  // Analog pin for soil moisture sensor
const int relayPin = 2;          // Digital pin for relay module

// Define thresholds
const int drySoilThreshold = 400; // Soil moisture level to start irrigation (adjust as needed)

void setup() {
  // Initialize serial communication
  Serial.begin(9600);

  // Initialize relay pin
  pinMode(relayPin, OUTPUT);

  // Ensure the LED (simulating the pump) is off initially
  digitalWrite(relayPin, LOW);
}

void loop() {
  // Read the value from the soil moisture sensor
  int soilMoistureValue = analogRead(soilMoisturePin);

  // Print the soil moisture value to the serial monitor
  Serial.print("Soil Moisture Value: ");
  Serial.println(soilMoistureValue);

  // Check if the soil moisture level is below the threshold
  if (soilMoistureValue < drySoilThreshold) {
    // Activate the LED (simulate water pump ON)
    digitalWrite(relayPin, HIGH);
  } else {
    // Deactivate the LED (simulate water pump OFF)
    digitalWrite(relayPin, LOW);
  }

  // Delay for a short period
  delay(1000);
}
