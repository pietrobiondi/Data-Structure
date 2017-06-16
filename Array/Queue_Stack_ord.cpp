#include <iostream>
using namespace std;
#define dim 6
template<class H> class Vect{
private:
	H *A;
	int head,tail;
	int isFull(){return tail==dim? 1:0;}
	int isEmpty(){return tail==0? 1:0;}
public:
	Vect(){
		A = new H[dim];
		head = tail = 0;
	}
	Vect<H> *noInsert(H x){
		if(isFull()){
			cout << " PIENO " << endl;
			return this;
		}
		A[tail] = x;
		tail++;
		return this;
	}
	Vect<H> *ordInsert(H x){
		if(isFull()){
			cout << " PIENO " << endl;
			return this;
		}
		int i = 0;
		while(i < tail && x > A[i]) i++;
		for(int j = tail; j > i ; j--) A[j] = A[j-1];
		A[i] = x;
		tail++;
		return this;
	}

	Vect<H> *del(H x){
		if(isEmpty()){
			cout << " VUOTO " << endl;
			return this;
		}
		for(int i = 0; i < tail; i++){
			if(A[i] == x){
				for(int j = i; j < tail ; j++) A[j] = A[j+1];
			tail--;
			}
		}
	return this;	
	}
	Vect<H> *dequeue(){
		if(isEmpty()){
			cout << " VUOTO " << endl;
			return this;
		}
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
	Vect<H> *pop(){
		if(isEmpty()){
			cout << " VUOTO " << endl;
			return this;
		}
		else{
			tail--;
			A[tail] = 0;
			return this;
		}
	}
	void print(){
		for(int i = 0; i < tail; i++){
			cout << A[i] << " ";
		}
	cout << endl;	
	}
	void swap(int x, int y){
		int t = A[x];
		A[x] = A[y];
		A[y] = t;
	}
	int partition(int top, int bot){
		int x = A[top];
		int i = top - 1;
		int j = bot + 1;
		do{
			do j--;
			while(x < A[j]);

			do i++;
			while(x > A[i]);

			if(i < j) swap(i,j);
		}while(i < j);
	return j;	
	}
	void quickSort(int top, int bot){
		int middle;
		if(top < bot){
			middle = partition(top,bot);
			quickSort(top,middle);
			quickSort(middle+1,bot);
		}
	return;	
	}	
	void _quickSort(){
		quickSort(0,tail-1);
	}
	void Merge(int left, int center, int right){
		int i = left;
		int k = left;
		int j = center +1;
		H b[tail];
		while((i<=center) && (j<=right)){
			if(A[i] < A[j]){
			b[k] = A[i];
			i++;	
			}
			else{
				b[k] = A[j];
				j++;
			}
		k++;	
		}
		while(i<=center){
			b[k] = A[i];
			i++;
			k++;
		}
		while(j<=right){
			b[k] = A[j];
			j++;
			k++;
		}
		for( k = left; k <= right; k++) A[k] = b[k];

	}
	void MergeSort(int left, int right){
		if(left<right){
			int center = (left+right)/2;
			MergeSort(left,center);
			MergeSort(center+1,right);
			Merge(left,center,right);
		}
	return;	
	}
	void _MergeSort(){
		MergeSort(0,tail-1);
	}

};



int main(){
	Vect<int> *v = new Vect<int>;
	v->noInsert(10)->noInsert(2)->noInsert(8)->noInsert(14)->noInsert(13)->noInsert(22);
	cout << " NON ORD " << endl;
	v->print();
	cout << " Ord " << endl;
	v->_MergeSort();
	v->print();
	return 1;
}