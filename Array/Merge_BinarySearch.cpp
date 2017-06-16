//Array mergesort binary search
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

	void Merge(int left,int center,int right){
		int i=left;
		int k=left;
		int j=center+1;
		H orderedArray[size];
		while( (i<=center)&&(j<=right) ){
			if( array[i] < array[j] ){
				orderedArray[k]=array[i];
				i++;
			}
			else{
				orderedArray[k]=array[j];
				j++;
			}
			k++;
		}
		while( i<=center ){
			orderedArray[k]=array[i];
			k++;
			i++;
		}
		while( j<=right ){
			orderedArray[k]=array[j];
			k++;
			j++;
		}
		for(k=left;k<=right;k++)
			array[k]=orderedArray[k];
	}

	//MergeSort
	void ArrayOrderMerge(int left, int right){
		if(left<right){
			int center=(left+right)/2;
			ArrayOrderMerge(left,center);
			ArrayOrderMerge(center+1,right);
			Merge(left,center,right);
		}
	}

	void MergeSort(){
		ArrayOrderMerge(0,end);
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
	cout << " Eseguo MergeSort" << endl;
	v->MergeSort();
	cout << " Stampa " << endl;
	v->print();
	
	cout << "Binary Search " << endl;
	cout << v->BinarySearch(6) <<" ";
	cout << v->BinarySearch(22) <<" ";
	cout << v->BinarySearch(8) <<" ";
	return 1;
}

