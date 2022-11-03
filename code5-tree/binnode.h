#include<stack>
#include<queue>
#include<vector>
#define stature(p) ((p) ? (p)->height : -1)//p is a node* && is it nullptr?
#define IsRoot(x) (!((x).parent))//x is a node && true iff x.parent!=nullptr
#define IsLChild(x) (!IsRoot(x) && (&(x) == (x).parent->lchild))//x is a node 
#define IsRChild(x) (!IsRoot(x) && (&(x) == (x).parent->rchild))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lchild)
#define HasRChild(x) ((x).rchild)
#define HasChild(x) ( HasLChild(x) || HasRChild(x) )
#define HasBothChild(x) ( HasLChild(x) && HasRChild(x) )
#define IsLeaf(x) ( !HasChild(x) )// x is leaf iff x has child
#define sibling(p) ( IsLChild(*(p)) ? (p)->parent->rchild : (p)->parent->lchild )
#define uncle(p) (IsLChild(*((p)->parent)) ? (p)->parent->parent->rchild : (p)->parent->parent->lchild)
#define FromParentTo(x) (IsRoot(x) ? _root : (IsLChild(x) ? (x).parent->lchild : (x).parent->rchild))
template <typename T>
static bool lt(T *a, T *b) { return lt(*a, *b); }
template <typename T>
static bool lt(T &a, T &b) { return a < b; }
template <typename T>
static bool eq(T *a, T *b) { return eq(*a, *b); }
template <typename T>
static bool eq(T &a, T &b) { return a == b; }
enum class RBColor
{
    RB_RED,
    RB_BLACK
};
template <typename T>
struct BinNode
{
    //member
    T data;
    BinNode<T> *parent;
    BinNode<T> *lchild;
    BinNode<T> *rchild;
    int height;
    int npl;
    RBColor color;
    //
    BinNode() : data{}, parent{nullptr}, lchild{nullptr}, rchild{nullptr}, height{0}, npl{1}, color{RBColor::RB_RED} {}
    BinNode(T e, BinNode<T> *p = nullptr, BinNode<T> *l = nullptr, BinNode<T> *r = nullptr,
            int h = 0, int n = 1, RBColor c = RBColor::RB_RED)
        : data{e}, parent{p}, lchild{l}, rchild{r}, height{h}, npl{n}, color{c} {}
    //
    int size();
    BinNode<T> *insertAsLC(const T &);
    BinNode<T> *insertAsRC(const T &);
    BinNode<T> *succ();
    //
    template <typename VST>
    void travLevel(VST &);
    template <typename VST>
    void travPre(VST &);
    template <typename VST>
    void travIn(VST &);
    template <typename VST>
    void travPost(VST &);
    //
    bool operator<(const BinNode &bn) { return data < bn.data; }
    bool operator==(const BinNode &bn) { return data == bn.data; }
};
template <typename T>
BinNode<T> *BinNode<T>::insertAsLC(const T &e)
{
    return lchild = new BinNode(e, this);
}
template <typename T>
BinNode<T> *BinNode<T>::insertAsRC(const T &e)
{
    return rchild = new BinNode(e, this);
}
template<typename T> BinNode<T>* BinNode<T>::succ(){
    BinNode<T>* s=this;
    if(rchild){
        s=rchild;
        while(HasLChild(*s))
            s=s->lchild;
    }
    else{
        while(IsRChild(*s))
            s=s->parent;
        s=s->parent;
    }
    return s;
}
template<typename T>
template<typename VST>
void BinNode<T>::travLevel(VST &visit)
{
    //  auto gen = std::bind(std::uniform_int_distribution<int>{}, std::default_random_engine{});
    switch (1)
    {
    case 1:
        travLevel_I1(this, visit);
        break;
    case 2:
  //      travIn_I2(this, visit);
        break;
    case 3:
    //    travIn_I3(this, visit);
        break;
    case 4:
      //  travIn_I4(this, visit);
        break;
    case 5:
        //travIn_R(this, visit);
        break;
    }
}
template<typename T>
template<typename VST>
void BinNode<T>::travPost(VST &visit)
{
    //  auto gen = std::bind(std::uniform_int_distribution<int>{}, std::default_random_engine{});
    switch (1)
    {
    case 1:
        travPost_I1(this, visit);
        break;
    case 2:
   //     travIn_I2(this, visit);
        break;
    case 3:
     //   travIn_I3(this, visit);
        break;
    case 4:
       // travIn_I4(this, visit);
        break;
    case 5:
        travPost_R(this, visit);
        break;
    }
}
template<typename T>
template<typename VST>
void BinNode<T>::travPre(VST &visit)
{
    //  auto gen = std::bind(std::uniform_int_distribution<int>{}, std::default_random_engine{});
    switch (2)
    {
    case 1:
        //travIn_I1(this, visit);
        break;
    case 2:
        travPre_I2(this, visit);
        break;
    case 3:
     //   travIn_I3(this, visit);
        break;
    case 4:
        //travIn_I4(this, visit);
        break;
    case 5:
        travPre_R(this, visit);
        break;
    }
}
template <typename T>
template <typename VST>
void BinNode<T>::travIn(VST &visit)
{
    //  auto gen = std::bind(std::uniform_int_distribution<int>{}, std::default_random_engine{});
    switch (3)
    {
    case 1:
        travIn_I1(this, visit);
        break;
    case 2:
        travIn_I2(this, visit);
        break;
    case 3:
        travIn_I3(this, visit);
        break;
    case 4:
    //    travIn_I4(this, visit);
        break;
    case 5:
        travIn_R(this, visit);
        break;
    }
}
template<typename T,typename VST>
void travPre_R(BinNode<T>* x,VST& visit){
    if(!x) 
        return;
    visit(x->data);
    travPre_R(x->lchild,visit);
    travPre_R(x->rchild,visit);
}
template<typename T,typename VST>
void travPost_R(BinNode<T>* x,VST& visit){
    if(!x)
        return;
    travPost_R(x->lchild,visit);
    travPost_R(x->rchild,visit);
    visit(x->data);
}
template<typename T,typename VST>
void travIn_R(BinNode<T>* x,VST& visit){
    if(!x)
        return;
    travIn_R(x->lchild,visit);
    visit(x->data);
    travIn_R(x->rchild,visit);
}
template<typename T, typename VST>
void travPre_I2(BinNode<T>* x,VST& visit){
    std::stack<BinNode<T>*> S;
    while(true){
        visitAlongLeftBranch(x,visit,S);
        if(S.empty())
            break;
        x=S.top();
        S.pop();
    }
}
template<typename T,typename VST>
static void visitAlongLeftBranch(BinNode<T>* x,VST& visit,std::stack<BinNode<T>*>& S){
    while(x){
        visit(x->data);
        S.push(x->rchild);
        x=x->lchild;
    }
}
template<typename T,typename VST>
void travLevel_I1(BinNode<T>* x,VST& visit){
    std::queue<BinNode<T>*> Q;
    Q.push(x);
    while(!Q.empty()){
        auto t=Q.front();
        Q.pop();
        visit(t->data);
        if(HasLChild(*t))
            Q.push(t->lchild);
        if(HasRChild(*t))
            Q.push(t->rchild);
    }
}
template<typename T,typename VST>
void travPost_I1(BinNode<T>* x,VST& visit){
    std::stack<BinNode<T>*> S;
    if(x) 
        S.push(x);
    while(!S.empty()){
        if(S.top()!=x->parent)
            gotoHLVFL(S);
        x=S.top();
        S.pop();
        visit(x->data);
    }
}
template<typename T>
static void gotoHLVFL(std::stack<BinNode<T>*>& S){
    while(BinNode<T>* x=S.top())
        if(HasLChild(*x)){
            if(HasRChild(*x))
                S.push(x->rchild);
            S.push(x->lchild);
        }
        else
            S.push(x->rchild);
    S.pop();
}
template<typename T>
static void goAlongLeftBranch(BinNode<T>* x, std::stack<BinNode<T>*>& S){
    while(x){
        S.push(x);
        x=x->lchild;
    }
}
template<typename T, typename VST>
void travIn_I1(BinNode<T>* x,VST& visit){
    std::stack<BinNode<T>*> S;
    while(true){
        goAlongLeftBranch(x,S);
        if(S.empty())
            break;
        x=S.top();
        S.pop();
        visit(x->data);
        x=x->rchild;
    }
}
template<typename T,typename VST>
void travIn_I2(BinNode<T>* x,VST& visit){
    std::stack<BinNode<T>*> S;
    while(true){
        if(x){
            S.push(x);
            x=x->lchild;
        }
        else if(!S.empty()){
            x=S.top();
            S.pop();
            visit(x->data);
            x=x->rchild;
        }
        else
            break;
    }
}
template<typename T,typename VST>
void travIn_I3(BinNode<T>* x,VST& visit){
    bool backtrack{false};
    while(true)
        if(!backtrack&&HasLChild(*x))
            x=x->lchild;
        else{
            visit(x->data);
            if(HasRChild(*x)){
                x=x->rchild;
                backtrack=false;
            }else{
                if(!(x=x->succ()))
                    break;
                backtrack=true;
            }
        }
}