#include<iostream>
using namespace std;
class set{
	int size, i;
	int *arr;
	public:
		void setdata(int arr[], int size){
			this->size = size;
			this->arr = new int[size];
			this->arr = arr;
			cout<<"Entered array: ";
			for(i = 0; i < size; i++) cout<<this->arr[i]<<" ";
			cout<<"\nEach location is seted to zero...\n";
			return;
		}
		void display(){
			for(i = 0; i < size; i++){
				arr[i] = 0;
				cout<<arr[i]<<" ";
			}
			cout<<"\n---------------------------------------"<<endl;
			return;
		}
};
int main(){
	set *s1 = new set[2];
	int size, i, j;
	int *arr1;
	for(i = 0; i < 2; i++){
		cout<<"Enter the size of array: ";
		cin>>size;
		arr1 = new int[size];
		cout<<"Enter elements of array: ";
		for(j = 0; j < size; j++) cin>>arr1[j];
		s1->setdata(arr1, size);
		s1->display();
	}
	return 0;
}
