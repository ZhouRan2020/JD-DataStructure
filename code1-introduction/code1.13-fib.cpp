/*
We can assume that each f() is equipped with a obj prevprev;
each f() does two things:
1.side-effect: modify his caller's prevprev using what his callee tells him;
2.return value: tell his caller's previous value to his caller.
*/
//linear recursion T(n)=O(n)
//every f() with a int
int fib_lr1(int n,int& prev) {
	int prevprev;
	if (n == 0) {
		prev = 1;
		return 0;
	}
	prev = fib_lr1(n - 1, prevprev);
	return prevprev + prev;
}
//use a common int
int fib_lr2(int n, int& prev) {
	if (n == 0) {
		prev = 1;
		return 0;
	}
	int p = fib_lr2(n - 1, prev);
	int pp = prev;
	prev = p;
	return p + pp;
}