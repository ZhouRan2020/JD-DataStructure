#include<cstdlib>
typedef int Rank;
constexpr auto DEFAULT_CAPACITY = 3;

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
	//constructor
	//一个3参数构造函数
	vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0) {
		_elem = new T[_capacity = c];  
		for (_size = 0; _size < s; _elem[_size++] = v);
	}
	//
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
	//destructor
	~vector() { 
		delete[] _elem; 
	}
	//read-only visit ADTs
	Rank size() const {
		return _size;
	}
	bool empty() const {
		return !_size;
	}
	int disordered() const;

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

	//writable visit ADTs
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
	void traverse( void(*visit)(T&) );
	template<typename VST> void traverse(VST&);
};

template<typename T>
void vector<T>::copyFrom(T const* A, Rank lo, Rank hi) {
	_elem = new T[_capacity = 2 * (hi - lo)];
	_size = 0;
	while (lo < hi) {
		_elem[_size++] = A[lo++];
	}
}

template<typename T>
vector<T>& vector<T>::operator=(vector<T> const& v) {
	if (_elem) {
		delete[] _elem;
		copyFrom(v._elem, 0, v.size());
		return *this;
	}
}

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

template<typename T>
T& vector<T>::operator[](Rank r) const {
	return _elem[r];
}

template<typename T>
void vector<T>::unsort(Rank lo, Rank hi) {
	T* v = _elem + lo;
	for (Rank i = hi - lo; i > 0; --i) {
		swap(v[i - 1], v[ rand()%i ]);
	}
}

template<typename T>
Rank vector<T>::find(T const& e, Rank lo, Rank hi) const {
	while ((lo < hi--) && (e != _elem[hi]));
	return hi;
}

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

template<typename T>
T vector<T>::remove(Rank r) {
	T e = _elem[r];
	remove(r, r + 1);
	return e;
}

template<typename T>
int vector<T>::deduplicate() {
	int oldSize = _size;
	Rank i = 1;
	while (i < _size) {
		find(_elem[i], 0, i) <0 ? ++i : remove(i);
	}
	return oldSize - _size;
}

template<typename T>
void vector<T>::traverse(void (*visit)(T&)) {
	for (int i = 0; i < _size; ++i) {
		visit(_elem[i]);
	}
}

template<typename T>
template<typename VST>
void vector<T>::traverse(VST& visit) {
	for (int i = 0; i < _size; ++i) {
		visit(_elem[i]);
	}
}

template<typename T>
int vector<T>::disordered() const {
	int n = 0;
	for (int i = 1; i < _size; i++) {
		if (_elem[i - 1] > _elem[i]) {
			++i;
		}
	}
	return n;
}

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

template<typename T>
bool vector<T>::bubble(Rank lo, Rank hi) {
	bool is_sorted = true;
	while (++lo < hi) {
		if (!(_elem[lo - 1] <= _elem[lo])) {
			is_sorted = false;
			swap(_elem[lo - 1], _elem[lo]);
		}
	}
	return sorted;
}

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











