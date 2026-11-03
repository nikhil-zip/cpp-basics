#include <stdio.h>
int main()
 {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;
    int sum = 0, i;
    for(i = 0; i < 5; i++) {
        sum = sum + *(ptr + i);
    }
    printf("Sum = %d", sum);
    return 0;
}