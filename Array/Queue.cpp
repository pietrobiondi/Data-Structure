#include <iostream>
using namespace std;
#define dim 5
//coda array
template <class H> class Queue{
	private:
		H *A;
		int head, tail;
		int isFull(){return tail == dim? 1:0;}
		int isEmpty(){return tail == 0? 1:0;}
	public:
		Queue(){
			head = tail = 0;
			A = new H[dim];
		}
		Queue<H> *enqueue(H x) {//inserimento in coda
			if(isFull()) cout << "Coda piena" << endl;
			else
			{
				A[tail] = x;
				tail++;
			}
			return this;
		}
		Queue<H> *dequeue(){
			if(isEmpty()) cout << "Coda vuota" << endl;
			else{
				int i = 0;
				int j = i+1;
				while(i < tail){
					A[i] = A[j];
					i++;
					j++;
				}
				tail--;

			return this;
			}
		}

		Queue<H> *arrayOrdinato(H x){
			if(isFull()){
				cout << " Pieno " << endl;
				return this;
			}
			int i = 0;
			while (i < tail && x > A[i]) i++;
			for (int j = tail; j > i; j--) A[j] = A[j-1];
			A[i] = x;
			tail++;
			return this;
		}
		
		Queue<H>* del(H x){
		if(isEmpty()) cout << "del -- VUOTA " << endl;
		else{
			for (int i = 0; i < tail; i++){
				if(A[i] == x){
					for(int j = i; j < tail; j++) 
						A[j] = A[j+1];
				}
			}
		tail--;
		}	
		return this;
		}

		void print(){
			for(int i = 0; i < tail; i++){
				cout << A[i] << " ";
			}
			cout << endl;
		}
};
int main()
{
	Queue<int> *a = new Queue<int>;
	a->enqueue(5)->enqueue(2)->enqueue(10)->enqueue(6)->enqueue(22);
	a->print();
	a->dequeue()->dequeue()->dequeue()->dequeue()->dequeue()->dequeue();
	a->print();
	return 1;
}