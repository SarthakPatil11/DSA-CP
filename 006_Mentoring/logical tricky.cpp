#include<iostream>
using namespace std;
int num(int n) {
	(n == 0) ? 0 : num(n - 1);
	cout<<n<<endl;
}
int main(void) {
	num(10);
	return 0;
}
