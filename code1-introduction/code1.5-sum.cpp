/*20221103*/
/*interface of sum()*/
/*implementation of sum()*/
int sum(int a[],int n) {
	/*recursion base*/
    if (n < 1)
		return 0;
	/* recursion */
	else
		return sum(a, n - 1) + a[n - 1];
}