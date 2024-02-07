#include<stdio.h>
#include<conio.h>
int main()
{
	int n, max = 0, min, i;
	printf("How many no.s you want to enter : ");
	scanf("%d", &n);
	int numb[n];
	printf("Enter the elements = ");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &numb[i]);
		if(numb[i] > max) max = numb[i];
		else if(numb[i] < min) min = numb[i];
	}
	printf("max = %d, min = %d", max, min);
	getch();
}
