#include<iostream>
#include<stdio.h>
using namespace std;
int main(void) {
	int a = 10, b = 20, c = 0;
	asm {
		mov ax, a;
		mov bx, b;
		add ax, bx;
		mov c, ax;
	}
	cout<<c;
	return 0;
}
