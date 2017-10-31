#include <iostream>
#include<list>
#include"clases.h"

using namespace std;

int main()
{
  BinomialHeap<int> heap;

  int n;
  do{
    cin>>n;
    heap.add(n);
    heap.print();
  }while(n!=0);
  



  return 0;
}
