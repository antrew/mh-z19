/*
 * MHZ19.h
 *
 *  Created on: 19.03.2016
 *      Author: Andrey Vetlugin <antrew@gmail.com>
 */

#ifndef MHZ19_H_
#define MHZ19_H_

#include <Arduino.h>

class MHZ19 {
public:
	MHZ19(int pwm_input_pin);
	float readPpm();
	virtual ~MHZ19();
private:
	int PWM_INPUT_PIN;
	boolean low();
	boolean high();
};

#endif /* MHZ19_H_ */
