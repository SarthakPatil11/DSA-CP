#include<iostream>
using namespace std;
int main(void) {
	int n = 5, ans = 1;
	while(n > 0) {
		ans *= n;
		n--;
	}
	cout<<ans;
	return 0;
}
