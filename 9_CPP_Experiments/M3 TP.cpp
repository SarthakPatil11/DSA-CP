#include<iostream>
using namespace std;
int main(){
	unsigned char c1 = 0x11, c2 = 0x22, c3 = 0x33, c4 = 0x44, c5 = 0;
	unsigned int i = 0;
	
//	i = c1 << 24 | c2 << 16 | c3 << 8 | c4;

	c5 = !c1;
	
	cout<<hex<<"0x"<<c5<<endl;
	return 0;
}
