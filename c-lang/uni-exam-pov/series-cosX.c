#include <stdio.h>

double power(double x, int n)
{
    double result = 1;
    int i;

    for(i = 1; i <= n; i++)
        result = result * x;

    return result;
}

double factorial(int n)
{
    double fact = 1;
    int i;

    for(i = 1; i <= n; i++)
        fact = fact * i;

    return fact;
}

int main(void)
{
    double x, sum = 0, term;
    int n, i, p;

    printf("Enter x in radians: ");
    scanf("%lf", &x);

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        p = 2*i;

        term = power(x, p) / factorial(p);

        if(i % 2 == 0)
            sum = sum + term;
        else
            sum = sum - term;
    }

    printf("Cos(x) = %lf", sum);

    return 0;
}