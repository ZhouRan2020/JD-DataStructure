/*20221104*/
/*facility sqrt()*/
inline int sqrt(int a) { return a * a; }
/*definition of pow2()*/
int pow2(int n) {
	if (n == 0) { return 1; }
	else {
		return (n & 1) ? sqrt(pow2(n >> 1)) << 1 : sqrt(pow2(n >> 1));
	}
}
/*main() for test*/
int main() {
	int res = pow2(5);
}