#include<stdio.h>
int main(){
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    for(int i=2; i<=n/2; i++){
        if(n%i==0){
            printf("%d is a composite number\n", n);
            break;
        }
        else
            printf("%d is a prime number\n", n);
            break;
    }
    return 0;
}
//prime number is a natural number greater than 1 that cannot be
//formed by multiplying two smaller natural numbers. A prime number 
//is a natural number greater than 1 that has no positive divisors other than 1 and itself. 
//A composite number is a natural number greater than 1 that is not prime, meaning it can be 
//formed by multiplying two smaller natural numbers.
