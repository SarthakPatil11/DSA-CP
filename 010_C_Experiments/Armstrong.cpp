#include<iostream>
using namespace std;
int main(void) {
	int n = 153, dig = 0, ans = 0;
	int temp = n;
	while(n != 0) {
		dig = n % 10;
		ans += (dig * dig * dig);
		n /= 10;
	}
	if(ans == temp) cout<<"Armstrong..";
	else cout<<"Not Armstrong..";
	return 0;
}
