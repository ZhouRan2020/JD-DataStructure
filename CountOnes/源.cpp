class Count_ones {
public:
	int solver(int n);
};
int Count_ones::solver(int n) {
	int ones = 0;
	while (n != 0) {
		ones += 1 & n;
		n >>= 1;
	}
	return ones;
}
int main() {
	Count_ones c;
	int f=c.solver(23);
}