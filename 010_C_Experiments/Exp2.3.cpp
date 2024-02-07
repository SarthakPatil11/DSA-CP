	#include<stdio.h>
#include<conio.h>
int main()
{
//	int choice, no, i, fact = 1, flag = 0, e = 0;
//	while(true)
//	{
//		printf("\nEnter the choice as per following,\n1 : Factorial of a number.\n2 : Prime or not.\n3 : Odd or even.\n4 : Exit.\n");
//		scanf("%d", &choice);
//		switch(choice)
//		{
//			case 1:
//				printf("Enter the number : ");
//				scanf("%d", &no);
//				if(no < 0) printf("Number is negative.");
//				else
//				{
//					for(i = 1; i <= no; ++i) fact *= i;
//					printf("Factoral of no is %d.", fact);
//				}
//				break;
//			case 2:
//				printf("Enter the number : ");
//				scanf("%d", &no);
//				if(no < 0) printf("Number is negative.");
//				else
//				{
//					for(i = 2; i < no && no % i == 0; i++) flag = 1;
//					if(flag == 0) printf("The number is Prime.");
//					else printf("The number is not prime.");
//				}
//				flag = 0;
//				break;
//			case 3:
//				printf("Enter the number : ");
//				scanf("%d", &no);
//				if(no % 2 == 0) printf("Number is Even.");
//				else printf("Number is Odd.");
//				break;
//			case 4:
//				e++;
//				break;
//			default:
//				printf("Your entered choice is wrong.");
//		}
//		if(e > 0) break;
//	}
	int y, x = 0 ;
do
{
y = x ;
} while ( x == 0 ) ;
printf("%d, %d", x , y);
getch();
}
