#include <iostream>
using namespace std;
template <class H> class Node{
	private:
		H *key;
		H chiave;
		Node<H> *next, *prev, *right, *left, *parent;
	public:
		Node(H x){
			chiave = x;
			next = prev = right = left = parent = NULL;
		}
		Node(H *x){
			key = x;
			next = prev = right = left = parent = NULL;
		}
		void setNext(Node<H> *next){this->next = next;}
		void setPrev(Node<H> *prev){this->prev = prev;}
		void setLeft(Node<H> *left){this->left = left;}
		void setRight(Node<H> *right){this->right = right;}
		void setParent(Node<H> *parent){this->parent = parent;}
		void setKey(H *x){this->key = x;}
		void setChiave(H x){chiave = x;}
		Node<H> *getNext(){return next;}
		Node<H> *getPrev(){return prev;}
		Node<H> *getLeft(){return left;}
		Node<H> *getRight(){return right;}
		Node<H> *getParent(){return parent;}
		H *getKey(){return key;}
		H getChiave(){return chiave;}
		int isLeaf(){
			if(!getLeft() && !getRight()) return 1;
			return 0;
		}
};

template <class H> class List{
private:
	Node<H> *head, *tail;
public:
	List(){head = tail = NULL;}
	void insertList(H *x){
		Node<H> *n = new Node<H>(x);
		if(!head){
			head = tail = n;
			return;
		}
		n->setNext(head);
		head->setPrev(n);
		head = n;
		return;
	}
	Node<H> *search(H x){
		Node<H> *n = head;
		while(n){
			if(x == *n->getKey()) return n;
			n = n->getNext();
		}
		return NULL;
	}
	void del(H *x){
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
	void print(){
		Node<H> *n = head;
		while(n){
			cout << *n->getKey() << " ";
			n = n->getNext();
		}
		cout << endl;
	}
	Node<H> *getHead(){return head;}
};

template<class H> class BST{
private:
	Node<H> *root;
	int k;
public:
	BST<H>(){
		root = NULL;
		k = 0;
	}
	int getGr(){return k;}
	Node<H> *getRoot(){return root;}
	Node<H> *getMax(Node<H> *x){
		if(!x) return NULL;
		while(x->getRight()) x = x->getRight();
		return x;
	}
	Node<H> *getMin(Node<H> *x){
		if(!x) return NULL;
		while(x->getLeft()) x = x->getLeft();
		return x;
	}
	Node<H> *getNext(Node<H> *x){
		if(getMax(root) == x) return NULL;
		if(x->getRight()) return getMin(x->getRight());
		while(x->getParent()->getChiave() <= x->getChiave()) x = x->getParent();
		return x->getParent();
	}
	void insertBST(H x){
		Node<H> *t = new Node<H>(x);
		k++;
		if(!root){
			root = t;
			return;
		}
		Node<H> *supp1 = root, *supp2 = NULL;
		while(supp1){
			supp2 = supp1;
			if(supp1->getChiave() > x) supp1 = supp1->getLeft();
			else supp1 = supp1->getRight();
		}
		if(x <= supp2->getChiave()) supp2->setLeft(t);
		else supp2->setRight(t);
		t->setParent(supp2);
		return;
	}
	Node<H> *rec_Search(H x,Node<H> *y){
		if(!y) return NULL;
		if(y->getChiave() == x) return y;
		if(y->getChiave() > x) return rec_Search(x, y->getLeft());
		else return rec_Search(x , y->getRight());
	}
	void _del(H x, Node<H> *r){
		Node<H> *t = rec_Search(x,r);
		if(!t) return;
		if(t->isLeaf()){
			k--;
			Node<H> *p = t->getParent();
			if(!p){ root = NULL; return;}
			if(p->getLeft() == t) p->setLeft(NULL);
			else p->setRight(NULL);
			return;
		}
		if(! (t->getLeft() && t->getRight() )){
			k--;
			Node<H> *p = t->getParent();
			Node<H> *f = t->getLeft();
			if(!f) f = t->getRight();
			if(!p){ root = f; return;}
			if(p->getLeft() == t) p->setLeft(f);
			else p->setRight(f);
			f->setParent(p);
			return;
		}
		Node<H> *n = getNext(t);
		t->setChiave(n->getChiave());
		_del(n->getChiave(), t->getRight());
		return;

	}
	void delBST(H x){
		_del(x,root);
		return;
	}
	void inOrder(Node<H> *x){
		if(!x) return;
		inOrder(x->getLeft());
		cout << x->getChiave() << " ";
		inOrder(x->getRight());
	}
	void inOrderPrint(){
		inOrder(root);
		cout << endl;
	}
};

template<class H> class LOT{
private:
	List< BST<H> > *lot;
public:
	LOT() { lot = NULL;}

	void insertLoT(H x){
		if(lot == NULL){
			lot = new List< BST<H> >; //creo la strut
			BST<H> *t = new BST<H>;
			lot->insertList(t);
		}
		if(lot->getHead()->getKey()->getGr() == 4){
			BST<H> *t = new BST<H>;
			lot->insertList(t);
		}
		if(lot->getHead()->getKey()->getGr() < 4){
			lot->getHead()->getKey()->insertBST(x);
			return;
		}
	}
	void printLoT(){
		Node< BST<H> > *t = lot->getHead();
		while(t){
			t->getKey()->inOrderPrint();
			t = t->getNext();
		}
	}
	void delLoT(H x){
		Node< BST<H> > *t = lot->getHead();
		while(t){
			t->getKey()->delBST(x);
			t = t->getNext();
		}
	}
	
};

int main(){
	LOT<int> *l = new LOT<int>;
	l->insertLoT(2);
	l->insertLoT(3);
	l->insertLoT(1);
	l->insertLoT(5);

	l->insertLoT(3);
	l->insertLoT(7);
	l->insertLoT(6);
	l->insertLoT(1);

	l->insertLoT(2);
	l->insertLoT(4);
	l->insertLoT(5);
	l->insertLoT(3);

	l->insertLoT(2);
	l->insertLoT(1);
	l->delLoT(5);
	l->delLoT(1);
	l->delLoT(2);

	l->printLoT();
	return 1;
}