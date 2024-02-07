#include<iostream>
using namespace std;
int getBit(int n, int i) {
	return ((n & (1 << i)) != 0);
}

int setBit(int n, int i) {
	return (n | (1 << i));
}

int clearBit(int n, int i) {
	return (n & (~(1 << i)));
}

int toggleBit(int n, int i) {
	return (n ^ (1 << i));
}

void printBinary(int n) {
	for(int i = 31; i >= 0; i--) {
		if((i+1) % 4 == 0) cout<<" ";
		cout<<((n >> i) & 1);
	}
}

int reverseBits(int n) {
	int ans = 0;
	for(int i = 0; i < 32; i++) {
		ans = ans << 1;
		if(((n >> i) & 1) == 1) {
			ans = ans | 1;
		}
	}
	return ans;
}

int clearBitsF_LSB(int n, int i) {
	i += 1;							//2 + 1 = 3
	int tn = (1 << i) - 1;			//create no.: 0100 - 1 = 0011
	n = n & ~(tn);					//1111 & 1100 = 1100
	return n;
}

int clearBitsF_MSB(int n, int i) {
	i += 1;							//2 + 1 = 3
	int tn = (1 << i) - 1;			//create no.: 0100 - 1 = 0011
	n = n & tn;						//1111 & 0011 = 0000
	return n;
}

int mix() {
//	char c1 = 0X11, c2 = 0x22, c3 = 0x33, c4 = 0x44;
//	int n = c1;
//	n = n << 8;
//	n = n | c2;
//	
//	n = n << 8;
//	n = n | c3;
//	
//	n = n << 8;
//	n = n | c4;
	
	int c1 = 0X112, c2 = 0x223;
	int n = (c1 << 12) | c2;
	
//	int n = (c1 << 24) | (c2 << 16) | (c3 << 8) | c4;
	return n;
}

int main(void) {
	cout<<"Bit at 2: "<<getBit(5, 2)<<endl;
//	cout<<"Set at 1: "<<setBit(5, 1)<<endl;
//	cout<<"Clear at 2: "<<clearBit(5, 2)<<endl;
//	printBinary(5 | (1 << 1));
	printBinary(0x11223344);
	cout<<endl;
//	int ans = clearBitsF_LSB(15, 2);
//	int ans = clearBitsF_MSB(328, 6);
	printBinary(mix());
	return 0;
}
