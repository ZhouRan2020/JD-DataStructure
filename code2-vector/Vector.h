/*20221104 by zr*/
/*for rand()*/
#include<cstdlib>
/*for class Fib*/
#include "Fib.h"
typedef int Rank;
#define DEFAULT_CAPACITY 3
/*code2.1 vector<>*/
template < typename T > 
class vector {
protected:
	Rank _size;
	int _capacity;
	T* _elem;
	void copyFrom(T const*, Rank, Rank);
	void expand();
	void shrink();
	bool bubble(Rank, Rank);
	void bubbleSort(Rank lo, Rank hi) {
		while (!bubble(lo, hi--));
	}
	Rank max(Rank lo, Rank hi);
	void selectionSort(Rank lo, Rank hi);
	void merge(Rank, Rank, Rank);
	void mergeSort(Rank lo, Rank hi);
	Rank partition(Rank lo, Rank hi);
	void quickSort(Rank lo, Rank hi);
	void heapSort(Rank lo, Rank hi);
public:
	/*constructor*/
	vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) {
		_elem = new T[_capacity = c];  
		for (_size = 0; _size < s; _elem[_size++] = v);
	}
	vector(T const* A, Rank lo, Rank hi) {
		copyFrom(A, lo, hi);
	}
	vector(T const* A, Rank n) {
		copyFrom(A, 0, n);
	}
	vector(vector<T> const& v, Rank lo, Rank hi) {
		copyFrom(v._elem, lo, hi);
	}
	vector(vector<T> const& v) {
		copyFrom(v._elem, 0, v._size);
	}
	/*destructor*/
	~vector() { 
		delete[] _elem; 
	}
	/*read-only visit ADTs*/
	Rank size() const {
		return _size;
	}
	bool empty() const {
		return !_size;
	}
	int disordered();
	Rank find(T const& e) const {
		return find(e, 0, static_cast<Rank>(_size));
	}
	Rank find(T const& e, Rank lo, Rank hi) const;
	Rank search(T const& e) const {
		return (0 >= size) ? -1 : search(e, static_cast<Rank>(0), static_cast<Rank>(_size));
	}
	Rank search(T const& e, Rank lo, Rank hi) const {
		return rand() % 2 ? binSearch(_elem, e, lo, hi) : fibSearch(_elem, e, lo, hi);
	}
	/*writable visit ADTs*/
	T& operator[](Rank r) const;
	vector<T>& operator=(vector<T> const&);
	T remove(Rank r);
	int remove(Rank lo, Rank hi);
	Rank insert(Rank r, T const& e);
	Rank insert(T const& e) { return insert(_size, e); }
	void sort(Rank lo, Rank hi) {
		switch (rand() % 5) {
		case 1:
			bubbleSort(lo, hi);
			break;
		case 2:
			selectionSort(lo, hi);
			break;
		case 3:
			mergeSort(lo, hi);
			break;
		case 4:
			heapSort(lo, hi);
			break;
		default:
			quickSort(lo, hi);
			break;
		}
	}
	void sort() { 
		sort(0, _size); 
	}
	void unsort(Rank lo, Rank hi);
	void unsort() { unsort(0, _size); }
	int deduplicate();
	int uniquify();
	/*traverse*/
	void traverse( void(*visit)(T&) );
	template<typename VST> void traverse(VST&);
};/*vector<>*/


/*code2.2 copyFrom()*/
template<typename T>
void vector<T>::copyFrom(T const* A, Rank lo, Rank hi) {
	_elem = new T[_capacity = 2 * (hi - lo)];
	_size = 0;
	while (lo < hi) {
		_elem[_size++] = A[lo++];
	}
}
/*code 2.3 assignment*/
template<typename T>
vector<T>& vector<T>::operator=(vector<T> const& v) {
	if (_elem) delete[] _elem;
	copyFrom(v._elem, 0, v.size());
	return *this;	
}


