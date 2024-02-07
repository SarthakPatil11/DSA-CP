#include<stdio.h>
#include<conio.h>
int main()
{
	float br, er;
	printf("-----------TAXI FARE CALCULATOR-----------\n");
	printf("Enter the beginning odometer reading = ");
	scanf("%f", &br);
	printf("Enter the ending odometer reading = ");
	scanf("%f", &er);
	printf("You traveled a distance of %f meters.\n", er - br);
	printf("At rs. 1.50 per mile, youre fare is Rs. %f.", (er - br) * 1.50);
	getch();
}


