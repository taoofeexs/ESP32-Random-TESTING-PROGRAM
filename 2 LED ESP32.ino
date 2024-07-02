const int LED1 = 5;   // GPIO 5 for LED1
const int LED2 = 15;  // GPIO 15 for LED2

unsigned long previousMillisHeartbeat = 0;
unsigned long previousMillisPilot = 0;
int heartbeatState = 0;
int pilotLampState = 0;

void setup() {
  pinMode(LED1, OUTPUT);  // Set LED1 as output
  pinMode(LED2, OUTPUT);  // Set LED2 as output

  digitalWrite(LED1, HIGH);  // Turn off LED1 (active low)
  digitalWrite(LED2, HIGH);  // Turn off LED2 (active low)
}

void loop() {
  heartbeat(LED1);  // Call heartbeat function for LED1
  pilotLamp(LED2);  // Call pilot lamp function for LED2
}

void heartbeat(int pin) {
  unsigned long currentMillis = millis();
  static unsigned long delayTimes[] = {50, 50, 200, 100, 1000};
  static int index = 0;

  if (currentMillis - previousMillisHeartbeat >= delayTimes[index]) {
    previousMillisHeartbeat = currentMillis;
    if (index % 2 == 0) {
      digitalWrite(pin, LOW);  // Turn on LED1
    } else {
      digitalWrite(pin, HIGH);  // Turn off LED1
    }
    index = (index + 1) % 5;
  }
}

void pilotLamp(int pin) {
  unsigned long currentMillis = millis();
  static unsigned long delayTimes[] = {3000, 50};
  static int index = 0;

  if (currentMillis - previousMillisPilot >= delayTimes[index]) {
    previousMillisPilot = currentMillis;
    if (index % 2 == 0) {
      digitalWrite(pin, LOW);
    } else {
      digitalWrite(pin, HIGH);
    }
    index = (index + 1) % 2;
  }
}
