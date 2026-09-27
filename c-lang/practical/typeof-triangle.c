#include<stdio.h>
 int main()
 {
    int a,b,c;
    printf("Enter length of Triangle in cm:");
    scanf("%d %d %d", &a, &b, &c);
    if ((a==b)&& (b==c))
    printf("It is a Equilateral Triangle.");
    else if ((a==b) || (b==c) || (a==c))
    printf("It is a Isosceles Triangle.");
    else
    printf("It is a Scalene Triangle.");
    return 0;

 }