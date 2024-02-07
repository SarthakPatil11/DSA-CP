#include<iostream>
using namespace std;
int main (void) {
	int n = 10;
	for(int i = 31; i >= 0; i--) {
		if((i + 1) % 4 == 0) cout<<' ';
		cout<< ((n >> i) & 1);
	}
	return 0;
}
