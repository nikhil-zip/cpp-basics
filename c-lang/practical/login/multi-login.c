#include <stdio.h>
#include <string.h>

int main() {

    char username[20];
    char password[20];

    char usernames[3][20] = {
        "admin",
        "nikhil",
        "student"
    };
    char passwords[3][20] = {
        "1234",
        "5678",
        "1111"
    };

    int login = 0;

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < 3; i++) {

        if (strcmp(username, usernames[i]) == 0 &&
            strcmp(password, passwords[i]) == 0) {
            login = 1;
            break;
        }
    }
    if (login == 1) {
        printf("Access Granted!\n");
    } else {
        printf("Access Denied!\n");
    }
    return 0;
}