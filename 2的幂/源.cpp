int sqrt(int a) { return a * a; }
int pow2(int n) {
	if (n == 0) { return 1; }
	else {
		return (n & 1) ? sqrt(pow2(n >> 1)) << 1 : sqrt(pow2(n >> 1));
	}
}
int main() {
	int c = pow2(5);
}