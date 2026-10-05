#include<stdio.h>
int main()
{
    int i=1;
    int sum=0;
    for(i=1; i<=10; i++)
    {
        sum += i;
    }
    printf("Sum of first 10 natural numbers: %d\n", sum);
    return 0;
}
// difference between for loop and while loop is that 
// for loop is used when the number of iterations is known, 
// while loop is used when the number of iterations is not known.