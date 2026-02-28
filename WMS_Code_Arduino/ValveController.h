#ifndef VALVE_CONTROLLER_H
#define VALVE_CONTROLLER_H

/**
 * ValveController.h
 * Controls the water valve actuator
 */

enum ValveState {
    VALVE_OPEN = HIGH,
    VALVE_CLOSED = LOW
};

class ValveController {
private:
    int controlPin;
    ValveState currentState;
    unsigned long lastStateChangeTime;
    bool isInitialized;

public:
    /**
     * Constructor
     * @param pin Digital pin connected to valve control
     */
    ValveController(int pin);
    
    /**
     * Initialize the valve controller
     */
    void begin();
    
    /**
     * Open the valve
     * @return true if operation successful
     */
    bool openValve();
    
    /**
     * Close the valve
     * @return true if operation successful
     */
    bool closeValve();
    
    /**
     * Set valve to a specific state
     * @param state VALVE_OPEN or VALVE_CLOSED
     * @return true if operation successful
     */
    bool setState(ValveState state);
    
    /**
     * Get current valve state
     * @return Current valve state
     */
    ValveState getState() const;
    
    /**
     * Check if valve is open
     * @return true if valve is open
     */
    bool isOpen() const;
    
    /**
     * Check if valve is closed
     * @return true if valve is closed
     */
    bool isClosed() const;
    
    /**
     * Get time since last state change
     * @return Milliseconds since last state change
     */
    unsigned long timeSinceStateChange() const;
    
    /**
     * Emergency close valve
     */
    void emergencyClose();
};

#endif // VALVE_CONTROLLER_H