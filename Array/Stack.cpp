#include <iostream>
using namespace std;
#define dim 5

template<class H> class Stack{
private:
	H *A;
	int size;
	int isFull(){ return size == dim? 1:0;}
	int isEmpty(){ return size == 0? 1:0;}
public:
	Stack(){
		size = 0;
		A = new H[dim];
	}
	Stack<H>* push(H x){
		if(isFull()) cout << " Stack Pieno " << endl;
		else{
			A[size] = x;
			size++;
		}
		return this;
	}
	Stack<H>* pop(){
		if( isEmpty() ) cout << " Stack Vuoto " << endl;
		else{
			size--;
			A[size] = 0;
		}
		return this;
	}
	void printStack(){
		for(int i = 0 ; i < size; i++)
			cout << A[i] << " ";
		cout << endl;
	}

};

int main(){
	Stack<int> *s = new Stack<int>;
	s->push(10)->push(5)->push(22)->push(44)->push(9);
	s->pop()->pop()->pop()->pop()->pop()->pop()->pop()->pop();
	s->push(77)->push(55)->push(11)->push(44);
	s->pop();
	s->printStack();
	return 1;
}