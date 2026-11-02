#include<stdio.h>
int main()
{
    int arr[100],i,n,largest;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n", n);
    for(i=0;i<n;i++)
    {
        printf("Element %d: ", i+1);
        scanf("%d",&arr[i]);
    }
    largest=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]>largest)
        {
            largest=arr[i];
        }
    }
    printf("Largest element in the array is: %d\n",largest);
    return 0;
}