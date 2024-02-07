#include<stdio.h>
#include<conio.h>
int GCD(int a, int b)
{
	if(b != 0) GCD(b, a % b);
	return b;
}
int main()
{
	int a, b;
	printf("Enter the values of A and B : ");
	scanf("%d %d", &a, &b);
	printf("The result is : %d", GCD(b, a % b));
	getch();
}
