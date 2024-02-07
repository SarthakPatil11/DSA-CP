#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int a, b;
	printf("Enter the value and the power value : ");
	scanf("%d %d", &a, &b);
	printf("The result is : %.2lf", pow(a, b));
	getch();
}
