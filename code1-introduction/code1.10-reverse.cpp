#include <algorithm>
void reverse(int* A, int lo, int hi){
    while(lo<hi) std::swap(A[lo++],A[hi--]);
}
int main(){
    int A[5]={0,7,7,8,1};
    reverse(A,0,4);
}