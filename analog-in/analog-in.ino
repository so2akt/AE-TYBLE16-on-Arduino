#include <math.h>

#define AD_CONV_RES (10)
#define AD_VAL_MAX (pow(2, AD_CONV_RES) - 1)

void setup() {
  pinMode(19, OUTPUT);                /* DIP1 (P0.19) */
  pinMode(3, INPUT);                  /* DIP5 (P0.03, AIN4) */
  analogReference(AR_DEFAULT);        /* valid range: 0 to VDD */
  analogReadResolution(AD_CONV_RES);  /* A/D converter resolution: 10bit (0 to 1023) */
}

void loop() {
  /* LED on DIP1 turns on if DIP5 is greater than or equal to 2.0[V] */
  if ((int32_t)((2.0 * AD_VAL_MAX) / 3.3) <= analogRead(3))
  {
    digitalWrite(19, HIGH);
  }
  else
  {
    digitalWrite(19, LOW);
  }
  delay(100);
}
