#include<iostream>
using namespace std;

void fibo(int size) {
	static int pr = 0, cr = 1, ans, temp = size;
	if (size == temp) cout<<pr<<" "<<cr<<" ";
	if ((size - 2) > 0) {
		int ans = pr + cr;
		cout<<ans<<" ";
		pr = cr;
		cr = ans;
		fibo(--size);
	}
}    

int main(void) {
	//using loop.
	int a = 10, ans = 0, pr = 0, cr = 1;
	cout<<pr<<" "<<cr<<" ";
	for(int i = 2; i < a; i++) {
		ans = pr + cr;
		cout<<ans<<" ";
		pr = cr;
		cr = ans;
	}
	cout<<endl;
	//using recursion.
	fibo(a);
	return 0;
}
