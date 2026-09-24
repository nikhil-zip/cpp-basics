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
//#include <stdio.h>

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
// a++ post-increment: returns the current value of a, then increments a by 1
// ++a pre-increment: increments a by 1, then returns the new value of a
// a-- post-decrement: returns the current value of a, then decrements a by 1
// --a pre-decrement: decrements a by 1, then returns the new value
