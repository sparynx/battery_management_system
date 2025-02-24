// Battery Management System Code
const int voltagePin = A0;  // Voltage sensor pin
const int currentPin = A1;  // Current sensor pin
const int buzzer = 8;       // Buzzer pin
const int led = 7;          // LED indicator pin

void setup() {
    pinMode(buzzer, OUTPUT);
    pinMode(led, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    float voltage = analogRead(voltagePin) * (5.0 / 1023.0) * 11; // Voltage divider ratio
    float current = analogRead(currentPin) * (5.0 / 1023.0) * 30; // ACS712 scaling

    Serial.print("Voltage: ");
    Serial.print(voltage);
    Serial.print(" V | Current: ");
    Serial.print(current);
    Serial.println(" A");

    if (voltage < 11.5) {
        digitalWrite(buzzer, HIGH);
        digitalWrite(led, HIGH);
    } else {
        digitalWrite(buzzer, LOW);
        digitalWrite(led, LOW);
    }

    delay(1000);
}