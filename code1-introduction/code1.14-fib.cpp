/* fib(-1)==1,fib(0)==0,fib(1)==1,fib(2)==1,... */
/* Keep on moving a fib pair window till n. */
//dynamic program with window
#include <vector>
int fib_dp1(int n) {
	int w0=1;
	int w1=0;
	for (int i = 0; i < n; ++i) {
		w1 += w0;
		w0 = w1 - w0;
	}
	return w1;
}
//dp with tbl
int fib_dp2(int n) {
	std::vector<int> tbl(n+2);
	tbl[0] = 1;
	tbl[1] = 0;
	for (int i = 1; i < n + 2; ++i) {
		tbl[i] = tbl[i - 1] + tbl[i - 2];
	}
	return tbl[n + 1];
}