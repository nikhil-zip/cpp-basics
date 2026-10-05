#include<stdio.h>
int main()
{
    int i=1;
    int sum=0;
    do
    {
        sum += i;
        i++;
    } while(i<=10);
    printf("Sum of first 10 natural numbers: %d\n", sum);
    return 0;
}
// difference between do-while loop and while loop is that
// do-while loop is used when the number of iterations is not known,    
// while loop is used when the number of iterations is known.
