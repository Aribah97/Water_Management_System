// WMS_Code_Arduino_Refactored.ino
// Refactored main Arduino sketch code with modular architecture

#include <TurbiditySensor.h>
#include <FlowRateSensor.h>
#include <ValveControl.h>
#include <LeakDetection.h>

TurbiditySensor turbidity;
FlowRateSensor flowRate;
ValveControl valve;
LeakDetection leakDetection;

void setup() {
    Serial.begin(9600);
    turbidity.begin();
    flowRate.begin();
    valve.begin();
    leakDetection.begin();
}

void loop() {
    int turbidityValue = turbidity.read();
    float flowRateValue = flowRate.read();
    valve.control(flowRateValue);
    bool leakDetected = leakDetection.check();

    Serial.print("Turbidity: ");
    Serial.print(turbidityValue);
    Serial.print(" Flow Rate: ");
    Serial.print(flowRateValue);
    Serial.print(" Leak Detected: ");
    Serial.println(leakDetected);

    delay(1000);
}