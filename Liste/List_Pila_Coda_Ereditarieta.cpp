//Lista /pila/coda con ereditarietà
#include <iostream>
using namespace std;
template<class H> class Node{
private:
	Node<H> *next,*prev;
	H key;
public:
	Node(H x){
		key = x;
		next = prev = NULL;
	}
	Node<H> *getNext(){return next;}
	Node<H> *getPrev(){return prev;}
	H getKey(){return key;}
	void setKey(H x){ key = x;}
	void setNext(Node<H> *next){this->next = next;}
	void setPrev(Node<H> *prev){this->prev = prev;}	
};
template<class H> class List{
protected:
	int sizeList;
	Node<H> *head,*tail;
public:
	List(){
		head = tail = NULL;
		sizeList = 0;
	}
	List<H> *headInsert(H x){
		Node<H> *t = new Node<H>(x);
		t->setNext(head);
		if(head) head->setPrev(t);
		head = t;
		sizeList++;
		return this;
	}
	List<H> *tailInsert(H x){
		Node<H> *t = new Node<H>(x);
		if(tail) tail->setNext(t);
		else head = t;
		t->setPrev(tail);
		tail = t;
		sizeList++;
		return this;
	}
	List<H> *orderInsert(H x){
		Node<H> *t = new Node<H>(x);
		sizeList++;
		if(!head){
			head = tail = t;
			return this;
		}
		if(x <= head->getKey()){
			t->setNext(head);
			head->setPrev(t);
			head = t;
			return this;
		}
		Node<H> *supp = head;
		while(supp->getNext()){
			if(supp->getKey() < x && x <= supp->getNext()->getKey()){
				supp->getNext()->setPrev(t);
				t->setNext(supp->getNext());
				t->setPrev(supp);
				supp->setNext(t);
				return this;
			}
		supp = supp->getNext();	
		}
	supp->setNext(t);
	t->setPrev(supp);
	tail = t;
	return this;	
	}
	Node<H> *search(H x){
		Node<H> *t = head;
		while(t){
			if(t->getKey() == x) return t;
			t = t->getNext();
		}
	return NULL;	
	}
	List<H> *del(H x){
		Node<H> *y = search(x);
		if(!y) return this;
		Node<H> *p = y->getPrev();
		Node<H> *s = y->getNext();
		if(p) p->setNext(s);
		else head = s;
		if(s) s->setPrev(p);
		else tail = p;
		sizeList--;
		delete y;
		return this;
	}
	void print(){
		Node<H> *t = head;
		while(t){
			cout << t->getKey() << " ";
			t = t->getNext();
		}
	cout << endl;	
	}
};

template<class H> class Queue : public List<H>{
	public:
	Queue() : List<H>(){}

	Queue<H> *dequeue(){
		if(!List<H>::head){
			cout << " Coda vuota " << endl;
			return this;
		}
		if(List<H>::head->getNext()){
			List<H>::head = List<H>::head->getNext();
			List<H>::head->setPrev(NULL);
			return this;
		}
		else{
			List<H>::head = NULL;
			return this;
		}
	}
	Queue<H>* headInsert(H x){ cout << " op nn cons ";}
	Queue<H>* orderInsert(H x){ cout << " op nn cons ";}

};

template<class H> class Pila : public List<H>{
public:
	Pila() : List<H>(){}
	Pila<H> *pop(){
	if(!List<H>::head){
			cout << " Coda vuota " << endl;
			return this;
	}
	if(List<H>::tail->getPrev()){
		List<H>::tail = List<H>::tail->getPrev();
		List<H>::tail->setNext(NULL);
		return this;
	}
	else{
		List<H>::tail = NULL;
		List<H>::head = NULL;
		return this;
	}
	}
};






int main(){
	/*List<int> *l = new List<int>;
	l->headInsert(10)->headInsert(4)->headInsert(8)->headInsert(2)->headInsert(77);
	l->del(8);
	l->print();*/
	/*Queue<int> *q = new Queue<int>;
	q->tailInsert(10)->tailInsert(4)->tailInsert(8)->tailInsert(2)->tailInsert(77);
	q->dequeue();
	q->print();*/
	Pila<int> *p = new Pila<int>;
	p->tailInsert(10)->tailInsert(4)->tailInsert(8)->tailInsert(2)->tailInsert(77);
	p->pop()->pop()->pop()->pop()->pop()->pop();
	p->print();
	return 1;
}