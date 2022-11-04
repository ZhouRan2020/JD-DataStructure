#include "ListNode.h"
/*code 3.2 class list*/
template<typename T> class List{
private:
    int _size;
    ListNode<T>* header;
    ListNode<T>* trailer;
protected:
    void init();
    int clear();
    void copyNodes(ListNode<T>*,int);
    void merge(ListNode<T>*&,int);
    void selectionSort(ListNode<T>*,int);
    void insertionSort(ListNode<T>*,int);
public:
    List(){init();}
    List(List<T> const& L){
        copyNodes(L.first(),L._szie);
    }
    List(List<T> const& L,Rank r,int n){
        copyNodes(L[r],n);
    }
    List(ListNode<T>* p,int n){
        copyNodes(p,n);
    }
    ~List(){
        clear();
        delete header;
        delete trailer;
    }
/*read-only*/
    Rank size() const{return _size;}
    bool empty() const{return _size<=0;}
    T& operator[](int r)const;
    ListNode<T>* first() const {return header->succ;}
    ListNode<T>* last() const{return trailer->pred;}
    bool valid(ListNode<T>* p){
        return p&&(trailer!=p)&&(header!=p);
    }    
    int disordered()const;
    ListNode<T>* find(T const& e)const{
        return find(e,_size,trailer);
    }
    ListNode<T>* find(T const& e,int n,ListNode<T>* p)const;
    ListNode<T>* search(T const& e) const{
        return search(e,_size,trailer);
    }
    ListNode<T>* search(T const& e,int n,ListNode<T>* p)const;
    ListNode<T>* selectMax(ListNode<T>* p,int n);
    ListNode<T>* selectMax() {return selectMax(header->succ,_size);}
/*writable*/
    ListNode<T>* insertAsFirst(T const& e){
        ++_size;
        return header->insertAsSucc(e);
    }
    ListNode<T>* insertAsLast(T const& e){
        ++_size;
        return trailer->insertAsPred(e);
    }
    ListNode<T>* insertBefore(ListNode<T>* p,T const& e){
        ++_size;
        return p->insertAsPred(e);
    }
    ListNode<T>* insertAfter(ListNode<T>* p,T const& e){
        ++_size;
        return p->insertAsSucc(e);
    }
    T remove(ListNode<T>* p);
    void merge(List<T>& l){
        merge(first(),_size,l,l.first,l._size);
    }
    void sort(ListNode<T>* p,int n);
    void sort(){sort(first(),_size);}
    int deduplicate();
    int uniquify();
    void reverse();
/*traverse*/
    void traverse(void(*)(T&));
    template<typename VST> void traverse(VST&);    
};
template <typename T> void List<T>::init(){
    header=new ListNode<T>;
    trailer=new ListNode<T>;
    header->succ=trailer;
    header->pred=nullptr;
    trailer->pred=header;
    trailer->succ=nullptr;
    _size=0;
}
template<typename T>
T& List<T>::operator[](int r) const{
    ListNode<T>* p=first();
    while(0<r--)p=p->succ;
    return p->data;
}
template<typename T>
ListNode<T>* List<T>::find(T const& e, int n, ListNode<T>* p)const{
    while(0<n--) if(e==(p=p->pred)->data) return p;
    return nullptr;
}
template<typename T>
void List<T>::copyNodes(ListNode<T>* p,int n){
    init();
    while(n--){
        insertAsLast(p->data);
        p=p->succ;
    }
}
template<typename T> T List<T>::remove(ListNode<T>* p){
    T e=p->data;
    p->pred->succ=p->succ;
    p->succ->pred=p->pred;
    delete p;
    --_size;
    return e;
}
template<typename T> int List<T>::clear(){
    int oldSize=_size;
    while(0<_size)remove(header->succ);
    return oldSize;
}
template<typename T>
int List<T>::deduplicate(){
    if(_size<2)return 0;
    int oldSize=_size;
    ListNode<T>* p=header;
    Rank r=0;
    while(trailer!=(p=p->succ)){
        ListNode<T>* q=find(p->data,r,p);
        q?remove(q):++r;
    }
    return oldSize-_size;
}
template<typename T>void List<T>::traverse(void(*visit)(T&)){
    for(ListNode<T>* p=header->succ;p!=trailer;p=p->succ)
    visit(p->data);
}
template<typename T>template <typename VST>
void List<T>::traverse(VST& visit){
    for(ListNode<T>* p=header->succ;p!=trailer;p=p->succ)
    visit(p->data);
}

template<typename T> int List<T>::uniquify(){
    if(_size<2)return 0;
    int oldSize = _size;
    ListNode<T>* p;
    ListNode<T>* q;
    for(p=header,q=p->succ;trailer!=q;p=q,q=q->succ)
    if(p->data==q->data) {remove(q);q=p;}
    return oldSize-_size;
}
template<typename T>
ListNode<T>* List<T>::search(T const& e,int n,ListNode<T>* p)const{
    while(0<=n--)if(((p=p->pred)->data)<=e) break;
    return p;
}