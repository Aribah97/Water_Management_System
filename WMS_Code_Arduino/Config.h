// Config.h

#ifndef CONFIG_H
#define CONFIG_H

// Pin assignments
const int pinRelay1 = 2;
const int pinRelay2 = 3;
const int pinSensor1 = A0;
const int pinSensor2 = A1;

// Thresholds
const int thresholdWaterLevel = 500;
const int thresholdSoilMoisture = 300;

// Timing intervals (in milliseconds)
const int intervalWatering = 60000; // 60 seconds
const int intervalSensorRead = 5000; // 5 seconds

// Feature flags
const bool featureAutoWatering = true;
const bool featureAlerts = false;

#endif // CONFIG_H
