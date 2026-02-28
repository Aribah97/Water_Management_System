#ifndef FLOW_RATE_SENSOR_H
#define FLOW_RATE_SENSOR_H

/**
 * FlowRateSensor.h
 * Handles flow rate sensor readings and water usage calculations
 */

class FlowRateSensor {
private:
    int sensorPin;
    volatile unsigned long pulseCount;
    unsigned long previousMillis;
    float flowRate;
    float totalLitres;
    float totalMillilitres;
    
    // Flow sensor calibration constant (pulses per liter)
    const float PULSE_FACTOR = 4.5; // Adjust based on your sensor
    const int TIME_INTERVAL = 1000; // 1 second interval

public:
    /**
     * Constructor
     * @param pin Digital pin connected to flow sensor
     */
    FlowRateSensor(int pin);
    
    /**
     * Initialize the sensor and attach interrupt
     */
    void begin();
    
    /**
     * Record a pulse from the flow sensor (called by interrupt)
     */
    void recordPulse();
    
    /**
     * Calculate flow rate (should be called regularly)
     * @return Flow rate in liters per minute
     */
    float calculateFlowRate();
    
    /**
     * Get the current flow rate
     * @return Flow rate in liters per minute
     */
    float getFlowRate() const;
    
    /**
     * Get total water used
     * @return Total water in litres
     */
    float getTotalLitres() const;
    
    /**
     * Get total water used in millilitres
     * @return Total water in millilitres
     */
    float getTotalMillilitres() const;
    
    /**
     * Reset water usage counters
     */
    void resetCounters();
    
    /**
     * Check if flow exceeds a threshold
     * @param threshold Flow rate threshold in LPM
     * @return true if current flow exceeds threshold
     */
    bool flowExceeds(float threshold) const;
};

#endif // FLOW_RATE_SENSOR_H