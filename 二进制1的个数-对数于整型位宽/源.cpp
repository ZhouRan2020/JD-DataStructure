#define POW(c) (1<<c)
#define MASK(c) (((unsigned long)-1) / (POW(POW(c)) + 1))

#define round(n,c) ((n)&MASK(c)+(n>>(POW(c))&MASK(c)))

int countones(unsigned int n) {
	n = round(n, 0);
	n = round(n, 1);
	n = round(n, 2);
	n = round(n, 3);
	n = round(n, 4);
	return n;
}

int main() {
	//unsigned int  y=((unsigned int)-1);
	int c = countones((unsigned int)-1);
}