#include <stdio.h>
int main()
{
    int i,n;
    float sum=0.0,avg;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    float arr[n];
    printf("Enter %d elements:\n ", n);
    for(i=0;i<n;i++)
    {
        printf("Element %d: ", i+1);
        scanf("%f",&arr[i]);
    }
for(i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    avg=sum/n;
    printf("Sum of elements: %.2f\n", sum);
    printf("Average of elements: %.2f\n", avg);
    return 0;
}