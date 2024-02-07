#include<stdio.h>
#include<conio.h>
int t, pass, r, j, result;
int arr_add(int r_arr[], int i, int size)
{
	if(i < size - 1)
	{
		result += r_arr[i];
		arr_add(r_arr, i + 1, size);
	}
	if(result == add) for(i = 0; i < size; i++) printf(" %d", r_arr[i]);
}

int arr_create(int arr1[], int i, int size)
{
	if(i < size - 1)
	{
		r = size - arr1[i]
		for(j = 0; j < size; j++)
		{
			if(arr1[j] == r) 
			{
				r_arr[t] = r += arr1[j];
				t++;
			}
		}
		r_arr[t] = 
		arr_create(arr1[], i + 1, size);
	}
	arr_add(r_arr, 0, size);
	pass++;
	if(pass < size - 1) arr_create(arr1[], 0, size);
}
int main()
{
	int size = 0, i, add = 0;
	printf("Enter the size of array : ");
	scanf("%d", &size);
	int arr1[size];
	printf("Enter the addition : ");
	scanf("%d", &add);
	printf("Enter the elements of array : ");
	for(i = 0; i < size; i++) scanf("%d", &arr1[i]);
//	sort(arr1, add, 0, 0);
	printf("The sorted array : ");
	for(i = 0; i < size; i++) printf(" %d", arr1[i]);
	getch();
}
