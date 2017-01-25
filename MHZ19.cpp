/*
 * MHZ19.cpp
 *
 *  Created on: 19.03.2016
 *      Author: Andrey Vetlugin <antrew@gmail.com>
 */

#include <Arduino.h>
#include "MHZ19.h"

MHZ19::MHZ19(int pwm_input_pin) {
	PWM_INPUT_PIN = pwm_input_pin;
	pinMode(PWM_INPUT_PIN, INPUT);
}

boolean MHZ19::low() {
	return LOW == digitalRead(PWM_INPUT_PIN);
}

boolean MHZ19::high() {
	return HIGH == digitalRead(PWM_INPUT_PIN);
}

float MHZ19::readPpm() {
	unsigned long lowCounter = 0;
	unsigned long highCounter = 0;

	// wait for low
	while (high()) {
	}

	// wait for high
	while (low()) {
	}

	// count high iterations
	while (high()) {
		highCounter++;
	}

	// count low iterations
	while (low()) {
		lowCounter++;
	}

	float ppm = 5000.0 * (1002.0 * highCounter - 2.0 * lowCounter) / 1000.0
			/ (highCounter + lowCounter);

	Serial.print("high = ");
	Serial.print(highCounter);
	Serial.print(" ; low = ");
	Serial.print(lowCounter);
	Serial.print(" ; high+low = ");
	Serial.print(highCounter + lowCounter);
	Serial.print(" ; ppm = ");
	Serial.print(ppm);
	Serial.println();

	return ppm;
}

MHZ19::~MHZ19() {
}
