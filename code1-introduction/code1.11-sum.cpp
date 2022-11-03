int sum(int* a,int low, int high) {
	if (low == high) {
		return a[low];
	}
	else {
		int mid = (low + high) / 2;
		return sum(a,low, mid) + sum(a,mid + 1, high);
	}
	
}
int main() {
	int a[5] = { 1,2,3,4,5 };
	int s = sum(a,0,4);
}
#include <vector>