#define WORK_IND_LED  (6)   /* DIP10 (P0.06) */
#define ILLUMI_IN     (5)   /* DIP9 (P0.05, AIN6) */
#define AD_CONV_RES   (8)   /* 8-bit: 0 - 255 */

#define ILLUMI_DARK_THRESH  (10)  /* note: observed value */

void setup() {
  /* pin direction settings */
  pinMode(ILLUMI_IN, INPUT);
  pinMode(WORK_IND_LED, OUTPUT);

  /* A/D converter settings */
  analogReference(AR_DEFAULT);  /* range: 0[V] - VDD */
  analogReadResolution(AD_CONV_RES);

  /* output initial settings */
  digitalWrite(WORK_IND_LED, LOW);
}

void loop() {
  digitalWrite(WORK_IND_LED, ILLUMI_DARK_THRESH >= analogRead(ILLUMI_IN) ? HIGH : LOW);
}
