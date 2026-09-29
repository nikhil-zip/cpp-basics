#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter sides of Triangle a,b,c:");
    scanf("%d %d %d", &a, &b, &c);
    if(a+b>c && b+c>a && a+c>b)
    printf("Valid Triangle");
    else 
    printf("Not a valid Triangle");
    return 0;
}