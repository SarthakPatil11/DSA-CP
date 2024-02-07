#include<stdio.h>
int main (void) {
    // int a, b, c;
    // float f1; //11.2
    // char c1;    //A, b
    // printf("Enter the vale of A and b: ");
    // scanf("%d %d %f %c", &a, &b, &f1, &c1);
    // c = a + b;
    // printf("Addition of A and b: %c", c);
    // int a[5] = {0, 1, 2, 3, 4};
	// printf("%d, %d", *a, a);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d", 1+i);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d", 1+j);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%c", 'A'+i);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%c", 'A'+j);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j < 4-i) printf(" ");
            else printf("%d", 1+j);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d", i);
        }
        printf("\n");
    }

    printf("\n");

    for (int i = 5; i >= 1; i--) {
        for (int j = 5; j >= i; j--) {
            printf("%d", j);
        }
        printf("\n");
    }
    
    printf("\n");

    for (int i = 1; i <= 5; i++) {
        for (int j = 5; j >= i; j--) {
            printf("%d", j);
        }
        printf("\n");
    }

    
    printf("\n");

    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}