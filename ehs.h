/** ehs library 2015
 */

/** Converts controller values into motor values on a quadratic curve.
 *  Takes a value between -127 and 127. It outputs an int between -127 and 127 along
 *  a quadratic curve. The equation is \f$y = \frac{1}{127}x^2\f$
 */
int quadraticAcceleration(int input /*! input from the controller (an int between -127 and 127) */) {
	if (input < 0) {
		return (int) ((1.0/127.0) * input * input * -1);
	}
	else {
		return (int) ((1.0/127.0) * input * input);
	}
}
