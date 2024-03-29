/*20221103*/
/*<vector> is equipped with <algorithm>*/
#include <vector>
/*bubblesort function definition*/
void bubblesort(std::vector<int>& v) { 
	bool  sorted;
 	auto  n = v.size();
	/*while unsorted, keep on doing*/
	do{
		sorted=true;
		/*check every pair, if unsorted, swap them*/
		for(int i{0};i<n-1;++i){
			if(v[i]>v[i+1]){
				sorted = false;
				std::swap(v[i],v[i+1]);
			}
		}
		--n;
	}while(!sorted);
}
