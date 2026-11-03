#include<stdio.h>
int main()
{
    int a = 20, *p;
    p= &a;
    ++*p;
    a=a+5;
    --*p;
    --a;
    printf("%d %d", a, *p);
    return 0;
}