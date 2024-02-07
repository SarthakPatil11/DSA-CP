#include<iostream>
#include<math.h>
using namespace std;

void printBinary(unsigned int n) {
	for(int i = 31; i >= 0; i--) {
		if((i+1) % 4 == 0) cout<<" ";
		cout<<((n >> i) & 1);
	}
}

int main(void) {
	int a = 0;
	int *p = &a;
	unsigned int x = (unsigned int) p;
	int byte_align, zeroes = 0;
	
	cout<<x<<endl;
	printf("%x\n", x);
	printBinary(x);
	cout<<endl;
	
//	while (x) {
//		if ((x & 1) == 0) {
//			zeroes++;
//		} else {
//			break;
//		}
//		x = x >> 1;
//	}

	for(int i = 0; i < 32; i++) {
		if ((x & (1 << i)) == 0) {
			zeroes++;
			printBinary((1 << i));
			cout<<" : "<<zeroes<<endl;
		}
		else break;
	}
	
	byte_align = pow(2, zeroes);	
	printf("Address pointed by p is @%p and it is %d bytes aligned\n", p, byte_align);
	return 0;
}
