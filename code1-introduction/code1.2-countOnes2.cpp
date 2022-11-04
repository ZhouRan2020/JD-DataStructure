/* definition of CountOnes2()*/
int CountOnes2(int n){
	int ones{0};
	while(n!=0){
		n&=n-1;
		ones++;
	}
	return ones;
}
/* main() for test*/
int main(){
	int res = CountOnes2(23);
}