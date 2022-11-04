int f(int,int&);
int main() {
	int prev{0};
	int res = f(4,prev);
}
/*
We can assume that each f() is equipped with a obj prevprev;
each f() does two things:
1.side-effect: modify his caller's prevprev using what his callee tells him;
2.return value: tell his caller's previous value to his caller.
*/
int f(int n,int& prev) {
	int prevprev{0};
	if (n == 0) {
		prev = 0;
		return 1;
	}
	else {
		prev = f(n - 1, prevprev);
		return prevprev + prev;
	}
}