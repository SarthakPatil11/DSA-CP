#include<stdio.h>
#include<conio.h>
int size = 0, ans = 0;
int fibo(int cur, int pr, int size, int temp)
{
	if(size == temp) printf("%d\n%d\n", pr, cur);
	if(size - 2 > 0)
	{
		ans = cur + pr;
		printf("%d\n", ans);
		fibo(ans, cur, size - 1, temp);
	}
}
int main()
{
	printf("Enter how many elements you want in series : ");
	scanf("%d", &size);
	fibo(1, 0, size, size);
	getch();
}
