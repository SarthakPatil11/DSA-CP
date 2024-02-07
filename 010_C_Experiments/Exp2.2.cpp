#include<stdio.h>
#include<conio.h>
int main()
{
	int i, sum = 0, temp = 0, r = 0;
	printf("the numbers are = ");
	for(i = 1; i < 501; i++)
	{
		temp = i;
		while(temp != 0)
		{	
			r = temp % 10;
			sum += r * r * r;
			temp /= 10;
		}
		if(sum == i) printf("\n%d", sum);
		if(temp == 0) sum = 0;
	} 
}

