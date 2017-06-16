//LISTA DOPPIAMENTE LINKATA ORDINATA Multilist
#include <iostream>
#include <cstdlib>
using namespace std;

	
template <class H> class Node{
	private:
		H key;
        int mul;
		Node<H> *next, *prev;
	public:
		Node(){}
		Node(H _key){
			key = _key;
            mul = 1;
			next = prev = NULL;
		}
		void setKey(H _key){key = _key;}
		void setNext(Node<H> *_next){next = _next;}
		void setPrev(Node<H> *_prev){prev = _prev;}
        void setMul(int _mul){mul = _mul;}
        void decMul() { this->mul--; }
        void incMul() { this->mul++; }

        int getMul() { return mul; }
		H getKey(){return key;}
		Node<H> *getNext(){return next;}
		Node<H> *getPrev(){return prev;}
};


template <class H> class List{
    private:
    	Node<H> *head, *tail;
    public:
    	List(){head = tail = NULL;}
	
    	List<H> *insert(H x){
    		Node<H> *node = new Node<H>(x);
            Node<H> *tmp = _search(x);
            if(tmp != NULL)
            {
                tmp->incMul();
                return this;  
            }
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

    	void print(){
    		Node<H> *node = head;
    		while(node){
                for(int i=0; i<node->getMul(); i++) cout << node->getKey() << " ";
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
            if(y->getMul() > 1){
                y->decMul();
                return this;
            }
            Node<H>* p = y->getPrev();
            Node<H>* s = y->getNext();
            if(p) p->setNext(s);
            else head = s;
            if(s) s->setPrev(p);
            else tail = p;
            return this; 
        }

    int  multiplicity(H x){
    Node<H> *t= _search(x);
    if(!t) return 0;
    return t->getMul();
    }

   int rank(H x) {
        int r = 0;
        Node<H> *t = head;
        while(t!=NULL && t->getKey()!=x) {
            r += t->getMul();
            t = t->getNext();
        }
        if( t==NULL ) return 0;
        return r+1;
    }
};
	

int main(){
List<int> *l = new List<int>;
int daIns[] = {10,5,8,3,5,1,6,5,8,1,12,7};
int daEl[] = {6,5,8,3,8};
for(int i = 0 ; i<12; i++)l->insert(daIns[i]);
l->print();
cout<< " inz del" << endl;
for(int i = 0; i < 5; i++) l->del(daEl[i]);
l->print();
cout << " rank " << endl;
cout << l->rank(5) << " " << l->rank(6) << " " << l->rank(12) << endl;
return 0;
	
}