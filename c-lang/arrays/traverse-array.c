#include<stdio.h>
int main()
{
    int num[100],i,n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n", n);
    for(i=0;i<n;i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d",&num[i]);
    }
    printf("Elements in the array are:\n");
    for(i=0;i<n;i++)
    {
        printf("%d ", num[i]);
    }
    return 0;
}