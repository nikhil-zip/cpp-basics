#include<stdio.h>
int main()
   {
    int units;
    printf("Enter the number of units consumed:");
    scanf("%d",&units);
    if (units<=100)
    printf("Total electricity bill is: %d",units*5);
    else if (units<=200)
    printf("Total electricity bill is: %d", (100*5)+(units-100)*7);
    else
    printf("Total electricity bill is: %d", (100*5)+(100*7)+(units-200)*10);
    return 0;
   }