#include <algorithm>
void reverse(int* A, int lo, int hi){
    while(lo<hi) std::swap(A[lo++],A[hi--]);
}