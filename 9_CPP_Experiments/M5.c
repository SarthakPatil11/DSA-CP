#include<stdio.h>
int main(){
	int i;
	unsigned char num = 0;
	
	printf("Enter a number: ");
	scanf("%d", &num);
	
	printf("Entered number: %u\n", num);
	for(i = 0; i < 8; i++){
		if(num & (1 << i)){
			printf("\n%d bit: SET.", i);
			num = ~(1 << i) & num;
		}
		else{
			printf("\n%d bit: NOT SET.", i);
			num = num | 1 << i;
		}
	}
	
	printf("\n\nToggled number: %u\n", num);
	for(i = 0; i < 8; i++){
		if(num & (1 << i)) printf("\n%d bit: SET.", i);
		else printf("\n%d bit: NOT SET.", i);
	}
	return 0;
}
