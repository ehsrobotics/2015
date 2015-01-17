/** ehs library 2015
 */

/** Converts controller values into motor values on a quadratic curve.
 *  Takes a value between -127 and 127. It outputs an int between -127 and 127 along
 *  a quadratic curve. The equation is \f$y = \frac{1}{127}x^2\f$
 */
int quadraticAccelerationGeneral(int input /*! input from the controller (an int between -127 and 127) */, float max) {
	if (input < 0) {
		return (int) ((1.0 / max) * input * input * -1);
	}
	else {
		return (int) ((1.0 / max) * input * input);
	}
}

int quadraticAcceleration(int input /*! input from the controller (an int between -127 and 127) */) {
	return quadraticAccelerationGeneral(input, 127.0);
}

void move(short power, int turn, int duration) {
	motor[port2] = power + turn;
	motor[port3] = power - turn;
	wait1Msec(duration);
	motor[port2] = 0;
	motor[port3] = 0;
}

void lift(short power, int duration) {
	motor[port1] = power;
	motor[port10] = power;
	motor[port4] = power;
	motor[port5] = power;
	wait1Msec(duration);
	motor[port1] = 0;
	motor[port10] = 0;
	motor[port4] = 0;
	motor[port5] = 0;
}

short simonAcceleration(short input) {
	// adjust sensitivity to Simon's own custom made curve
	return (short) (7.0 * pow(input - 115.0, 1.0/1.96) + 78.8 );
}

void liftManual(short power) {
	motor[port1] = -1*quadraticAcceleration(power);
	motor[port10] = -1*quadraticAcceleration(power);
	motor[port4] = -1*quadraticAcceleration(power);
	motor[port5] = quadraticAcceleration(power);
}

short getMoveRight(short power, int turn) {
	return power + turn;
}

short getMoveLeft(short power, int turn) {
	return power - turn;
}

void step(short rightPower, short leftPower, short liftPower, int ms) {
	motor[port1] = liftPower;
	motor[port10] = liftPower;
	motor[port2] = leftPower;
	motor[port3] = rightPower;
	motor[port6] = leftPower;
	motor[port7] = rightPower;
	wait1Msec(ms);
	motor[port1] = 0;
	motor[port10] = 0;
	motor[port2] = 0;
	motor[port3] = 0;
	motor[port4] = 0;
	motor[port5] = 0;
}

void liftWithFinesse(short power, int duration) {
	for (int i = 1; i >= 10; i++) {
		motor[port1] = power / 10 * i;
	  motor[port10] = power / 10 * i;
	  wait1Msec(30);
	}
	motor[port1] = power;
  motor[port10] = power;

	wait1Msec(duration - 600);
	motor[port1] = 0;
	motor[port10] = 0;
}
