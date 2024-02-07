#include<stdio.h>
#include<stdlib.h>
int a, b;

void foo(int *a, int *b){
	printf("a = %d, b = %d\n", a, b);
}

void foo1(int a[], int size){	//array never pass by value it always pass by reference so, int a[] / int* a is same in thr arg. list.
	int i = 0, size1;
	size1 = sizeof(a)/sizeof(a[0]);
	printf("\nSize of array shows in function: %d\n", size1);			//it dives 4 because it pointes to the int which is the first loc of the array.
	for(i = 0; i < size; i++) a[i] = 2 * a[i];
}

int* foo2(int *a, int *b){
//	int *c = (int*)malloc(sizeof(int));
//	*c = (*a) + (*b);
	int c = (*a) + (*b);
	return &c;
}

int foo3(int a, int b){
//	int *c = (int*)malloc(sizeof(int));
//	*c = (*a) + (*b);
	int c = a + b;
	return c;
}

int main(){
	int x = 10, y = 20, a[] = {1,2,3,4,5}, size, i;
	int *p, *p1, *ans;
	
	p = &x;
	p1 = &y;
	printf("x = %d, y = %d\n", x, y);
	printf("x = %d, y = %d\n", &x, &y);
	printf("p = %p, p1 = %p\n", p, p1);
	foo(&x, &y);
	
	size = sizeof(a)/sizeof(a[0]);
	printf("Elements of array before fun call: ");
	for(i = 0; i < size; i++) printf("%d ", a[i]);
	foo1(a, size);
	printf("Elements of array after fun call: ");
	for(i = 0; i < size; i++) printf("%d ", a[i]);		//all elements are incremented because array always pass by reference.
	
	ans = foo2(&x, &y);
	x = foo3(0x11111111, 0x22222222);
	printf("ANS = %d.", *ans);
	return 0;
}
