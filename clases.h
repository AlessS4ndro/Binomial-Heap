#include<iostream>

using namespace std;

template<class T>
struct BNode
{
  T data;
  int grado;
  BNode<T> *father;
  BNode<T> *brother;
  BNode<T> *hermano;
 
  BNode(T d):data(d),father(NULL),brother(NULL),hermano(NULL);
  
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
  void print();
};

void add(T dato)
{
  BNode<T> *nuevo=new BNode<T>(data);
  B
}

