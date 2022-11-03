int f(int,int&);
int main() {
	int p;
	int a = f(7,p);
}
int f(int n,int& prev) {
	if (n == 0) {
		prev = 0;
		return 1;
	}
	else {
		int prevprev;
		prev = f(n - 1, prevprev);
		return prevprev + prev;
	}
}