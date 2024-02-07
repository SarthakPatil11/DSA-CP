#include<stdio.h>
#include<conio.h>
int temp = 0, pass = 0, m = 0;
int sort(int arr1[], int size, int i)
{
	if(i < size - 1)
	{
		if(arr1[i] > arr1[i + 1])
		{
			temp = arr1[i + 1];
			arr1[i + 1] = arr1[i];
			arr1[i] = temp; 
		}
		m++;
		printf("%d\n", m);
		sort(arr1, size, i + 1);
	}
	pass++;
	if(pass < size - 1) sort(arr1, size, 0);
}
int main()
{
	int size = 0, i;
	printf("Enter the size of array : ");
	scanf("%d", &size);
	int arr1[size];
	printf("Enter the elements of array : ");
	for(i = 0; i < size; i++) scanf("%d", &arr1[i]);
	sort(arr1, size, 0);
	printf("The sorted array : ");
	for(i = 0; i < size; i++) printf(" %d", arr1[i]);
	getch();
}
