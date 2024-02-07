#include<iostream>
using namespace std;
int main(void) {
	int n = 7, flag = 0;
	for(int i = 2; i < n && n % i == 0; i++) flag = 1;
	if(flag == 1) cout << "Not Prime number...";
	else cout << "Prime number...";
	return 0;
}
