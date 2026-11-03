#include <stdio.h>
int main() {
    int arr[5] = {10, 15, 20, 25, 30};
    int *ptr = arr;
    int even = 0, odd = 0, i;
    for(i = 0; i < 5; i++) {
        if(*(ptr + i) % 2 == 0) {
            even++;
        }
        else {
            odd++;
        }
    }
    printf("Even numbers = %d\n", even);
    printf("Odd numbers = %d", odd);
    return 0;
}