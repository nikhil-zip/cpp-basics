#include <stdio.h>

int main() {

    int a = 10;
    int b = 20;

    printf("AND (&&) = %d\n", (a < b) && (b > 15));
    printf("OR  (||) = %d\n", (a > b) || (b > 15));
    printf("NOT (!)  = %d\n", !(a > b));

    return 0;
}
// AND (&&): Returns true if both conditions are true
// OR (||): Returns true if at least one condition is true
// NOT (!): Returns true if the condition is false
