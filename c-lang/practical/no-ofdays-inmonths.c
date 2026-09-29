#include <stdio.h>

int main() {
    int month, year;

    printf("Enter Month (1-12): ");
    scanf("%d", &month);
    printf("Enter Year: ");
    scanf("%d", &year);

    if (month < 1 || month > 12) {
        printf("Invalid Month");
    } else if (month == 2) {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
            printf("Days = 29");
        } else {
            printf("Days = 28");
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        printf("Days = 30");
    } else {
        printf("Days = 31");
    }

    return 0;
}