#include<stdio.h>
#include<conio.h>
int main()
{
	int no, r, sum = 0;
	printf("Enter a 5 digit no :");
	scanf("%d", &no);
	while(no != 0){
		r = no % 10;
		sum += r;
		no /= 10;
	}
	printf("sum = %d", sum);
	getch();
}


