/*20221104,zr*/
/*definition for pow2()*/
int pow22(int n) {
	int power = 1;
	int p = 2;
	while (n != 0) {
		/*check for the last bit*/
		if (n & 1) {
			power *= p;
		}
		/*update for next turn*/
		n >>= 1;
		p *= p;
	}
	return power;
}