//PROGRAM TO ADD TWO ARRAYS AND STORE IN THIRD ARRAY USING COPY CONSTRUCTOR AN DYNAMIC CONSTRUCTOR.
#include<iostream>
using namespace std;
class add_array{
	int *arry1, *arry2, *sum;
	int i, sz;
	public:
		add_array(int arr1[], int arr2[], int size){
			arry1 = new int[size];
			arry1 = arr1;
			arry2 = new int[size];
			arry2 = arr2;
			sz = size;
		}
		add_array(add_array &a1){
			sz = a1.sz;
			sum = new int[sz];
			for(i = 0; i < sz; i++){
				sum[i] = a1.arry1[i] + a1.arry2[i];
			}
		}
		void disp_entered_arr(){
			cout<<"Entered array1: ";
			for(i = 0; i < sz; i++) cout<<arry1[i]<<" ";
			cout<<"\nEntered array1: ";
			for(i = 0; i < sz; i++) cout<<arry2[i]<<" ";
		}
		void disp_sum_arr(){
			cout<<"\nSum of entered arrays: ";
			for(i = 0; i < sz; i++) cout<<sum[i]<<" ";
		}
};
int main(){
	int i, size;
	int *arr1, *arr2;
	
	cout<<"Enter the size of both arrays: ";
	cin>>size;
	arr1 = new int[size];
	arr2 = new int[size];
	
	cout<<"Enter elements of array1: ";
	for(i = 0; i < size; i++) cin>>arr1[i];
	cout<<"Enter elements of array2: ";
	for(i = 0; i < size; i++) cin>>arr2[i];
	
	add_array a1(arr1, arr2, size);
	a1.disp_entered_arr();
	add_array a2(a1);
	a2.disp_sum_arr();
	
	return 0;
}
