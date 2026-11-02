#include <stdio.h>

int main() {
    int numbers[3] = {10, 20, 30};
    printf("Before: %d\n", numbers[1]);
    numbers[1] = 99; 
    printf("After:  %d\n", numbers[1]);
    return 0;
}
