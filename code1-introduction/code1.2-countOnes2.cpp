/* definition of CountOnes2()*/
int CountOnes2(int n){
	int ones{0};
	while(n){
		n&=n-1;
		ones++;
	}
	return ones;
}
