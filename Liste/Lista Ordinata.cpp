//LISTA DOPPIAMENTE LINKATA ORDINATA
#include <iostream>
#include <cstdlib>
using namespace std;

	
template <class H> class Node{
	private:
		H key;
		Node<H> *next, *prev, *parent, *left, *right;
	public:
		Node(){}
		Node(H _key){
			key = _key;
			next = prev = parent = left = right = NULL;
		}

		void setKey(H _key){key = _key;}
		void setNext(Node<H> *_next){next = _next;}
		void setPrev(Node<H> *_prev){prev = _prev;}
		void setParent(Node<H> *_parent){parent = _parent;}
		void setLeft(Node<H> *_left){left = _left;}
		void setRight(Node<H> *_right){right = _right;}

		H getKey(){return key;}
		Node<H> *getNext(){return next;}
		Node<H> *getPrev(){return prev;}
		Node<H> *getParent(){return parent;}
		Node<H> *getRight(){return right;}
		Node<H> *getLeft(){return left;}
		int isLeaf() { 
			if( !getLeft() && !getRight() ) return 1;
			return 0; 
		}
		
};


template <class H> class List{
    private:
    	Node<H> *head, *tail;
    public:
    	List(){head = tail = NULL;}
	
    	List<H> *insert(H x){
    		Node<H> *node = new Node<H>(x);
    		if(!head){
    			head = tail = node;
    			return this;
    		}
    		Node<H> *supp = head;
    		if (x <= head->getKey()){
    			node->setNext(head);
    			head->setPrev(node);
    			head = node;
    			return this;
    		}
    		while (supp->getNext()) {
    			if (x >= supp->getKey() && x <= supp->getNext()->getKey()){
    				supp->getNext()->setPrev(node); 
    				node->setNext(supp->getNext());
    				node->setPrev(supp);
    				supp->setNext(node);
    				return this;
    			}
    			supp = supp->getNext();
    		}
    		supp->setNext(node);
    		node->setPrev(supp);
    		tail = node;
    		return this;
    	}

    	void printl(){
    		Node<H> *node = head;
    		while(node){
    			cout << node->getKey() << " ";
    			node = node->getNext();
    		}
    		cout << endl;
    	}

    Node<H> *_search(H x){
            Node<H> *t = head;
            while (t){
                if (t->getKey()==x) return t;
                t = t->getNext();
            }
            return NULL;
        }

	   List<H>* del(H x) { 
            Node<H> *y =_search(x);
            if(!y) return this;
            Node<H>* p = y->getPrev();
            Node<H>* s = y->getNext();
            if(p) p->setNext(s);
            else head = s;
            if(s) s->setPrev(p);
            else tail = p;
            return this; 
        }

};
	

int main(){
List<int> *l = new List<int>;
	l->insert(10)->insert(13)->insert(50)->insert(27)->insert(2)->insert(20);
	l->printl();  
	l->del(20)->del(2);
	l->printl();  

return 0;
	
}