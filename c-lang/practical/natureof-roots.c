#include <stdio.h>
int main()
{
    int a, b, c, d;
    printf("Enter the value of a,b,c:");
    scanf("%d %d %d", &a, &b, &c);
    if (a == 0)
        printf("Not a quadratic equation");
    else
        d = b * b - 4 * a * c;
    if (d > 0)
    printf("Real or Distinct Roots");
    else if(d==0)
    printf("Real and Equal roots");
    else
    printf("Complex Roots");
    return 0;
}
