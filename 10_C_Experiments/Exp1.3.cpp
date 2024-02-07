#include<stdio.h>
#include<conio.h>
int main()
{
	int no, rn = 0, r;
	printf("Enter a 5 digit no = ");
	scanf("%d", &no);
	while(no != 0)
	{
		r = no % 10;
		rn = rn * 10 + r;
		no /= 10;
	}
	printf("incremented no = ");
	while(rn != 0)
	{
		r = rn % 10;
		if(r == 9) printf("0");
		else printf("%d", r + 1);
		rn /= 10;
	}
	getch();
}