/*code 2.4 expand()*/
template<typename T>
void vector<T>::expand() {
	if (_size < _capacity) {
		return;
	}
	if (_capacity < DEFAULT_CAPACITY) {
		_capacity = DEFAULT_CAPACITY;
	}
	T* oldElem = _elem;
	_elem = new T[_capacity <<= 1];
	for (int i = 0; i < _size; ++i) {
		_elem[i] = oldElem[i];
	}
	delete[] oldElem;
}
/*code2.5 shrink()*/
template<typename T>
void vector<T>::shrink() {
	if (_capacity < DEFAULT_CAPACITY << 1) {
		return;
	}
	if (_size << 2 > _capacity) {
		return;
	}
	T* oldElem = _elem;
	_elem = new T[_capacity >>= 1];
	for (int i = 0; i < _size; ++i) {
		_elem[i] = oldElem[i];
	}
	delete[] oldElem;
}
/*code2.6 reload operator[]*/
template<typename T>
T& vector<T>::operator[](Rank r) const {
	return _elem[r];
}
/*code2.8 permute vector<> entirely*/
template<typename T>
void vector<T>::unsort(Rank lo, Rank hi) {
	T* v = _elem + lo;
	for (Rank i = hi - lo; i > 0; --i) {
		swap(v[i - 1], v[ rand()%i ]);
	}
}
/*code2.10 find(e) in a unsorted vector*/
template<typename T>
Rank vector<T>::find(T const& e, Rank lo, Rank hi) const {
	while ((lo < hi--) && (e != _elem[hi]));
	return hi;
}
/*code 2.11 insert(e) as Rank r*/
template<typename T>
Rank vector<T>::insert(Rank r, T const& e) {
	expand();
	for (int i = _size; i > r; --i) {
		_elem[i] = _elem[i - 1];
	}
	_elem[r] = e;
	++_size;
	return r;
}
/*code 2.12 remove(lo,hi)*/
template<typename T>
int vector<T>::remove(Rank lo, Rank hi) {
	if (lo == hi) return 0;
	while (hi < size) {
		_elem[lo++] = _elem[hi++];
	}
	_size = lo;
	shrink();
	return hi - lo;
}
/*code 2.13 remove Rank r*/
template<typename T>
T vector<T>::remove(Rank r) {
	T e = _elem[r];
	remove(r, r + 1);
	return e;
}
/*code 2.14 deduplicate a unsorted vector*/
template<typename T>
int vector<T>::deduplicate() {
	int oldSize = _size;
	Rank i = 1;
	while (i < _size) {
		find(_elem[i], 0, i) <0 ? ++i : remove(i);
	}
	return oldSize - _size;
}
/*code 2.15 traverse using function pointer*/
template<typename T>
void vector<T>::traverse(void (*visit)(T&)) {
	for (int i = 0; i < _size; ++i) {
		visit(_elem[i]);
	}
}
/*code 2.15 traverse using functor*/
template<typename T>
template<typename VST>
void vector<T>::traverse(VST& visit) {
	for (int i = 0; i < _size; ++i) {
		visit(_elem[i]);
	}
}
/*code 2.17 return num of inverse pair*/
template<typename T>
int vector<T>::disordered() {
	int n = 0;
	for (int i = 1; i < _size; i++) {
		if (_elem[i - 1] > _elem[i]) {
			++i;
		}
	}
	return n;
}
/*code 2.19 uniquify() a sorted vector*/
template<typename T>
int vector<T>::uniquify() {
	Rank i = 0, j = 0;
	while (++j < _size) {
		if (_elem[i] != _elem[j]) {
			_elem[++i] = _elem[j];
		}
	}
	_size = ++i;
	shrink();
	return j - i;
}
/*code2.27 bubble()*/
template<typename T>
bool vector<T>::bubble(Rank lo, Rank hi) {
	bool is_sorted = true;
	while (++lo < hi) {
		if (!(_elem[lo - 1] <= _elem[lo])) {
			is_sorted = false;
			swap(_elem[lo - 1], _elem[lo]);
		}
	}
	return is_sorted;
}
/*code 2.29 merge()*/
template<class T>
void vector<T>::merge(Rank lo, Rank mi, Rank hi) {
	T* A = _elem + lo;
	int lb = mi - lo;
	T* B = new T[lb];
	for (Rank i = 0; i < lb; B[i] = A[i++]);
	int lc = hi - mi;
	T* C = _elem + mi;
	for (Rank i = 0, j = 0, k = 0; (j < lb) || (k < lc);) {
		if ((j < lb) && ((k == lc) || (B[j] <= C[k]))) {
			A[i++] = B[j++];
		}
		if ((k < lc) && ((j == lb) || (C[k] < B[j]))) {
			A[i++] = C[k++];
		}
	}
	delete[] B;
}
/*code 2.28 mergesort()*/
template<class T>
void vector<T>::mergeSort(Rank lo, Rank hi) {
	if (hi - lo == 1) {
		return;
	}
	Rank mi = (lo + hi) / 2;
	mergeSort(lo, mi);
	mergeSort(mi, hi);
	merge(lo, mi, hi);
}
/*code 2.24 binsearch() C*/
template<typename T> 
Rank binSearch(T* A, T const& e, Rank lo, Rank hi){
	while(lo<hi){
		Rank mi=(lo+hi)>>1;
		(e<A[mi])?hi=mi:lo=mi+1;
	}
	return --lo;
}
/*code2.22 fibsearch*/
template <typename T> Rank fibSearch(T*A, T const& e, Rank lo,Rank hi){
	Fib fib(hi-lo);
	while(lo<hi){
		while(hi-lo<fib.get())fib.prev();
		Rank mi=lo+fib.get()-1;
		if (e<A[mi]) hi=mi;
		else if(A[mi]<e)lo=mi+1;
		else return mi;
	}
	return -1;
}







