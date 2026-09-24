#include <stdio.h>

int main() {

    int a;

    a = 10;
    printf("a = 10  : %d\n", a);

    a += 5;
    printf("a += 5   : %d\n", a);

    a -= 3;
    printf("a -= 3   : %d\n", a);

    a *= 2;
    printf("a *= 2   : %d\n", a);

    a /= 4;
    printf("a /= 4   : %d\n", a);

    a %= 3;
    printf("a %%= 3   : %d\n", a);

    return 0;
}
// a = 10  : Assigns the value 10 to variable a
// a += 5   : Adds 5 to a and assigns the result back to a
// a -= 3   : Subtracts 3 from a and assigns the result back to a
// a *= 2   : Multiplies a by 2 and assigns the result back to a
// a /= 4   : Divides a by 4 and assigns the result back to a
// a %%= 3   : Calculates the remainder of a divided by 3 and assigns the result back to a