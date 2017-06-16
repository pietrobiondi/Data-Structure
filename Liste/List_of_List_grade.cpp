#include <iostream>
using namespace std;

template<class H> class Node{
private:
	Node<H> *next,*prev;
	H *key;
	H chiave;
public:
	Node(H *x){
		key = x;
		next = prev = NULL;
	}
	Node(H _chiave){
		chiave = _chiave;
		next = prev = NULL;
	}
	H *getKey(){ return key;}
	H getChiave(){return chiave;}
	Node<H> *getNext(){return next;}
	Node<H> *getPrev(){return prev;}
	void setNext(Node<H> *next){this->next = next;}
	void setPrev(Node<H> *prev){this->prev = prev;}
	void setKey(H *x){ this->key = x;}
	void setChiave(H _chiave){ this->chiave = _chiave;}
};

template<class H> class List{
private:
	Node<H> *head,*tail;
public:	
	List<H>(){ head = tail = NULL;}
	void headInsertList(H *x){
		Node<H> *t = new Node<H>(x);
		t->setNext(head);
		if(head) head->setPrev(t);
		head = t;
		return;
	}
	void printList(){
		Node<H> *t = head;
		while(t){
			cout << *t->getKey() << " ";
			t = t->getNext();
		}
	}
	Node<H> *search(H x){
		Node<H> *t = head;
		while(t){
			if(x == *t->getKey() ) return t;
			t = t->getNext();
		}
	return NULL;
	}
	void delList(H *x){
		Node<H> *y = search(*x);
		if(!y) return;
		Node<H> *p = y->getPrev();
		Node<H> *s = y->getNext();
		if(p) p->setNext(s);
		else head = s;
		if(s) s->setPrev(p);
		else tail = p;
		return;
	}
	Node<H> *getHead(){return head;}
};

template<class H> class Cl{
private:
	Node<H> *head,*tail;
public:
	int sizeCl;	
	Cl<H>(){ 
		sizeCl = 0;
		head = tail = NULL;
	}
	void insertCl(H x){
		Node<H> *t = new Node<H>(x);
		sizeCl++;
		if(!head){
			head = tail = t;
			t->setNext(t);
			t->setPrev(t);
			return;
		}
		else{
			t->setNext(head);
			tail->setNext(t);
			t->setPrev(tail);
			head->setPrev(t);
			tail = t;
			return;
		}
	}
    void printListCirc(){
      Node<H> *n = head;
      int cont = 0;
      while(cont < sizeCl ){
        cout << n->getChiave() << " ";
        n = n->getNext();
        cont++;
      }
      cout << endl;
    }
 
    Node<H> *search (H x){
      Node<H> *supp = head;
      while(supp){
        if( supp->getChiave()==x ) return supp;
        supp = supp->getNext();
        if(supp == head) return NULL;
      }
      return NULL;
    }
	void delCl(H x){
		Node<H> *y = search(x);
		if(!y) return;
		Node<H> *p = y->getPrev();
		Node<H> *s = y->getNext();
		if(y == head) head = s;
		if(y == tail) tail = p;
		if(p) p->setNext(s);
		if(s) s->setPrev(p);
		sizeCl--;
		return;
	}
	int getSize(){return sizeCl;}
};

template<class H> class LOL{
private:
	List< Cl<H> > *l;
public:
	LOL(){ l = NULL;}
	void insertLOL(H x){
		if(l == NULL){
			l = new List< Cl<H> >;
			Cl<H> *c = new Cl<H>;
			l->headInsertList(c);
		}
		if(l->getHead()->getKey()->getSize() == 4){
			Cl<H> *c = new Cl<H>;
			l->headInsertList(c);
		}
		if(l->getHead()->getKey()->getSize() < 4){
			l->getHead()->getKey()->insertCl(x);
			return;
		}
	}
	void printLoT(){
		Node< Cl<H> > *t = l->getHead();
		while(t){
			t->getKey()->printListCirc();
			t = t->getNext();
		}
	}
	void delLoL(H x){
		Node< Cl<H> > *t = l->getHead();
		while(t){
			t->getKey()->delCl(x);
			t = t->getNext();
		}
	}

};


int main(){
	LOL<int> *l = new LOL<int>;
	l->insertLOL(2);
	l->insertLOL(3);
	l->insertLOL(1);
	l->insertLOL(5);

	l->insertLOL(3);
	l->insertLOL(7);
	l->insertLOL(6);
	l->insertLOL(1);

	l->insertLOL(2);
	l->insertLOL(4);
	l->insertLOL(5);
	l->insertLOL(3);

	l->insertLOL(2);
	l->insertLOL(1);

	l->delLoL(5);
	l->delLoL(1);
	l->delLoL(2);

	l->printLoT();

	return 1;
}