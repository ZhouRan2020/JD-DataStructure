/*20221103*/
/* definition of CountOnes1()*/
int countOnes1(int n) {
	int ones = 0;
	/*check every bit of n, using ones to count*/
	while (n != 0) {
		ones += 1 & n;
		n >>= 1;
	}
	return ones;
}
/*main() for test*/
int main() {
	int res = countOnes1(23);
}
