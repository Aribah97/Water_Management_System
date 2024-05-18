SoftwareSerial:
  sserial:
    RX: 12
    TX: 13

LiquidCrystal:
  lcd:
    pins: [9, 8, 7, 6, 5, 4]

Variables:
  float:
    - turbidity: 0
    - flowRate: 0
  bool:
    - leak: false
    - valve: false
  int:
    - waterLimit: 10
    - waterUsed: 0
  volatile byte:
    - pulseCount: 0

Functions:
  pulseCounter:
    description: Increments the pulse count for flow rate measurement.
    implementation: |
      void pulseCounter() {
        pulseCount++;
      }

  setup:
    description: Initializes serial communication, pins, LCD, and flow sensor interrupt.
    implementation: |
      void setup() {
        Serial.begin(115200);
        sserial.begin(9600);

        pinMode(valvePin, OUTPUT);
        digitalWrite(valvePin, LOW);

        lcd.begin(16, 2);
        lcd.setCursor(0, 0);
        lcd.print("  Water Meter   ");
        delay(5000);
        lcd.clear();
        
        digitalWrite(valvePin, HIGH);

        pinMode(flowPin, INPUT_PULLUP);
        attachInterrupt(0, pulseCounter, FALLING);
      }

  loop:
    description: Main loop calling functions for turbidity, LCD update, flow rate, leak detection, and data transmission.
    implementation: |
      void loop() {
        Turbidity();
        lcdScr();
        flow();
        leakage();
        sendData();
      }

  leakage:
    description: Detects leaks and controls the valve based on water usage, turbidity, and flow rate.
    implementation: |
      void leakage() {
        uint32_t interval_ms = 60000;
        static uint32_t time3;

        if (millis() - time3 > interval_ms) {
          digitalWrite(valvePin, HIGH);
          if (millis() - time3 > interval_ms + 5000){
            bool leak_ = (flowRate > 0.00f);
            if (millis() - time3 > interval_ms + 5000) {
              leak = leak_;
              time3 = millis();
            }
          }
        } else {
          valve = (waterUsed >= waterLimit || turbidity >= 3000 || leak);
          digitalWrite(valvePin, valve ? LOW : HIGH);
        }
      }

  flow:
    description: Calculates flow rate from pulse counts and updates total water usage.
    implementation: |
      void flow() {
        static uint32_t previousMillis, totalMilliLitres;
        static float totalLitres;

        if (millis() - previousMillis > 1000) {
          uint16_t pulse1Sec = pulseCount;
          pulseCount = 0;

          flowRate = ((1000.0 / (millis() - previousMillis)) * pulse1Sec) / 4.5;
          previousMillis = millis();

          uint32_t flowMilliLitres = (flowRate / 60) * 1000;
          float flowLitres = (flowRate / 60);

          totalMilliLitres += flowMilliLitres;
          totalLitres += flowLitres;
          waterUsed = totalLitres;

          Serial.println(flowRate);
          Serial.println(waterUsed);
        }
      }

  Turbidity:
    description: Measures and calculates the turbidity of water.
    implementation: |
      void Turbidity() {
        float volt = 0;
        for (int i = 0; i < 100; i++) {
          volt += (analogRead(turbidityPin) / 1023.0) * 5;
          delay(5);
        }
        volt /= 100;
        volt = round_to_dp(volt, 2);

        if (volt < 2.5) turbidity = 3000;
        else turbidity = -1120.4 * sq(volt) + 5742.3 * volt - 4353.8;
      }

  lcdScr:
    description: Manages LCD display, rotating through screens showing turbidity, leak status, valve state, and water usage.
    implementation: |
      void lcdScr() {
        static uint32_t time1;
        static byte screen = 0;

        if (millis() - time1 > 3000) {
          lcd.clear();
          time1 = millis();
          screen++;
          if (screen > 2) screen = 0;
        }

        switch (screen) {
          case 0:
            lcd.setCursor(0, 0);
            lcd.print("   Turbidity    ");
            lcd.setCursor(0, 1);
            lcd.print("  ");
            lcd.print(turbidity);
            lcd.print(" NTU");
            break;

          case 1:
            lcd.setCursor(0, 0);
            lcd.print(leak ? "Leakage Detected" : "   No Leakage   ");
            lcd.setCursor(0, 1);
            lcd.print(valve ? "  Valve Opened  " : "  Valve Closed  ");
            break;

          case 2:
            lcd.setCursor(0, 0);
            lcd.print("H2O limit: ");
            lcd.print(waterLimit);
            lcd.print("L ");
            lcd.setCursor(0, 1);
            lcd.print("H2O Used: ");
            lcd.print(waterUsed);
            lcd.print("L ");
            break;
        }
      }

  sendData:
    description: Sends system data over software serial in JSON format every second.
    implementation: |
      void sendData() {
        static uint32_t time1;
        if (millis() - time1 > 1000) {
          sserial.print(
            "{\"t\":" + String(turbidity) +
            ",\"l\":" + String(leak) +
            ",\"v\":" + String(valve) +
            ",\"wl\":" + String(waterLimit) +
            ",\"wu\":" + String(waterUsed) +
            "}"
          );
          time1 = millis();
        }
      }

  round_to_dp:
    description: Rounds a float value to the specified number of decimal places.
    implementation: |
      float round_to_dp(float in_value, int decimal_place) {
        float multiplier = powf(10.0f, decimal_place);
        in_value = roundf(in_value * multiplier) / multiplier;
        return in_value;
      }