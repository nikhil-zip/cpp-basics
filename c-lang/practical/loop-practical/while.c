#include<stdio.h>
int main()
{
    int i=1;
    int sum=0;
    while(i<=10)
    {
        sum += i;
        i++;
    }
    printf("Sum of first 10 natural numbers: %d\n", sum);
    return 0;
}