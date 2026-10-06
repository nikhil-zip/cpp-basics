#include<stdio.h>
int main(){
    int n, i, factorial = 1;
    printf("Enter a number: ");
    scanf("%d", &n);
    for(int i=n;i>=1;i--){
        factorial *= i;
    }
    printf("Factorial of %d is: %d", n, factorial);
    return 0;
}