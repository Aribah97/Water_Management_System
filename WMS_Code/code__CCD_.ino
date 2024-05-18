SoftwareSerial (12, 13);
LiquidCrystal lcd(9, 8, 7, 6, 5, 4) ; 



float turbidity = 0, flowRate = 0;
bool leak = false, valve = false;
//Standardized boolean values to true or false.

int waterLimit = 10, waterUsed = 0;
volatile byte pulseCount;

void pulseCounter() {
  pulseCount++;
}

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
  //use High and Low instead of 1 and 0 

  pinMode(flowPin, INPUT_PULLUP);
  attachInterrupt(0, pulseCounter, FALLING);
}

void loop() {
  Turbidity();
  lcdScr();
  flow();
  leakage();
  sendData();
}

void leakage() {
  uint32_t interval_ms = 60000;
  static uint32_t time3;
// Remove redundant condition in leakage function

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

void Turbidity() {
  float volt = 0;
  for (int i = 0; i < 100; i++) {
    volt += (analogRead(turbidityPin) / 1023.0) * 5;
    delay(5);
    // Remove unwanted delay 
  }
  volt /= 100;
  volt = round_to_dp(volt, 2);

  if (volt < 2.5) turbidity = 3000;
  else turbidity = -1120.4 * sq(volt) + 5742.3 * volt - 4353.8;
}

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

void sendData() {
  static uint32_t time1;
  if (millis() - time1 > 1000) {
      //Simplified sending data to sserial using String concatenation//
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

float round_to_dp(float in_value, int decimal_place) {
  float multiplier = powf(10.0f, decimal_place);
  in_value = roundf(in_value * multiplier) / multiplier;
  return in_value;
}
