#include <stdio.h>

int main() {

    int a = 5;
    int b = 3;

    printf("Bitwise AND (&)  = %d\n", a & b);
    printf("Bitwise OR (|)   = %d\n", a | b);
    printf("Bitwise XOR (^)  = %d\n", a ^ b);
    printf("Bitwise NOT (~a)  = %d\n", ~a);
    printf("Left Shift (<<)   = %d\n", a << 1);
    printf("Right Shift (>>)  = %d\n", a >> 1);

    return 0;
}
// Bitwise AND (&): Performs a bitwise AND operation between two integers.
// Bitwise OR (|): Performs a bitwise OR operation between two integers.
// Bitwise XOR (^): Performs a bitwise XOR operation between two integers.
// Bitwise NOT (~): Inverts the bits of an integer.
// Left Shift (<<): Shifts the bits of an integer to the left by a specified number of positions.
// Right Shift (>>): Shifts the bits of an integer to the right by a specified number of positions.
