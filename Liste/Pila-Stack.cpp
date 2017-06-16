#include <iostream>
using namespace std;
//pila lista
template <class H> class Node{
	private:
		H key;
		Node<H> *prev, *next;
	public:
		Node(H x){
			key = x;
			prev = next = NULL;
		}
		void setNext(Node<H> *next){this->next = next;}
		void setPrev(Node<H> *prev){this->prev = prev;}
		void setKey(H key){this->key = key;}
		Node<H> *getNext(){return next;}
		Node<H> *getPrev(){return prev;}
		H getKey(){return key;}
};
template <class H> class Stack{
	private:
		int size;
		Node<H> *head, *tail;
		int isEmpty(){return size == 0? 1:0;}
	public:
		Stack(){
			size = 0;
			head = tail = NULL;
		}
		Stack<H> *push(H x){
			Node<H> *n = new Node<H>(x);
			size++;
			if(!head){
				head = tail = n;
				n->setNext(NULL);
				n->setPrev(NULL);
				return this;
			}
			else{
				n->setNext(head);
				head->setPrev(n);
				head = n;
				return this;
			}
		}
		Stack<H> *pop(){
			if(isEmpty()) return this;
			size--;
			if(head->getNext()){
				head = head->getNext();
				head->setPrev(NULL);
				return this;
			}
			else{
				head = NULL;
				return this;
			}
		}
		void print(){
			Node<H> *n = head;
			while(n != NULL)
			{
				cout << n->getKey() << " ";
				n = n->getNext();
			}
			cout << endl;
		}

};

int main(){
	Stack<int> *l = new Stack<int>();
	l->push(2)->push(3)->push(5)->push(8);
	l->pop()->pop()->pop()->pop()->pop()->pop();
	l->print();
	return 1;
}