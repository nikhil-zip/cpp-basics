#include<stdio.h>
int main()
{
    int arr[5];
    int largest, second_largest;
    int *ptr = arr;
    printf("Enter 5 numbers:");
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", ptr + i);
    }   
    largest = *ptr;
    second_largest = -999999;
    for(int i = 0; i < 5; i++)
    {
        if(*(ptr + i) > largest)
        {
            second_largest = largest;
            largest = *(ptr + i);
        }
        else if(*(ptr + i) > second_largest && *(ptr + i) != largest)
        {
            second_largest = *(ptr + i);
        }
    }
    printf("Largest number: %d\n", largest);
    printf("Second largest number: %d\n", second_largest);
    return 0;
}