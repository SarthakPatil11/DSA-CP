#include<stdio.h>
int main(){
	unsigned char c1 = 0x11, c2 = 0x22, c3 = 0x33, c4 = 0x44;
	unsigned int i = 0, temp = 0;
	
	i = c1 << 24;
	
	temp = c2 << 16;
	i = i | temp;
	
	temp = c3 << 8;
	i = i | temp;
	
	i = i | c4;
	
	if (i != 0x11223344) printf("Test Fail.\n");
	else printf("Test Pass.\n");
	return 0;
}
