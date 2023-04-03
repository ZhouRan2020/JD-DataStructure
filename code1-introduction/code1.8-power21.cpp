/*20221104*/
/*facility sqrt()*/
inline int sqrt(int a) { return a * a; }
/*definition of pow2()*/
int pow21(int n) {
	if (n == 0) { return 1; }
	else {
		return (n & 1) ? sqrt(pow21(n >> 1)) << 1 : sqrt(pow21(n >> 1));
	}
}
