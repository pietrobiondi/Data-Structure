#include <iostream>
#include <cstdlib>
using namespace std;

template <class H> class Node{
	private:
		H key;
		int mul;
		Node<H> *parent, *left, *right;
	public:
		Node(){}
		Node(H _key){
			key = _key;
			mul = 1;
			parent = left = right = NULL;
		}
		void setKey(H _key){key = _key;}
		void setParent(Node<H> *_parent){parent = _parent;}
		void setLeft(Node<H> *_left){left = _left;}
		void setRight(Node<H> *_right){right = _right;}
		void setMul(int _mul){mul = _mul;}
		void decMul() { this->mul--; }
		void incMul() { this->mul++; }

		H getKey(){return key;}
		int getMul() { return mul; }
		Node<H> *getParent(){return parent;}
		Node<H> *getRight(){return right;}
		Node<H> *getLeft(){return left;}
		int isLeaf() { 
			if( !getLeft() && !getRight() ) return 1;
			return 0; 
		}
};

template <class H> class MyMultiBST{
	private:
		Node<H> *root;

	public:
	MyMultiBST(){
	root=NULL;
	}

	 Node<H>* getMin(Node<H> *x) {
			if (x==NULL) return NULL;
			while(x->getLeft()!=NULL) x = x->getLeft();
			return x;
		}

	Node<H>* getMax(Node<H> *x) {
			if (x==NULL) return NULL;
			while(x->getRight()!=NULL) x = x->getRight();
			return x;
		}


	Node<H> *getPreva(Node<H> *node){
		if(!node)return NULL;
		if(node->getLeft()) return getMax(node->getLeft());
		while(node->getParent() && node->getParent()->getKey() >= node->getKey()) node = node->getParent();
		return node->getParent();
	}


	Node<H>* getNext(Node<H> *x) {
			if( getMax(root) == x ) return NULL;
			if(x->getRight()) return getMin(x->getRight());
			while(x->getParent()->getKey() <= x->getKey()) x = x->getParent();
			return x->getParent();
		}

	MyMultiBST<H> *ins(H x){
			Node<H> *node = new Node<H>(x);
			 if (!root) {
			 	root = node;
			 	return this;
			 }
			 Node<H> *supp1 = root, *supp2 = NULL;
			 while(supp1){
			 	supp2 = supp1;
			 	if( supp1->getKey()==x ) {
					supp1->incMul();
					return this;
				}
			 	if(supp1->getKey() > x) supp1 = supp1->getLeft();
			 	else supp1 = supp1->getRight();
			 }

			 if (x <= supp2->getKey()) supp2->setLeft(node);
			 else supp2->setRight(node);
			 node->setParent(supp2);
			 return this;
		}

	Node<H>* search(H p) {
			Node<H> *t = root;
			while(t!=NULL) {
				if(t->getKey()==p){
				cout << t->getKey()<<endl;
				return t;
				}
				if(t->getKey()>p) t = t->getLeft();
				else t = t->getRight();
			}
			return 0;
		}

 	H find(int p) {
			if( search(p) ) return p;
			return 0;
		}


	void print(){
		Node<H> *temp = getMax(root);
		while(temp){
			cout << " " << temp->getKey();
			temp = getPreva(temp);
			}
	cout << endl;
	}

	int rec_search(H x) {
		return _rec_search(x,root)!=NULL?1:0;
		}

	Node<H>* _rec_search(H x, Node<H>*y) {
		if(!y) return NULL;
		if( y->getKey()==x ) return y;
		if( y->getKey() > x ) return _rec_search(x, y->getLeft());
		else return _rec_search(x, y->getRight());
	}

	int  multiplicity(H x){
	Node<H> *t= search(x);
	if(!t) return 0;
	return t->getMul();
	}


	MyMultiBST<H>* del(H x) {
		_del(root, x);
		return this;
	}

	MyMultiBST<H>* _del(Node<H>*r, H x) {
		Node<H> *t = _rec_search(x, r);
		if( !t ) return this;
		if(t->getMul() > 1){
			t->decMul();
			return this;
		}
		if( t->isLeaf() ) {
			Node<H> *p = t->getParent();
			if(p==NULL) {root=NULL; return this;}
			if(p->getLeft()==t) p->setLeft(NULL);
			else p->setRight(NULL);
			return this;
		}
		if( !(t->getLeft() && t->getRight()) ) {
			Node<H> *p = t->getParent();
			Node<H> *f = t->getLeft();
			if(!f) f = t->getRight();
			if(p==NULL) {root=f; return this;}
			if( p->getRight()==t ) p->setRight(f);
			else p->setLeft(f);
			f->setParent(p);				
			return this;
		}
		Node<H> *n =  getNext(t);
		t->setKey(n->getKey());
		_del(t->getRight(), n->getKey());
		return this;
	}

	void _inorder(Node<H> *x) {
			if(x==NULL) return;
			_inorder(x->getLeft());
			for(int i=0; i<x->getMul(); i++) cout << x->getKey() << " ";
			_inorder(x->getRight());
		}

		void inOrderPrint(){
			_inorder(root);
			cout << endl;
		}

		int rank(H x) {
			int r = 0;
			Node<H> *t = getMin(root);
			while(t!=NULL && t->getKey()!=x) {
				r += t->getMul();
				t = getNext(t);
			}
			if( t==NULL ) return 0;
			return r+1;
		}
};


int main()
{
 MyMultiBST<int> *m = new MyMultiBST<int>;
 int daIns[14] = {10, 7, 7, 23, 30, 4, 1, 5, 9, 5, 1, 7, 1, 9};
 int daEli[5] = {7, 4, 23, 7, 7};
 for (int i = 0; i < 14; i++) m->ins(daIns[i]);
 for (int i = 0; i < 5; i++) m->del(daEli[i]);

  m->inOrderPrint();

 cout << "rank: " << m->rank(5) << " "<< m->rank(9) << " " << m->rank(30);



 return 1;
 
}
