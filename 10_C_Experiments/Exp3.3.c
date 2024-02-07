#include<stdio.h>
#include<conio.h>
#include<math.h>
int main()
{
	int size, mean, i = 0, sum = 0, num = 0;
	printf("Enter how many elements you want to enter : ");
	scanf("%d", &size);
	int arr[size];
	printf("Enter elements : ");
	while(i < size)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
		i++;
	}
	mean = sum / size;
	printf("\nmean : %d\nDifference :", mean);
	for(i = 0; i < size; i++)
	{
		printf("%d ", arr[i] - mean);
		num += (arr[i] - mean) * (arr[i] - mean);
	}
	printf("\nStandard Deviation : %lf", sqrt(num / size));
	getch();
}
