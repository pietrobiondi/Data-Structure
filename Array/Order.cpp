#include <iostream>
using namespace std;
#define dim 8
template<class H> class Array{
private:
	H *A;
	int head,size;
	int isFull(){return size == dim? 1:0;}
	int isEmpty(){return size == 0? 1:0;}
public:
	Array(){
		A = new H[dim];
		head = size = 0;
	}
	int getSize(){return size;}
	void noinsert(H x){
		if(isFull()){
			cout <<" PIENO " << endl;
			return;
		}
		else{
			A[size] = x;
			size++;
			return;
		}
	}
	void orderInsert(H x){
		if(isFull()) return;
		int i = 0;
		while( i < size && x >A[i])i++;
		for(int j = size; j > i; j--) A[j] = A[j-1];
		A[i] = x;
		size++;
		return;
	}
	void del(H x){
		if(isEmpty()) return;
		for(int i = 0; i < size; i++){
			if(A[i] == x){
				for(int j = i; j <size; j++) A[j] = A[j+1];
			size--;	
			}
		}
	return;	
	}
	void dequeue(){
		if(isEmpty()) cout << "Coda vuota" << endl;
		else{
			int i = 0;
			int j = i+1;
			while(i < size){
				A[i] = A[j];
				i++;
				j++;
			}
		size--;
		return;
		}
	}

	void swap(int x, int y){
		int t = A[x];
		A[x] = A[y];
		A[y] = t;
	}
	
	int partition(int top,int bot){
		int x = A[top];
		int i = top - 1;
		int j = bot + 1;
		do{
			do j--;
			while(x < A[j]);

			do i++;
			while(x > A[i]);

			if(i < j) swap(i,j);
		}while(i<j);
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
	void print(){
		for(int i = 0; i < size; i++){
			cout << A[i] << " ";
		}
	cout << endl;
	}
	void _quickSort(){
		quickSort(0,size-1);
	}
	void Merge(int left, int center, int right){
		int i = left;
		int k = left;
		int j = center+1;
		H b[size];
		while( (i<=center) && (j <= right) ){
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
		while(j <= right){
			b[k] = A[j];
			j++;
			k++;
		}
		for(k = left; k<=right; k++) A[k]= b[k];
	}
	void MergeSort(int left, int right){
		if(left<right){
			int center = (left+right)/2;
			MergeSort(left,center);
			MergeSort(center+1,right);
			Merge(left,center,right);
		}
	}
	void _MergeSort(){
		MergeSort(0,size-1);
	}
	void bubbleSort(){
		for(int i = 0; i < size-1; i++){
			for(int k = 0; k <size-1;k++)
				if(A[k] > A[k+1]) swap(k,k+1);
		}
	}
		bool verifyOrder(){
		for(int i = 0; i<size-1; i++){
			if(A[i] > A[i+1]) 
				return false;
		}
	return true;
	}
	int binarySearch(H x){
		if( verifyOrder() == false) return -1;
		iteratBinarySearch(x,0,size-1);
	}
	int recBinarySearch(int x, int left, int right){
		if(left == right){
			if(A[left] == x)
				return 1;
			else
				return 0;
		}
		int center = (left+right)/2;
		if(x <= A[center])
			return recBinarySearch(x,left,center);
		else
			return recBinarySearch(x,center+1,right);
	}
	int iteratBinarySearch(int x, int left, int right){
		while(left<=right){
		if(left == right){
			if(A[left] == x)
				return 1;
			else
				return 0;
		}
			int center = (left+right)/2;
			if(A[center] == x) return 1;
			else if(A[center] < x) left = center+1;
			else right = center - 1;
		}
	return -1;	
	}
};





int main(){
	Array<int> *a = new Array<int>;
	a->noinsert(10);
	a->noinsert(5);
	a->noinsert(60);
	a->noinsert(2);
	a->noinsert(48);
	cout << " Array: " << endl;
	a->print();
	cout << " ORDINO " << endl;
	a->_MergeSort();
	cout << " Print " << endl;
	a->print();

	cout << " RICERCA " << endl;
	cout << a->binarySearch(88) << endl;
	return 1;
}