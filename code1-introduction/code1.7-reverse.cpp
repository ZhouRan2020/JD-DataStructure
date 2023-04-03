/*20221104*/
/*for std::swap()*/
#include <algorithm>
/*inteface of reverse()*/
/*main() for test*/
/*implementation of reserve()*/
void reverse_r(int* a, int low,int high) {
	/*recursion base*/
	if (low >= high) {
		return;
	}
	/*recursion*/
	std::swap(a[low],a[high]);
	reverse_r(a, low + 1, high - 1);
}