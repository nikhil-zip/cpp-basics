#include <stdio.h>

int main() {
    int month, year;
    printf("Enter Month (1-12): ");
    scanf("%d", &month);
    switch (month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            printf("Days = 31\n");
            break; 
        case 4:
        case 6:
        case 9:
        case 11:
            printf("Days = 30\n");
            break;  
        case 2:
            printf("Enter Year: ");
            scanf("%d", &year);
            if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
                printf("Days = 29\n");
            } else {
                printf("Days = 28\n");
            }
            break;   
        default:
            printf("Invalid Month\n");
            break;
    }
    return 0;
}
