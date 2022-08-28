#pragma once
typedef int Rank;

template <typename T> class ListNode {
public:
	//members��Ա����
	T data;
	ListNode<T>* pred;
	ListNode<T>* succ;
	//constructor���캯��
	ListNode(){}
	ListNode(T e, ListNode<T>* p = nullptr, ListNode<T>* s = nullptr)
		:data(e), pred(p), succ(s) {}
	//
	ListNode<T>* insertAsPred(T const&);
	ListNode<T>* insertAsSucc(T const&);
};
