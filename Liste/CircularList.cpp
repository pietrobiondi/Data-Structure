#include <iostream>
#include <cstdlib>
using namespace std;

template<class H> class Node{
private:
	H key;
	Node<H> *next,*prev;
public:
	Node(H x){
		key = x;
		next = prev = NULL;
	}
	Node<H>* getNext(){return next;}
	Node<H>* getPrev(){return prev;}
	H getKey(){return key;}

	void setKey(H x){this->key = x;}
	void setNext(Node<H> *next){this->next = next;}
	void setPrev(Node<H> *prev){this->prev = prev;}

};

template <class H> class circularList{
  private:
    Node<H> *head, *tail;
    int size;
    Node<H> * _search (H x){
      Node <H> *supp = head;
      while(supp){
        if( supp->getKey()==x ) return supp;
        supp = supp->getNext();
        if(supp == head) return NULL;
      }
      return NULL;
    }

  public:
   circularList(){
     size = 0;
     head = tail = NULL;
   }

   circularList<H>* insCirc(H x){
   	Node<H> *p = new Node<H>(x);
	   	if(!head){
	   		head = tail = p;
	   		p->setNext(p);
	   		p->setPrev(p);
	   		size++;
	   		return this;
	   	}
	   	tail->setNext(p);
	   	p->setPrev(tail);
	   	p->setNext(head);
	   	head->setPrev(p);
	   	head = p;
	   	size++;
	   	return this;
   }

   circularList<H>* orderInsertCirc(H x){
   	Node<H> *p = new Node<H>(x);
   		size++;
    	if(!head){
	   		head = tail = p;
	   		p->setNext(p);
	   		p->setPrev(p);
	   		return this;
	   	}
	   	if( x <= head->getKey() ){
	   		head->setPrev(p);
	   		p->setNext(head);
	   		p->setPrev(tail);
	   		tail->setNext(p);
	   		head = p;
	   		return this;
	   	}
	   	Node<H> *supp = head;
	   	while(supp->getNext() != head){
	   		if ( x >= supp->getKey() && x <= supp->getNext()->getKey() ){
	   			supp->getNext()->setPrev(p);
	   			p->setNext(supp->getNext());
	   			p->setPrev(supp);
	   			supp->setNext(p);
	   			return this;
	   		}
	   	supp = supp->getNext();
	   	}
	   	p->setPrev(supp);
		supp->setNext(p);
		p->setNext(head);
		head->setPrev(p);
		tail = p;
	   	return this;
   }

   circularList<H>* delCirc(H x){
   	Node<H> *y = _search(x);
   	if(!y) return this;
   	Node<H> *p = y->getPrev();
   	Node<H> *s = y->getNext();
   	if(y == head) head = s;
   	if(y == tail) tail = p;
   	if(p) p->setNext(s);
   	if(s) s->setPrev(p);
   	size--;
   	return this;
   }

    void printListCirc(){
    	Node<H> *supp = head;
    	while(supp){
    		cout << supp->getKey() << " ";
    		supp = supp->getNext();
    		if(supp == head) return;
    	}
    	cout << endl; 
    }
};

int main (){
	circularList<int> *c = new circularList<int>;
	c->orderInsertCirc(10)->orderInsertCirc(20)->orderInsertCirc(15)->orderInsertCirc(13)->orderInsertCirc(77);
	c->delCirc(10)->delCirc(15);
	c->printListCirc();
	return 1;
}