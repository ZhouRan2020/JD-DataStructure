/*20221104*/
/*for std::swap()*/
#include <algorithm>
/*inteface of reverse()*/
void reverse(int*,int,int);
/*main() for test*/
int main() {
	int a[5] = { 0,7,7,8,1 };
	reverse(a,0,4);
}
/*implementation of reserve()*/
void reverse(int* a, int low,int high) {
	/*recursion base*/
	if (low >= high) {
	}
	/*recursion*/
	else {
		std::swap(a[low],a[high]);
		reverse(a, low + 1, high - 1);
	}
}