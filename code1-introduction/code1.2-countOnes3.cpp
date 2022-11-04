/*Macro*/
#define POW(c) (1<<(c))
#define MASK(c) (((unsigned long)-1) / (POW(POW(c)) + 1))
#define round(n,c) (((n)&MASK(c))+((n)>>POW(c)&MASK(c)))
/*definition of CountOnes3()*/
int countOnes3(unsigned int n) {
	n = round(n, 0);
	n = round(n, 1);
	n = round(n, 2);
	n = round(n, 3);
	n = round(n, 4);
	return n;
}
/*main() for test*/
int main() {
	int res = countOnes3(23);
}