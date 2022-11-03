int f(int);
int main() {
	int k = f(7);
}
int f(int n) {
	int c=1;
	int p=1;
	for (int i = 0; i < n-1; ++i) {
		c = c + p;
		p = c - p;
	}
	return c;
}