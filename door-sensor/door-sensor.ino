#define EN_UART                 /* if defined EN_UART, enable UART TxRx */
#ifdef EN_UART
  #define UART_BAUDRATE (115200)
  #undef PIN_SERIAL_TX        /* originally defined in variants/Generic/variant.h */
  #define PIN_SERIAL_TX   (1) /* DIP6 (P0.01) */
  #undef PIN_SERIAL_RX        /* originally defined in variants/Generic/variant.h */
  #define PIN_SERIAL_RX   (3) /* DIP5 (P0.03) */
  /* if want to use CTS/RTX, these defines must be in variants/Generic/variant.h
   * NOT to do so, these pin functions are not effective
   */
  //#define PIN_SERIAL_CTS  (2) /* DIP7 (P0.02) */
  //#define PIN_SERIAL_RTS  (0) /* DIP8 (P0.00) */
#endif  /* #define EN_UART */

#define WORK_IND_LED  (6)   /* DIP10 (P0.06) */
#define ILLUMI_IN     (5)   /* DIP9 (P0.05, AIN6) */
#define AD_CONV_RES   (8)   /* 8-bit: 0 - 255 */

#define ILLUMI_DARK_THRESH  (10)  /* note: observed value */

void setup() {
  #ifdef EN_UART
    Serial.begin(UART_BAUDRATE, SERIAL_8N1);
  #endif  /* #ifdef EN_UART */

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
  uint8_t illumi_sens_val = analogRead(ILLUMI_IN);

  #ifdef EN_UART
    Serial.print("illumi sens val: ");
    Serial.println(illumi_sens_val, DEC);
  #endif  /* #ifdef EN_UART */

  digitalWrite(WORK_IND_LED, ILLUMI_DARK_THRESH >= illumi_sens_val ? HIGH : LOW);
}
