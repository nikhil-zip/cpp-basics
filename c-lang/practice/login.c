#include <stdio.h>
#include <string.h>

int main() {

    char username[20];
    char password[20];

    char correctUsername[] = "admin";
    char correctPassword[] = "1234";

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, correctUsername) == 0 &&
        strcmp(password, correctPassword) == 0) {

        printf("Access Granted!\n");

    } else {

        printf("Access Denied!\n");
    }

    return 0;
}