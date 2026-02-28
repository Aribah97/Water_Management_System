#ifndef TURBIDITY_READER_H
#define TURBIDITY_READER_H

/**
 * TurbidityReader.h
 * Handles turbidity sensor readings and calculations
 */

class TurbidityReader {
private:
    int sensorPin;
    float voltage;
    float turbidity;
    const float REFERENCE_VOLTAGE = 5.0;
    const int ADC_RESOLUTION = 1023;
    
    // Polynomial coefficients for turbidity calculation
    // NTU = a0 + a1*V + a2*V^2
    const float A0 = 1000.0;
    const float A1 = -500.0;
    const float A2 = 100.0;

public:
    /**
     * Constructor
     * @param pin Analog pin connected to turbidity sensor
     */
    TurbidityReader(int pin);
    
    /**
     * Read and calculate turbidity value
     * @param samples Number of samples to average
     * @return Turbidity in NTU (Nephelometric Turbidity Units)
     */
    float readTurbidity(int samples = 10);
    
    /**
     * Get the last measured turbidity value
     * @return Turbidity in NTU
     */
    float getTurbidity() const;
    
    /**
     * Get the last measured voltage value
     * @return Voltage in volts
     */
    float getVoltage() const;
    
    /**
     * Check if turbidity is within acceptable range
     * @param minNTU Minimum acceptable turbidity
     * @param maxNTU Maximum acceptable turbidity
     * @return true if turbidity is within range
     */
    bool isWithinRange(float minNTU, float maxNTU) const;
};

#endif // TURBIDITY_READER_H