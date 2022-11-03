#include "bintree.h"
#include <iostream>
template<typename T>
struct Plusone{
    void operator() (T& data){
        data=data+1;
    }
};
template<typename T>
struct Pri{
    void operator() (const T& data){
        std::cout<<data<<'\t';
    }
};
int main(int argc, char **argv)
{
    BinTree<int> tree{};
    tree.insertAsRoot(1);
    auto h10 = tree.insertAsLC(tree.root(), 2);
    auto h11 = tree.insertAsRC(tree.root(), 3);
    tree.insertAsLC(h10, 4);
    tree.insertAsRC(h10, 5);
    tree.insertAsLC(h11, 6);
    tree.insertAsRC(h11, 7);
    int sz = tree.size();
    Plusone<int> p{};
    Pri<int> pr{};
    tree.travIn(pr);
    std::cout<<std::endl;
    tree.travIn(p);
    tree.travIn(pr);
    auto pp=tree.root();
    while(pp){
        pr(pp->data);
        pp=pp->succ();
    }
    std::cout<<std::endl;    
}
