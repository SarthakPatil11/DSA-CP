#include<iostream>
#include<utility>
using namespace std;
int main(void) {
	pair<int, string> p;
//	p = make_pair(2, "abc");
//	p = {2, "abcd"};
	cin>>p.first>>p.second;
	cout<<p.first<<" "<<p.second<<endl;
	
	int a[] = {1, 2, 3}, b[] = {4, 5, 6};
	pair<int, int> arr_p[3];
	
	arr_p[0] = {a[0], b[0]};
	arr_p[1] = {a[1], b[1]};
	arr_p[2] = {a[2], b[2]};
	
	cout<<"Before swapping:\n";
	for(int i = 0; i < 3; i++) {
		cout<<arr_p[i].first<<", "<<arr_p[i].second<<" \n";
	}
	swap(arr_p[0], arr_p[1]);
	cout<<"After swapping:\n";
	for(int i = 0; i < 3; i++) {
		cout<<arr_p[i].first<<", "<<arr_p[i].second<<" \n";
	}
	
	return 0;
}
