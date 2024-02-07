#include<stdio.h>
#include<conio.h>
#include<math.h>
int cube(int no) 
{
	return no * no * no;
}
int main()
{
	int size, i, no;
	printf("Enter how many elements you want to enter : ");
	scanf("%d", &size);
	int arrs[size], arrc[size];
	printf("Enter elements : ");
	for(i = 0; i < size; i++)
	{
		scanf("%d", &no);
		arrs[i] = sqrt(no);
		arrc[i] = cube(no);
		printf("square roots\tcubes\n");
		printf("%d\t\t%d\n", arrs[i], arrc[i]);
	}
	getch();
}
