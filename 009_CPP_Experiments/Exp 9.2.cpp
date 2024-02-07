#include<iostream>
using namespace std;

template<class T1>
void bubblesort(T1 arr[], int n){
	int i, j;
	T1 temp;
	bool swapped;
	for (i = 0; i < n-1; i++){
	    swapped = false;
	    for (j = 0; j < n-i-1; j++){
	        if (arr[j] > arr[j+1]){
	           temp = arr[j];
	           arr[j] = arr[j+1];
	           arr[j+1] = temp;
	           swapped = true;
	        }
	    }
	    if (swapped == false) break;
	}
	cout<<"\nSorted arrya:";
	for(i = 0; i < n; i++) cout<<" "<<arr[i];
}

int main(){
	int arr1[4] = {3, 2, 10, 5};
	float arr2[5] = {3.1, 2.8, 10.2, 1.4, 1.5};
	bubblesort(arr1, 4);
	bubblesort(arr2, 5);
}
