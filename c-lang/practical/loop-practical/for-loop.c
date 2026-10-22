#include<stdio.h>
int main()
{
    int i=1;
    int sum=0;
    int n;
    printf("Enter the number to sum upto:");
    scanf("%d", &n);
    for(i=1; i<=n; i++)
    {
        sum += i;
    }
    printf("Sum of 1 to %d natural numbers is: %d\n", n,sum);
    return 0;
}
// difference between for loop and while loop is that 
// for loop is used when the number of iterations is known, 
// while loop is used when the number of iterations is not known.