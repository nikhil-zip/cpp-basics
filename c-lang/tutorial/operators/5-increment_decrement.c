#include <stdio.h>

int main() {

    int a = 5;

    printf("Initial a       = %d\n", a);

    printf("Post-increment  = %d\n", a++);
    printf("After a++       = %d\n", a);

    printf("Pre-increment   = %d\n", ++a);
    printf("After ++a       = %d\n", a);

    printf("Post-decrement  = %d\n", a--);
    printf("After a--       = %d\n", a);

    printf("Pre-decrement   = %d\n", --a);
    printf("After --a       = %d\n", a);

    return 0;
}
//