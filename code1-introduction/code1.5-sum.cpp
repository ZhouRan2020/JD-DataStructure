/*20221103*/
/*interface of sum()*/
int sum(int[],int);
/*main() for test*/
int main() {
	int a[5]={1,2,3,4,5};
	int res=sum(a,5);
}
/*implementation of sum()*/
int sum(int a[],int n) {
	/*recursion base*/
    if (n < 1)
		return 0;
	/* recursion */
	else
		return sum(a, n - 1) + a[n - 1];
}