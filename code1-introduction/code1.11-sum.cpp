int sum2(int* a,int low, int high) {
	if (low == high) {
		return a[low];
	}
	else {
		int mid = (low + high) / 2;
		return sum2(a,low, mid) + sum2(a,mid + 1, high);
	}
}