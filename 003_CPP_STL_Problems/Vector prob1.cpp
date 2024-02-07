#include<iostream>
#include<vector>
using namespace std;
void convertToWave(vector<int>& arr, int n) {
	for(int i = 1; i < n; i+=2) {
		int temp = arr[i];
		arr[i] = arr[i-1];
		arr[i-1] = temp;
	}
	return;
}
int main(void) {
	vector<int> v;
	int n = 5;
	for(int i = 0; i < n; i++) {
		v.push_back(i);
		cout<<v[i]<<" ";
	}
	convertToWave(v, n);
	cout<<endl<<"After convert: ";
	for(int i = 0; i < n; i++) {
		cout<<v[i]<<" ";
	}
	return 0;
}
