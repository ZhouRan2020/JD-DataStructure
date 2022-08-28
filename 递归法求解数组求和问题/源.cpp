int sum(int[],int);
int main() {
	int a[5]={1,2,3,4,5};
	int c=sum(a,5);
}
int sum(int a[],int n) {
    if (n == 1)
		return a[0];
	else
		return sum(a, n - 1) + a[n - 1];
}