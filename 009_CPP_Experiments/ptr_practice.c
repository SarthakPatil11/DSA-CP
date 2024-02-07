#include<stdio.h>
int main(){
//	int i, arr[] = {1,2,3};
//	for(i = 0; i < 3; i++) printf("%d", *(arr+i));

	int a = 10;
	int *p,**q;
	printf("%d ", a);
	printf("%d ", &a);
	p = &a;
	printf("%d ", *p);
	printf("%d ", p);
	q = &p;
	printf("%d ", **q);
	printf("%d ", q);
	return 0;
}
