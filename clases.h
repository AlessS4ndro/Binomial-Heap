#include<iostream>
#include<list>

using namespace std;

template<class T=int>
struct BNode
{
  T data;
  int grado;
  list<BNode<T>*> childs;
  BNode<T> *father;
  BNode(T d):data(d),grado(0),father(NULL){}
  BNode(){}
  BNode(const BNode<T> &nodo)
  {
    this->data=nodo.data;
    this->grado=nodo.grado;
    this->childs=nodo.childs;
    this->father=nodo.father;
  }
};

template<class T=int  >
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
  void delete_min();
  typename list<BNode<T>*>::iterator find_min();
  void unir(typename list<BNode<T>*>::iterator &, typename list<BNode<T>*>::iterator &);
  void up_child(typename list<BNode<T>*>::iterator );
  void print();
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
  typename list< BNode<T>* >::iterator primero=roots.begin();
  typename list< BNode<T>* >::iterator segundo=roots.begin();
  segundo++;

  if(roots.size()>1 && (*primero)->grado==(*segundo)->grado){
    //cout<<"llamando a unir con los valores "<<(*primero)->data<<" y "<<(*segundo)->data<<endl;
    unir(primero,segundo);
  }
}

template<class T>
void BinomialHeap<T>::unir(typename list<BNode<T>*>::iterator &p,typename list<BNode<T>*>::iterator &q)
{
  if((*p)->data>(*q)->data){      /// cual es el menor
    //cout<<(*q)->data<<" es menor que "<<(*p)->data<<endl;
    (*p)->father=(*q);
    (*q)->childs.push_front(*p); //// q es menor y pushea a q en sus hijos
    roots.remove(*p);        /// eliminamos a q de la lista roots
    (*q)->grado++;             //// aumenta el grado
  }
  else{
    //cout<<(*p)->data<<" es menor que "<<(*q)->data<<endl;
    (*q)->father=(*p);
    (*p)->childs.push_front(*q);
    roots.remove(*q);
    (*p)->grado++;
  }
  merge();
}

template<class T>
void view(list<BNode<T> *> lista)
{
  typename list< BNode<T>* >::iterator primero=lista.begin();
  while(primero!=lista.end()){
    cout<<"->"<<(*primero)->data<<"_"<<(*primero)->grado;
    if((*primero)->father)cout<<"f("<<(*primero)->father->data<<"_"<<(*primero)->father->grado<<")";
    primero++;
  }
  cout<<endl;

  primero=lista.begin();
  while(primero!=lista.end()){
    //cout<<"llamando a view"<<endl;
    view((*primero)->childs);
    primero++;
  }
  cout<<endl;

}
template<class T>
typename list<BNode<T>*>::iterator BinomialHeap<T>::find_min()
{
  typename list<BNode<T>*>::iterator walk=roots.begin();
  typename list<BNode<T>*>::iterator menor=roots.begin();
  while(walk!=roots.end()){
    if((*walk)->data<(*menor)->data)
      menor=walk;
    walk++;
  }

  return menor;

}
template<class T>
void BinomialHeap<T>::up_child(typename list<BNode<T>*>::iterator menor)
{
  typename list<BNode<T>*>::iterator r=roots.begin();cout<<"r es: "<<(*r)->data<<endl;
  typename list<BNode<T>*>::reverse_iterator hijoMenor=(*menor)->childs.rbegin();//empezamos por el ultimo
  BNode<T> *nuevo;

  if((*menor)->childs.size()!=0){ //chequeamos q tenga hijos el nodo a eliminar
    //cout<<"pos es: "<<(*hijoMenor)->data<<endl;
    do{ // recorremos los hijos de menor empezando del ultimo
      nuevo=(*menor)->childs.back(); // guardamos el puntero a nodo
      nuevo->father=NULL;
      //cout<<"trabajando con :"<<nuevo->data<<endl;
      (*menor)->childs.pop_back();  // eliminamos el puntero
      while(r!=roots.end()){ // recorremos en roots
        if((*r)->grado >= nuevo->grado || r==roots.end()){ // insertamos de manera ordenada
          //cout<<"insertando en grado.. "<<(*r)->grado<<"el puntero a "<<nuevo->data<<endl;
          roots.insert(r,nuevo);
          cout<<"insercion exitosa"<<endl;
          break;
        }
        r++;
      }
      hijoMenor=(*menor)->childs.rbegin();
    }while(hijoMenor!=(*menor)->childs.rend());
  }
  //cout<<"llamando a  remove\n";
  roots.remove((*menor));
  //cout<<"llamando a merge\n";
  merge();
}
template<class T>
void BinomialHeap<T>::delete_min()
{
  typename list<BNode<T>*>::iterator menor=find_min();
  cout<<"menor es: "<<(*menor)->data<<endl;
  up_child(menor);
}

template<class T>
void BinomialHeap<T>::print()
{
  view(roots);
}
