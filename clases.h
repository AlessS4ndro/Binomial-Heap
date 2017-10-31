#include<iostream>
#include<list>

using namespace std;

template<class T>
struct BNode
{
  T data;
  int grado;
  list<BNode<T>*> childs;
  BNode(T d):data(d),grado(0){}
};

template<class T>
class BinomialHeap
{
  list< BNode<T>* > roots;
  
 public:
  BinomialHeap(){}
  void add(T );
  void merge();
  void decrease_key(BNode<T> *);
  void swap(BNode<T> *,BNode<T> *);
  //void delete(BNode<T> *);
  //void delete_min();
  BNode<T> * find_min();
  void unir(list<BNode<T>*>,list<BNode<T>*>);
  //void print();
};

template<class T>
void BinomialHeap<T>::add(T dato)
{
  roots.push_front(new BNode<T>(dato));
  merge();
}

template<class T>
void BinomialHeap<T>::merge()
{
  list< BNode<T>* >::iterator primero;
  primero;//=roots.begin();
  list< BNode<T>* >::iterator segundo;//=++primero;

  //if(segundo!=roots.end() && *(*primero)->grado==*(*(segundo))->grado){
  // unir(primero,segundo);
  //}
}

template<class T>
void BinomialHeap<T>::unir(list<BNode<T>*> p,list<BNode<T>*> q)
{



}

