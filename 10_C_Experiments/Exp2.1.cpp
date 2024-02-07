#include<stdio.h>
#include<conio.h>
int main()
{
	int no, rn = 0, r, temp = 0, i = 0;
	printf("Enter a 5 digit no = ");
	scanf("%d", &no);
	temp = no;
	while(no != 0)
	{
		r = no % 10;
		rn = rn * 10 + r;
		no /= 10;
	}
	printf("Reversed number = %d\n", rn);
	if(rn == temp) printf("Numbers are equal.");
	else printf("Numbers are not equal.");
	getch();
}

