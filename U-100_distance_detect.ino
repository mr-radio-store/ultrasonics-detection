/*
HC-SR04 Ultrasonic Sensor

Wire Connection
Wiring (HC-SR04 to Arduino Uno)
HC-SR04 Pin	Arduino Uno Pin
VCC	5V
GND	GND
Trig	D9
Echo	D10

***
Expected Result:
Distance: 23.4 cm
Distance: 24.1 cm
Distance: 25.0 cm
***
*/

const int trigPin = 9;
const int echoPin = 10;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration;
  float distance_cm;

  // Trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Echo response time
  duration = pulseIn(echoPin, HIGH, 25000);  // 25ms timeout

  if (duration == 0) {
    Serial.println("No echo received");
  } else {
    distance_cm = duration * 0.034 / 2;
    Serial.print("Distance: ");
    Serial.print(distance_cm, 1);
    Serial.println(" cm");
  }

  delay(500);  // Wait half a second
}
