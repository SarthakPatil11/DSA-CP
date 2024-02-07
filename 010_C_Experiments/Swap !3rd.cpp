#include<iostream>
using namespace std;
int main(void) {
	int a = 10, b = 20;
	a += b;
	b = a - b;
	a = a - b;
	cout<<a<<" "<<b;
	return 0;
}
