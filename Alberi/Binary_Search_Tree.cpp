#include <iostream>
using namespace std;
#define dim 8
template<class H> class Node{
private:
	Node<H> *next,*prev,*left,*right,*parent;
	H key;
public:
	Node(){}
	Node(H x){
		key = x;
		next = prev = left = right = parent = NULL;
	}
	void setNext(Node<H> *next){this->next = next;}
	void setPrev(Node<H> *prev){this->prev = prev;}
	void setLeft(Node<H> *left){this->left = left;}
	void setRight(Node<H> *right){this->right = right;}
	void setParent(Node<H> *parent){this->parent = parent;}
	Node<H> *getNext(){return next;}
	Node<H> *getPrev(){return prev;}
	Node<H> *getLeft(){return left;}
	Node<H> *getRight(){return right;}
	Node<H> *getParent(){return parent;}
	void setKey(H x){ this->key = x;}
	H getKey(){return key;}
	int isLeaf(){
		if( !getRight() && !getLeft()) return 1;
		return 0;
	}
};

template<class H> class BST{
private:
	Node<H> *root;
public:
	BST(){root = NULL;}
	Node<H> *getMax(Node<H> *x){
		if(!x) return NULL;
		while(x->getRight()) x  = x->getRight();
		return x;
	}
	Node<H> *getMin(Node<H> *x){
		if(!x) return NULL;
		while(x->getLeft()) x = x->getLeft();
		return x;
	}
	Node<H> *getNext(Node<H> *x){
		if(x == getMax(root)) return NULL;
		if(x->getRight()) return getMin(x->getRight());
		while(x->getParent()->getKey() <= x->getKey()) x = x->getParent();
		return x->getParent();
	}
	BST<H> *insBST(H x){
		Node<H> *t = new Node<H>(x);
		if(!root){ root = t; return this;}
		Node<H> *supp1 = root, *supp2 = NULL;
		while(supp1){
			supp2 = supp1;
			if(supp1->getKey() > x) supp1 = supp1->getLeft();
			else supp1 = supp1->getRight();
		}
	if(x <= supp2->getKey()) supp2->setLeft(t);
	else supp2->setRight(t);
	t->setParent(supp2);
	return this;	
	}
	Node<H> *rec_search(H x, Node<H> *r){
		if(!r) return NULL;
		if(r->getKey() == x) return r;
		if(r->getKey() > x) return rec_search(x,r->getLeft());
		else return rec_search(x,r->getRight());
	}
	void _inOrder(Node<H> *r){
		if(!r) return;
		_inOrder(r->getLeft());
		cout << r->getKey() << " ";
		_inOrder(r->getRight());
	}
	void inorder(){
		_inOrder(root);
		cout << endl;
		return;
	}
	BST<H> *_del(H x,Node<H> *r){
		Node<H> *t = rec_search(x,r);
		if(!t) return this;
		if(t->isLeaf()){
			Node<H> *p = t->getParent();
			if(!p){root = NULL; return this;}
			if(p->getLeft()== t) p->setLeft(NULL);
			else p->setRight(NULL);
			return this;
		}
		if(! (t->getLeft() && t->getRight()) ){
			Node<H> *f = t->getLeft();
			if(!f) f = t->getRight();
			Node<H> *p = t->getParent();
			if(!p) { root = f; return this;}
			if(p->getLeft() == t) p->setLeft(f);
			else p->setRight(f);
			f->setParent(p);
			return this;
		}
	Node<H> *n = getNext(t);
	t->setKey(n->getKey());
	_del(n->getKey(),t->getRight());
	return this;
	}
	BST<H> *delBST(H x){
		_del(x,root);
		return this;
	}
};


int main(){
	BST<int> *a = new BST<int>;
	a->insBST(5)->insBST(3)->insBST(8)->insBST(1)->insBST(9);
	a->delBST(5);
	a->inorder();
	return 1;
}