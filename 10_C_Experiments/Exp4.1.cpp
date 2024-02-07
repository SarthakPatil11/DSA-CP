#include<stdio.h>
#include<conio.h>
int i = 0, size = 0, result[10];
int add(int arr1[], int arr2[], int size, int i)
{
	if(i < size)
	{
		result[i] = arr1[i] + arr2[i];
		printf("%d ", result[i]);
		add(arr1, arr2, size, i + 1);
	}
}
int main()
{
	printf("Enter how many elements you want to enter : ");
	scanf("%d", &size);
	int arr1[size], arr2[size];
	result[size];
	printf("Enter the elements of 1st array : ");
	for(i = 0; i < size; i++) scanf("%d", &arr1[i]);
	printf("Enter the elements of 2nd array : ");
	for(i = 0; i < size; i++) scanf("%d", &arr2[i]);
	printf("Added array : ");
	add(arr1, arr2, size, 0);
	getch();
}
