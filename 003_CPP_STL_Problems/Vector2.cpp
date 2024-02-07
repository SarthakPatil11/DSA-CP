 #include<iostream>
#include<vector>
using namespace std;
void print(vector<int> &arr) {
	cout<<"In function: ";
	for(int i = 0; i < arr.size(); i++) {
		cout<<arr[i]<<" ";
	}
}
int main(void) {
	vector<int> v;
	cout<<"Capacity: "<<v.capacity()<<endl;
	
	v.push_back(20);  
	cout<<"Capacity: "<<v.capacity()<<endl;
	
	v.push_back(10);
	cout<<"Capacity: "<<v.capacity()<<endl;
	
	print(v);
	cout<<"\nSize v: "<<v.size()<<endl;
	
	vector<int> arr;
	int n;
	cout<<"\nhow many elements you want to enter: ";
	cin>>n;
	for(int i = 0; i < n; i++) {
		cout<<i;
		arr.push_back(i);
	}
	
	vector<int> arr1 = arr; // O(n)
	cout<<"\nSize arr: "<<arr.size()<<endl;
	for(int i = 0; i < arr.size(); i++) {
		cout<<" "<<arr[i]<<" ";
	}
	
	print(arr);
	
	
	return 0;
}
