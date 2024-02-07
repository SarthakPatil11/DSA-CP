#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int size,sq, mean, i = 0, sum = 0, num = 0;
	printf("Enter how many elements you want to enter : ");
	scanf("%d", &size);
	int arr[size];
	printf("Enter elements :");
	for(i = 0; i < size; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	mean = sum / size;
	printf("Mean : %d\nDifference : ", mean);
	for(i = 0; i < size; i++)
	{
		printf(" %d", arr[i] - mean);
		sq = arr[i] - mean;
		num += sq * sq;
	}
	printf("\nStandard Deviation : %lf", sqrt(num / size));
	getch();
}
