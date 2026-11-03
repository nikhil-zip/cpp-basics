#include <stdio.h>

int main() {
    int numbers[3] = {10, 20, 30};
    printf("Before 1: %d\n", numbers[1]);
    printf("Before 2: %d\n", numbers[2]);
    numbers[1] = 99; 
    numbers[2]= 222;
    printf("After 1:  %d\n", numbers[1]);
    printf("After 2:  %d\n", numbers[2]);
    return 0;
}
