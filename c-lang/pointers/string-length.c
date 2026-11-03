#include <stdio.h>
int main() {
    char str[100];
    char *ptr = str;
    int count = 0;
    printf("Enter a string: ");
    scanf("%99s", str);
    while(*(ptr + count) != '\0') {
        count++;
    }
    printf("Length = %d", count);
    return 0;
}