void reverse(int*,int,int);
int main() {
	int a[5] = { 0,7,7,8,1 };
	reverse(a, 0,4);
}
void reverse(int* a, int low,int high) {
	if (low >= high) {

	}
	else {
		int temp=a[low];
		a[low] = a[high];
		a[high] = temp;
		reverse(a, low + 1, high - 1);
	}

}