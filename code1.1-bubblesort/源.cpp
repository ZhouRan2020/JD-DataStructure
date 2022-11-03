#include <vector>
class Problem_solver {
public:
	void sort(std::vector<int>& v);
};
void Problem_solver::sort(std::vector<int>& v) {
	bool sorted = true;
	int n = v.size();
	do
	{
		for (int i = 0; i < n - 1; ++i) {
			if (v[i] > v[i + 1]) {
				sorted = false;
				//
				int temp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = temp;
				//
			}
		}
	} while (!sorted);

}
int main() {
	Problem_solver p;
	std::vector<int> v = { 5,4,3,2,1 };
	p.sort(v);
}