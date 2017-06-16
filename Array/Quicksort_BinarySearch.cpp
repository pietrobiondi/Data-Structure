//Array quicksort binary search
#include <iostream>
#define dim 13
using namespace std;
template<class H> class MyVector{
	public:
	H array[dim]; //array
	int size;
	int end;

	MyVector<H>(){
		size = 0;
		end = -1;
	}

	void insert(H x){
		if(size<dim){
			end = end+1;
			array[end] = x;
			size++;
		}
	}

	void del(H x){
		for(int i=0; i<size; i++){
			if(array[i]==x){
				for(int j=i; j<size; j++){
					array[j] = array[j+1];
				}
				size--;
				end--;
				return;
			}
		}
	}

	void print(){
		for(int i = 0; i < size; i++) cout << array[i] << "  ";
		cout << endl;

	}

	int search(H x){
		for(int i = 0; i < size; i++){
			if(array[i] == x)
				return 1;
		}
		return 0;
	}

	bool verifyOrder(){
		for(int i=0; i<size-1; i++){
			if( array[i] > array[i+1] )
				return false;
		}
		return true;
	}
	
	int BinarySearch(H x){
		if(verifyOrder()==false) return -1;
		RecBinarySearch(x,0,end);
	}

	int RecBinarySearch(int x, int left, int right){
		if(left == right){
			if(x == array[left])
				return 1;
			else
				return 0;
		}
		int center = (left + right) / 2;
		if(x <= array[center])
			return RecBinarySearch(x, left, center);
		else
			return RecBinarySearch(x, center+1, right);
	}

	void Invert (int& a, int& b) 
	{  
		int aux=a; 
		a=b; 
	   	b=aux; 
	}   

	void quicksort(int left, int right) 
	{
		if (left>= right) return;
		int i=left;  
		int j=right-1;
		int pivot = array[(right+left)/2];
		
		Invert(array[right],array[(right+left)/2]);		
		while (i<j) {
			while ((array[i]<=pivot) && (i< right)) i++;
			while ((array[j]>pivot) && (j>=left)) j--;
			if (i<j)  
				Invert(array[i],array[j]); 
			}
		array[right]=array[i];
		array[i]=pivot;
		
		quicksort(left,j);
		quicksort(j+1,right);
	}

	void _quick(){
		quicksort(0,end);
	}	

/*  VERSIONE 2
void scambia(int x, int y) {
	int t = array[x];
	array[x] = array[y];
	array[y] = t;
}

int partition(int top, int bottom) {
	int x = array[top];
	int i = top - 1;
    int j = bottom + 1;
    do {
    	do j--;
		while (x < array[j]);

        do i++;
        while (x > array[i]);

        if (i < j) scambia(i, j);
	} while (i < j);    
    return j;        
}

void quicksort(int top, int bottom) {
	int middle;
	if (top < bottom) {
		middle = partition(top, bottom);
		quicksort(top, middle);
		quicksort(middle+1, bottom);
    }
	return;
}

void _quick() {
	quicksort(0, end);
}
*/
};


int main (){
	MyVector<int> *v = new MyVector<int>;
	cout << endl << endl;
	cout << "Inserimento array" << endl;
	v->insert(4);
	v->insert(7);
	v->insert(12);
	v->insert(10);
	v->insert(2);
	v->insert(5);
	v->insert(8);
	v->insert(9);
	v->insert(6);
	v->insert(3);
	v->insert(15);
	v->insert(22);
	v->insert(1);
	v->print();
	cout << "Eseguo delete di : 8 e 7 (array) "<< endl;
	v->del(8);
	v->del(7);
	cout << " Eseguo quicksort" << endl;
	v->_quick();

	cout << " Stampa " << endl;
	v->print();
	
	cout << "Binary Search " << endl;
	cout << v->BinarySearch(6) <<" ";
	cout << v->BinarySearch(22) <<" ";
	cout << v->BinarySearch(8) <<" ";
	return 1;
}

