#include <iostream>
using namespace std;
template <class H> class PBT{
public:
	virtual PBT<H>* ins(int p, H x) = 0;
	virtual H find(H x) = 0;
	virtual void print() = 0;
};

template<class H> class Node{
private:
	Node<H> *left,*right,*parent;
	H key;
	int priority;
public:
	Node(){}
	Node(int p, H x){
		this->key = x;
		priority = p;
		left = right = parent = NULL;
	}
	Node<H> *getLeft(){return left;}
	Node<H> *getRight(){return right;}
	Node<H> *getParent(){return parent;}
	void setLeft(Node<H> *left){this->left = left;}
	void setRight(Node<H> *right){this->right = right;}
	void setParent(Node<H> *parent){this->parent = parent;}
	void setKey(H x){this->key = x;}
	void setPriority(H p){this->priority = p;}
	H getKey(){return key;}
	int getPriority(){return priority;}
	int isLeaf(){
		if (!getRight() && !getLeft()) return 1;
		return 0;
	}
};

template<class H> class MyPBT : public PBT<H>{
private:
	Node<H> *root;
public:
	MyPBT(){root = NULL;}
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
	Node<H>* getNextPriority(Node<H> *x) {
		if( getMax(root) == x ) return NULL;
		if(x->getRight()) return getMin(x->getRight());
		while(x->getParent() && x->getParent()->getPriority() <= x->getPriority()) x = x->getParent();
		return x->getParent();
	}
	Node<H> *getPrevPriority(Node<H> *x){
		if(!x) return NULL;
		if(x->getLeft()) return getMax(x->getLeft());
		while(x->getParent() && x->getParent()->getPriority() >= x->getPriority()) x = x->getParent();
		return x->getParent();
	}
	MyPBT<H> *ins(int p, H x){
		Node<H> *t = new Node<H>(p,x);
		if(!root){
			root = t;
			return this;
		}
		Node<H> *supp1 = root, *supp2 = NULL;
		while(supp1){
			supp2 = supp1;
			if(supp1->getPriority() > p) supp1 = supp1->getLeft();
			else supp1 = supp1->getRight();
		}
		if(p <= supp2->getPriority()) supp2->setLeft(t);
		else supp2->setRight(t);
		t->setParent(supp2);
		return this;
	}
	Node<H> *search(H p){
		Node<H> *t = root;
		while(t){
			if(t->getPriority() == p) return t;
			if(t->getPriority() > p) t = t->getLeft();
			else t = t->getRight();
		}
	return NULL;
	}
	H find(int p){
		if(search(p)) return search(p)->getKey();
		else return 0;
	}
	void print(){
		Node<H> *t = getMax(root);
		while(t){
			cout << " " << t->getKey();
			t = getPrevPriority(t);
		}
	cout << endl;	
	}
	Node<H> *rec_search(H p, Node<H> *y){
		if(!y) return NULL;
		if(y->getPriority() == p) return y;
		if(y->getPriority() > p) return rec_search(p,y->getLeft());
		else return rec_search(p, y->getRight());
	}
	int findNodeWithKey(H x){ //cerca il nodo con KEY = X, e torna la priorità
		Node<H> *t = getMin(root);
		while(t){
			if(t->getKey() == x) {return t->getPriority();}
			t = getNextPriority(t);
		}
	return 0;	
	} 

	MyPBT<H> *del(H x){
		_del(x, root);
		return this;
	}
	MyPBT<H> *_del(H x, Node<H> *r){
		Node<H> *t = rec_search(findNodeWithKey(x), r);
		if(!t) return this;
		if(t->isLeaf()){
			Node<H> *p = t->getParent();
			if(!p) { root = NULL; return this;}
			if(p->getLeft() == t) p->setLeft(NULL);
			else p->setRight(NULL);
			return this;
		}
		if(! (t->getLeft() && t->getRight()) ){
			Node<H> *f = t->getLeft();
			if(!f) f = t->getRight();
			Node<H> *p = t->getParent();
			if(!p){root = f; return this;}
			if(p->getLeft() == t ) p->setLeft(f);
			else p->setRight(f);
			f->setParent(p);
			return this;
		}
	Node<H> *n = getNextPriority(t);
	t->setPriority(n->getPriority());
	t->setKey(n->getKey());
	_del(n->getKey(),t->getRight());
	return this;
	}

};

int main(){
	MyPBT<int> *t = new MyPBT<int>;
	t->ins(10,5)->ins(7,3)->ins(8,13)->ins(13,1)->ins(6,2)->ins(9,7);
	t->print();
	cout << " DEL " << endl;
	t->del(13);
	t->del(1);
	t->print();
	return 1;
}