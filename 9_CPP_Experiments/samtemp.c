#include<stdio.h>
#include<conio.h>

main()
{
	int d,i=0;
	int r[5];
	printf("Enter number");
	scanf("%d",&d);
	
	while(d >= 1)
	{
		r[i]= d % 2;
		d = d / 2;
		i++;
	}
	
	for(i=3;i>=0;i--)
	{
		printf("%d",r[i]);
	}
}
