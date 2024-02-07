#include<iostream>
using namespace std;
int main(void) {
	string s = "111";
//	cout<<s<<endl;
//	int a = 0;
//	a = a << s[2];
//	printf("%d %d %d %d %s", s[0], s[1], s[2], a, a);
	
	int r = 0, x = 1;
	for (int i = (s.length() - 1); i >= 0; i--) {
		if (s[i] == '1') r += x;
		x = (x * 2) % 3;
	}
	if (r % 3 == 0) cout<<"1 "<<r;
	else cout<<"0 "<<r;
}
