#include<stdio.h>
#include<conio.h>
int GCD(int a, int b)
{
	if(a == 0) return b;
	if(b == 0) return a;
	return GCD(b, a % b);
}
int main()
{
	int a, b;
	printf("Enter the values of A and B : ");
	scanf("%d %d", &a, &b);
	printf("The result is : %d", GCD(b, a % b));
	return 0;
}
