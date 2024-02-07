#include<stdio.h>
#include<conio.h>
int main()
{
	int mx1[3][3], mx2[3][3], ans[3][3], i, j, k, l, sum = 0;
	printf("Enter the 1st 3 by 3 matrix : ");
	for(i = 0; i < 3; i++) for(j = 0; j < 3; j++) scanf("%d", &mx1[i][j]);
	printf("Enter the 2nd 3 by 3 matrix : ");
	for(k = 0; k < 3; k++) for(l = 0; l < 3; l++) scanf("%d", &mx2[k][l]);
	printf("1st maxtrix : ");
	for(i = 0; i < 3; i++) 
	{
		printf("\n");
		for(j = 0; j < 3; j++) printf("%d ", mx1[i][j]);
	}
	printf("\n2nd maxtrix : ");
	for(k = 0; k < 3; k++) 
	{
		printf("\n");
		for(l = 0; l < 3; l++) printf("%d ", mx2[k][l]);
	}
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			for(k = 0; k < 3; k++) sum += mx1[i][k] * mx2[k][j];
			ans[i][j] = sum;
			sum = 0;
		}
	}
	printf("\nResult maxtrix : ");
	for(i = 0; i < 3; i++) 
	{
		printf("\n");
		for(j = 0; j < 3; j++) printf("%d ", ans[i][j]);
	}
	getch();
}
