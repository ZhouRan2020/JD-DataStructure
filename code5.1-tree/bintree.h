#include "binnode.h"
#include "release.h"
template <typename T>
class BinTree
{
protected:
    int _size;
    BinNode<T> *_root;
    int updateHeight(BinNode<T> *x);
    void updateHeightAbove(BinNode<T> *x);
public:
    BinTree() : _size{0}, _root{nullptr} {}
    ~BinTree()
    {
        if (_size > 0)
            remove(_root);
    }
    int size() const { return _size; }
    bool empty() const { return !_root; }
    BinNode<T> *root() const { return _root; }
    BinNode<T> *insertAsRoot(const T &e);
    BinNode<T> *insertAsLC(BinNode<T> *x, const T &e);
    BinNode<T> *insertAsRC(BinNode<T> *x, const T &e);
    BinNode<T> *attachAsLC(BinNode<T> *x, BinTree<T> *S);
    BinNode<T> *attachAsRC(BinNode<T> *x, BinTree<T> *S);
    int remove(BinNode<T> *x);
    BinTree<T> *secede(BinNode<T> *x);
    //    int test();
    template <typename VST>
    void travLevel(VST &visit)
    {
        if (_root)
            _root->travLevel(visit);
    }
    template <typename VST>
    void travPre(VST &visit)
    {
        if (_root)
            _root->travPre(visit);
    }
    template <typename VST>
    void travIn(VST &visit)
    {
        if (_root)
            _root->travIn(visit);
    }
    template <typename VST>
    void travPost(VST &visit)
    {
        if (_root)
            _root->travPost(visit);
    }
    bool operator<(const BinTree<T> &t) { return _root && t._root && lt(_root, t._root); }
    bool operator==(const BinTree<T> &t) { return _root && t._root && (_root == t._root); }
};



template <typename T>
int BinTree<T>::updateHeight(BinNode<T> *p)
{
    return p->height = 1 + stature(p->lchild) > stature(p->rchild) ? stature(p->lchild) : stature(p->rchild);
}

template <typename T>
void BinTree<T>::updateHeightAbove(BinNode<T> *p)
{
    while (p)
    {
        updateHeight(p);
        p = p->parent;
    }
}
/*
template <typename T>
int BinTree<T>::test()
{
   return 0;
}
*/
template <typename T>
BinNode<T> *BinTree<T>::insertAsRoot(const T &e)
{
    _size = 1;
    return _root = new BinNode<T>(e);
}
template <typename T>
BinNode<T> *BinTree<T>::insertAsLC(BinNode<T> *p, const T &e)
{
    _size++;
    p->insertAsLC(e);
    updateHeightAbove(p);
    return p->lchild;
}
template <typename T>
BinNode<T> *BinTree<T>::insertAsRC(BinNode<T> *p, const T &e)
{
    _size++;
    p->insertAsRC(e);
    updateHeightAbove(p);
    return p->rchild;
}
template <typename T>
BinNode<T> *BinTree<T>::attachAsLC(BinNode<T> *p, BinTree<T> *S)
{
    if (p->lchild = S->_root)
        p->lchild->parent = p;
    _size += S->_size;
    updateHeightAbove(p);
    S->_root = nullptr;
    S->_size = 0;
    //release *S
    release(S);
    S = nullptr;
    return p;
}
//#include"bintree.h"
template <typename T>
BinNode<T> *BinTree<T>::attachAsRC(BinNode<T> *p, BinTree<T> *S)
{
    if (p->rchild = S->_root)
        p->rchild->parent = p;
    _size += S->_size;
    updateHeightAbove(p);
    S->_root = nullptr;
    S->_size = 0;
    release(S);
    S = nullptr;
    return p;
}

template <typename T>
int BinTree<T>::remove(BinNode<T> *p)
{
    FromParentTo(*p) = nullptr;
    updateHeightAbove(p->parent);
    int n = removeAt(p);
    _size -= n;
    return n;
}

template <typename T>
BinTree<T> *BinTree<T>::secede(BinNode<T> *p)
{
    FromParentTo(*p) = nullptr;
    updateHeightAbove(p->parent);
    BinTree<T> *S = new BinTree<T>{};
    S->_root = p;
    p->parent = nullptr;
    S->_size = p->size();
    _size -= S->_size;
    return S;
}
template <typename T>
static int removeAt(BinNode<T> *p)
{
    if (!p)
        return 0;
    int n = 1 + removeAt(p->lchild) + removeAt(p->rchild);
    //if T==int, decltype(p)==T*, delete p release p&& release *p
    //if p->data is a ptr, delete p->data release *p->data
    release(p->data);
    release(p);
    return n;
}