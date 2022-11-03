#include"release.h"
//#include<iostream>
int main()
{
   int* p=new(int){};
   delete(p);
}
