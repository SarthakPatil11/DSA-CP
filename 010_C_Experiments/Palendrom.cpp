#include<iostream>
using namespace std;
int main(void) {
	int n = 12321, new_n = 0, ans = 0;
	while(n != 0) {
		new_n = n % 10;
		ans *= 10 + new_n;
		n /= 10;
	}
	if (n == ans) cout<<"Number is palindrom...";
	else cout<<"Number is not palindrom...";
	return 0;
}
