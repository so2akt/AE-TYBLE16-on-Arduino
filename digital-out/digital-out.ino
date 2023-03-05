/* pin numbers from DIP1 to DIP16 */
int led_nr[] = {19, 25, 3, 1, 2, 0, 5, 6, 4, 21, 23, 17};

void setup() {
  for (int i = 0; i < (int)sizeof(led_nr) / sizeof(led_nr[0]); i++)
  {
    pinMode(led_nr[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < (int)sizeof(led_nr) / sizeof(led_nr[0]); i++)
  {
    for (int j = 0; j < 2; j++)
    {
      digitalWrite(led_nr[i], 0 == (j % 2) ? HIGH : LOW);
      delay(100);
    }
  }
}
