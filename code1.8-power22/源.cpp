#include <vector>
int sqrt(int a) { return a * a; }
int pow2(int n) {
	int power = 1;
	int p = 2;
	while (n > 0) {
		if (n & 1) {
			power *= p;
		}
		n >>= 1;
		p *= p;
	}
	return power;
}
int main() {
	int c = pow2(5);
}