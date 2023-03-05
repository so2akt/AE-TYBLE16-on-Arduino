void setup() {
  Serial.begin(9600);
}

void loop() {
  static uint32_t cnt = 0;
  Serial.print(cnt++);Serial.println(": TEST MESSAGE");
  delay(1000);
}
