#include<stdio.h>
#include<conio.h>
int main(){
	int i = 10;
	int *p = &i;
//	unsigned int x = (unsigned int) &i;
	unsigned int x = (unsigned int) p;
	printf("%p\n", p);
//	printf("%u\n", x);
	return 0;
}
