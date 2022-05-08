//list    N
//printlist  O(N) .
//makeempty  ?
//find       O(N) .
//insert     O(N) .
//remove     O(N) .
//findkth    O(1) .
//next       
//previous
#include<vector>
#include<iostream>
class list_by_vector{
private:

	std::vector<int> list;

public:
	list_by_vector():list{}{}

	size_t size() { return list.size(); }
	void printlist() {
		for (int i = 0; i < list.size(); ++i)
			std::cout << list[i]<<std::endl;
	}
	void makeempty() {

	}
	size_t find(){}
	void insert(){}
	void remove(){}
	int findkth(){}
	int next(){}
	int previous(){}

};
int main(){}
