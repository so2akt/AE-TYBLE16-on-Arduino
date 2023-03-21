#define WORK_IND_LED  6   /* P0.06 (DIP10) */

void setup() {
  pinMode(WORK_IND_LED, OUTPUT);
  digitalWrite(WORK_IND_LED, LOW);
}

void loop() {
  digitalWrite(WORK_IND_LED, LOW == digitalRead(WORK_IND_LED) ? HIGH : LOW);
  delay(500);
}
