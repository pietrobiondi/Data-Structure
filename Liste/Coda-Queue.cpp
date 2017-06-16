#include <iostream>
using namespace std;
//coda lista
template <class H> class Node{
	private:
		H key;
		Node<H> *next, *prev;
	public:
		Node(H x){
			key = x;
			next = prev = NULL;
		}
		void setNext(Node<H> *next){this->next = next;}
		void setPrev(Node<H> *prev){this->prev = prev;}
		void setKey(Node<H> *key){this->key = key;}
		Node<H> *getNext(){return next;}
		Node<H> *getPrev(){return prev;}
		H getKey(){return key;}
};
template <class H> class Queue{
	private:
		int size;
		Node<H> *head, *tail;
		int isEmpty(){return size == 0? 1:0;}
	public:
		Queue(){
			size = 0;
			head = tail = NULL;
		}
		Queue<H> *enqueue(H x){
			Node<H> *n = new Node<H>(x);
			size++;
			if(!head){
				head = n;
				tail = n;
				n->setPrev(NULL);
				n->setNext(NULL);
				return this;
			}
			else{
				n->setPrev(tail);
				n->setNext(NULL);
				tail->setNext(n);
				tail = n;
				return this;
			}
		}
		Queue<H> *dequeue(){
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
			while(n != NULL){
				cout << n->getKey() << " ";
				n = n->getNext();
			}
			cout << endl;
		}

};
int main()
{
	Queue<int> *l = new Queue<int>();
	l->enqueue(1)->enqueue(3)->enqueue(5);
	l->dequeue()->dequeue()->dequeue();
	l->enqueue(8);
	l->dequeue()->dequeue()->dequeue();
	l->print();
	return 1;
}