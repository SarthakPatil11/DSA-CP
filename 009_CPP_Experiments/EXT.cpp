//PROGRAM FOR SETTING ALL ELEMENTS OF ARRAY TO "0" USING THE DEMONSTRATION OF ARRAY OF OBJECTS, POINTER TO OBJECT, THIS POINTER IN THE PROGRAM.
#include<iostream>
using namespace std;
class set{
	int size, i;
	int *arr;
	public:
		void setdata(int arr[], int size){
			this->size = size;				//THIS POINTERS FOR size AND arr VARIABLES.
			this->arr = new int[size];
			this->arr = arr;
			return;
		}
		void display(){
			cout<<"Entered array: ";
			for(i = 0; i < size; i++) cout<<arr[i]<<" ";
			cout<<"\nEach location is setted to zero..."<<endl;
			cout<<"Elements of array: ";
			for(i = 0; i < size; i++){		//SETTING THE EACH VALUE OF arr TO "0".
				arr[i] = 0;
				cout<<arr[i]<<" ";
			}
			cout<<"\n---------------------------------------"<<endl;
			return;
		}
};
int main(){
	int iterate, size, i, j;
	int *arr1;
	cout<<"How many times you want to iterate: ";
	cin>>iterate;
	set *s1 = new set[iterate];				//POINTER TO ARRAY OF OBJECTS.
	for(i = 0; i < iterate; i++){
		cout<<"Enter the size of array: ";
		cin>>size;
		arr1 = new int[size];
		cout<<"Enter elements of array: ";
		for(j = 0; j < size; j++) cin>>arr1[j];
		s1->setdata(arr1, size);
		s1->display();
		//s1 -> size;
	}
	return 0;
}
