#pragma once


bool isValueOutOfRange(float value, float min, float max);
bool checkVitalAndAlert(const string& name, float value, float min, float max);
int vitalsOk(float temperature, float pulseRate, float spo2);
void blinkWarning();