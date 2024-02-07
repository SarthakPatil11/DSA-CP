#include<stdio.h>
int main(){
//	unsigned char n = 0;
	int bits = 0, ans = 0, i;
	
	printf("Enter the number: ");
	scanf("%d", &bits);
	for(i = 1; i < bits; i++){
		ans *= 2;
	}
	printf("-%d to %d", ans, ans-1);
	
//	num = 1 << 2;			// 1 << 2 it means the 0100 the new number. basically it creates the number 0001 and it shifts '1' by 2 positions.
//	printf("number: %d", 1 << 2); // it will print 4 (0100)
	
//	n  = ~n;
	
//	printf("number: %u", n);
	return 0;
}
