#include "FlowRateSensor.h"

// Global pointer for interrupt handler
FlowRateSensor* flowSensorInstance = nullptr;

// Interrupt service routine
void pulseCounterISR() {
    if (flowSensorInstance != nullptr) {
        flowSensorInstance->recordPulse();
    }
}

FlowRateSensor::FlowRateSensor(int pin) 
    : sensorPin(pin), pulseCount(0), previousMillis(0), 
      flowRate(0.0), totalLitres(0.0), totalMillilitres(0.0) {
    flowSensorInstance = this;
}

void FlowRateSensor::begin() {
    pinMode(sensorPin, INPUT);
    attachInterrupt(digitalPinToInterrupt(sensorPin), pulseCounterISR, RISING);
}

void FlowRateSensor::recordPulse() {
    pulseCount++;
}

float FlowRateSensor::calculateFlowRate() {
    unsigned long currentMillis = millis();
    unsigned long elapsedMillis = currentMillis - previousMillis;
    
    if (elapsedMillis >= TIME_INTERVAL) {
        // Calculate flow rate: (pulses per second) / pulses per liter * 60 seconds per minute
        flowRate = ((1000.0 / elapsedMillis) * pulseCount) / PULSE_FACTOR;
        
        // Update total water usage
        float flowMillilitres = (flowRate / 60.0) * 1000.0; // Convert to mL per interval
        float flowLitres = (flowRate / 60.0);
        
        totalMillilitres += flowMillilitres;
        totalLitres += flowLitres;
        
        // Reset for next interval
        pulseCount = 0;
        previousMillis = currentMillis;
    }
    
    return flowRate;
}

float FlowRateSensor::getFlowRate() const {
    return flowRate;
}

float FlowRateSensor::getTotalLitres() const {
    return totalLitres;
}

float FlowRateSensor::getTotalMillilitres() const {
    return totalMillilitres;
}

void FlowRateSensor::resetCounters() {
    totalLitres = 0.0;
    totalMillilitres = 0.0;
    pulseCount = 0;
    flowRate = 0.0;
}

bool FlowRateSensor::flowExceeds(float threshold) const {
    return flowRate > threshold;
}