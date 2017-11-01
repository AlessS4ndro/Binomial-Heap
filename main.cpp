#include <iostream>
#include<list>
#include"clases.h"

using namespace std;

int main()
{
  BinomialHeap<> heap;
  typename list<BNode<>*>::iterator menor;
  int n;
  do{
    cin>>n;
    if(n==666){
      //cout<<"q nodo eliminara: ";cin>>n;
      heap.delete_min();
      heap.print();
      continue;
    }
    heap.add(n);
    heap.print();
    menor=heap.find_min();

    cout<<"\n\n";
  }while(n!=999);




  return 0;
}
