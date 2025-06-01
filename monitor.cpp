#include "./monitor.h"
#include <assert.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <string>

using std::cout, std::flush, std::string;
using std::this_thread::sleep_for;
using std::chrono::seconds;

void blinkWarning() {
    for (int i = 0; i < 6; i++) {
        cout << "\r* " << flush;
        sleep_for(seconds(1));
        cout << "\r *" << flush;
        sleep_for(seconds(1));
    }
    cout << "\n";
}

bool isValueOutOfRange(float value, float min, float max) {
    return value < min || value > max;
}

bool checkVitalAndAlert(const string& name, float value, float min, float max) {
    if (isValueOutOfRange(value, min, max)) {
        cout << name << " is out of range!\n";
        blinkWarning();
        return false;
    }
    return true;
}
int vitalsOk(float temperature, float pulseRate, float spo2) {
    bool tempOk = checkVitalAndAlert("Temperature", temperature, 95.0, 102.0);
    bool pulseOk = checkVitalAndAlert("Pulse Rate", pulseRate, 60.0, 100.0);
    bool spo2Ok = checkVitalAndAlert("Oxygen Saturation", spo2, 90.0, 100.0);

    return tempOk && pulseOk && spo2Ok;
}
 
