#include <stdio.h>

// Function declaration
int factorial(int n);

int main() {
    int number;
    printf("Enter the Number:");
    scanf("%d", &number);
    int result = factorial(number);

    
    printf("Factorial of %d is %d\n", number, result);
    return 0;
}

// Recursive function definition
int factorial(int n) {
    // 1. Base case: standard termination rule
    if (n <= 1) {
        return 1;
    } 
    // 2. Recursive case: function calls itself
    else {
        return n * factorial(n - 1);
    }
}
