#include<stdio.h>
int main(){
    int n;
    unsigned long long fact = 1;
    printf("Enter a positive number: ");
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        fact *= i;
    }
    printf("Factorial of %d is: %llu", n, fact);
    return 0;
}