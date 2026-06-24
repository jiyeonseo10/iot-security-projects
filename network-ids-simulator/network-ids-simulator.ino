const int BTN_NORMAL = 2;
const int BTN_WARNING = 3;
const int BTN_ATTACK = 4;
const int GREEN_LED = 8;
const int YELLOW_LED = 9;
const int RED_LED = 10;
const int BUZZER = 11;

void setup() {
  Serial.begin(9600);
  pinMode(BTN_NORMAL, INPUT_PULLUP);
  pinMode(BTN_WARNING, INPUT_PULLUP);
  pinMode(BTN_ATTACK, INPUT_PULLUP);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {
  if (digitalRead(BTN_NORMAL) == LOW) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, LOW);
    noTone(BUZZER);
    Serial.println("[INFO] Traffic Normal");
    delay(300);
  }
  if (digitalRead(BTN_WARNING) == LOW) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(RED_LED, LOW);
    noTone(BUZZER);
    Serial.println("[WARNING] Suspicious Traffic");
    delay(300);
  }
  if (digitalRead(BTN_ATTACK) == LOW) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    tone(BUZZER, 1000);
    delay(3000);
    noTone(BUZZER);
    Serial.println("[ALERT] DDoS Attack Detected");
    delay(300);
  }
}
