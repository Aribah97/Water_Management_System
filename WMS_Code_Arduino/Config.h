// Config.h

// Configuration constants for the water management system

// Pin assignments
const int PUMP_PIN = 7; // Pin for water pump
const int SENSOR_PIN = A0; // Pin for water level sensor

// Thresholds
const int MAX_WATER_LEVEL = 800; // Maximum water level in millimeters
const int MIN_WATER_LEVEL = 200; // Minimum water level in millimeters

// Timing intervals
const unsigned long PUMP_DELAY = 10000; // Pump delay in milliseconds
const unsigned long SENSOR_READ_INTERVAL = 5000; // Sensor read interval in milliseconds
