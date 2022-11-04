int f(int);
/* fib[0]==1,fib[1]==1,fib[2]==2,...,...*/
int main() {
	int res = f(4);
}
/*keep on moving a fib pair window till n*/
int f(int n) {
	int p=0;
	int c=1;
	for (int i = 0; i < n; ++i) {
		c = c + p;
		p = c - p;
	}
	return c;
}