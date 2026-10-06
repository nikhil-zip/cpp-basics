#include<stdio.h>
#include<math.h>
int main()
{
    int x,n,power;
    printf("Enter the value of x: ");
    scanf("%d", &x);
    printf("Enter the value of n: ");
    scanf("%d", &n);
    power= pow(x,n);
    printf("Result %d", power);
    return 0;
}