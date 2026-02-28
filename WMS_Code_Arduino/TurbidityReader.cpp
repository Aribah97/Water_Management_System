#include "TurbidityReader.h"

TurbidityReader::TurbidityReader(int pin) : sensorPin(pin), voltage(0.0), turbidity(0.0) {
    pinMode(sensorPin, INPUT);
}

float TurbidityReader::readTurbidity(int samples) {
    // Read multiple samples and average
    float totalVoltage = 0.0;
    
    for (int i = 0; i < samples; i++) {
        int rawValue = analogRead(sensorPin);
        voltage = (rawValue / (float)ADC_RESOLUTION) * REFERENCE_VOLTAGE;
        totalVoltage += voltage;
        delay(10); // Small delay between readings
    }
    
    // Calculate average voltage
    voltage = totalVoltage / samples;
    
    // Calculate turbidity using polynomial formula
    // NTU = a0 + a1*V + a2*V^2
    turbidity = A0 + (A1 * voltage) + (A2 * voltage * voltage);
    
    // Ensure turbidity is not negative
    if (turbidity < 0) {
        turbidity = 0.0;
    }
    
    return turbidity;
}

float TurbidityReader::getTurbidity() const {
    return turbidity;
}

float TurbidityReader::getVoltage() const {
    return voltage;
}

bool TurbidityReader::isWithinRange(float minNTU, float maxNTU) const {
    return (turbidity >= minNTU) && (turbidity <= maxNTU);
}