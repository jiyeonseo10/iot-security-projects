const int ldrPin = A0;
const int ledPin = 8;
const int buzzerPin = 9;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
}

void loop() {
  int lightValue = analogRead(ldrPin);
  Serial.println(lightValue);
  if (lightValue < 500) {
    tone(buzzerPin, 1000);
  } else {
    noTone(buzzerPin);
  }
  delay(100);
}
