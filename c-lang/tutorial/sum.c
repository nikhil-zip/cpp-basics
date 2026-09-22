#include <stdio.h>

int main() {
    int a, b, sum;
    printf("Enter First integer: "); 
    scanf("%d", &a);
    printf("Enter Second integer: ");
    scanf("%d", &b);
    sum = a + b;    
    printf("Sum: %d\n", sum);

    return 0;
}