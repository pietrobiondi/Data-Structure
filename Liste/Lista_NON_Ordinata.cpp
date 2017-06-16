//LISTA DOPPIAMENTE CONCATENATA E NON ORDINATA
#include <iostream>
#include <cstdlib>
using namespace std;

template <class H> class Node {
	private:
		H key;
		Node<H>* next, *prev;
	public:
		Node(H x) {
			key = x;
			next = prev = NULL;
		}
		void setKey(H x) {
			key = x;
		}
		void setNext(Node<H>* next) {
			this->next = next;
		}
		void setPrev(Node<H>* prev) {
			this->prev = prev;
		}
		H getKey() { return key; }
		Node<H>* getNext() { return next; }
		Node<H>* getPrev() { return prev; }
};


template <class H> class List{
	private:
		Node<H>* head, *tail;
		int size;
		Node<H>* _search(H x) {
			Node<H>* t = head;
			while(t!=NULL) {
				if( t->getKey()==x ) return t;
				t = t->getNext();
			}
			return NULL;
		}
		
	public:
		List() { 
			head=tail=NULL; 
			size=0; 
		}
		int isEmpty() { return size==0?1:0; }
		
		List<H>* insert(H x) { //list concatenata e NON ordinata
			Node<H>* p = new Node<H>(x);
			p->setNext(head);
			if(head) head->setPrev(p);
			head = p;
			size++;
			if(!tail) tail = p;
			return this;
		}
		List<H>* tailInsert(H x) {
			Node<H>* p = new Node<H>(x);
			if(tail) tail->setNext(p);
			else head = p;
			p->setPrev(tail);
			tail = p;
			size++;
			return this;
		}
		int search(H x) {
			Node<H>* t = head;
			while(t!=NULL) {
				if( t->getKey()==x ) {
					cout << "l'elemento " << x << " e' presente\n";
					return 1;
				}
				t = t->getNext();
			}
			cout << "l'elemento " << x << " non Ã¨ presente\n";
			return 0;
		}
		List<H>* del(H x) { 
			Node<H> *node =_search(x);
			if(!node) return this;
			Node<H>* p = node->getPrev();
			Node<H>* s = node->getNext();
			if(p) p->setNext(s);
			else head = s;
			if(s) s->setPrev(p);
			else tail = p;
			size--;
			return this; 
		}
		H* getHead() {
			if(!head) return NULL;
			H *key = new H(head->getKey());
			return key;
		}
		void print() {
			cout << "[" << size << "] ";
			Node<H> *t = head;
			while( t!=NULL ) {
				cout << t->getKey() << " ";
				t = t->getNext();
			}
			cout << endl;
		}
};

int main(){

List<int> *l = new List<int>;
l->insert(50)->insert(20)->insert(78)->insert(95)->insert(5)->print();
cout << endl;
l->tailInsert(50)->tailInsert(20)->tailInsert(78)->tailInsert(95)->tailInsert(5);
l->print();
return 0;
}