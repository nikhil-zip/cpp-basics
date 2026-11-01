
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function declarations
int calculateSum(char number[], int doubleRightmost);
int validateLuhn(char number[]);
int validateLength(char number[], int network);
int validatePrefix(char number[], int network);
int getCheckDigit(char number[]);
void validateCard();
void generateCheckDigit();
void clearInput();

// Network constants
#define VISA 1
#define MASTERCARD 2
#define AMEX 3
#define DISCOVER 4
#define OTHER 5

// Calculate Luhn sum
int calculateSum(char number[], int doubleRightmost) {
    int sum = 0;
    int length = strlen(number);
    int shouldDouble = doubleRightmost;

    for (int i = length - 1; i >= 0; i--) {
        int digit = number[i] - '0';

        if (shouldDouble) {
            digit *= 2;

            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
        shouldDouble = !shouldDouble;
    }

    return sum;
}

// Check Luhn algorithm
int validateLuhn(char number[]) {
    return calculateSum(number, 0) % 10 == 0;
}

// Check card length
int validateLength(char number[], int network) {
    int len = strlen(number);

    switch (network) {
        case VISA:
            return len == 13 || len == 16 || len == 19;

        case MASTERCARD:
            return len == 16;

        case AMEX:
            return len == 15;

        case DISCOVER:
            return len >= 16 && len <= 19;

        case OTHER:
            return len >= 12 && len <= 19;
    }

    return 0;
}

// Check card prefix
int validatePrefix(char number[], int network) {

    int len = strlen(number);

    int first2 = (number[0] - '0') * 10
               + (number[1] - '0');

    int first4 = 0;
    int first6 = 0;

    for (int i = 0; i < 4; i++) {
        first4 = first4 * 10 + (number[i] - '0');
    }

    for (int i = 0; i < 6; i++) {
        first6 = first6 * 10 + (number[i] - '0');
    }

    switch (network) {

        case VISA:
            return number[0] == '4';

        case MASTERCARD:
            return (first2 >= 51 && first2 <= 55) ||
                   (first4 >= 2221 && first4 <= 2720);

        case AMEX:
            return first2 == 34 || first2 == 37;

        case DISCOVER:
            return first4 == 6011 ||
                   first2 == 65 ||
                   (first6 >= 644000 && first6 <= 649999) ||
                   (first6 >= 622126 && first6 <= 622925);

        case OTHER:
            return 1;
    }

    return 0;
}

// Generate check digit
int getCheckDigit(char number[]) {
    int sum = calculateSum(number, 1);

    return (10 - (sum % 10)) % 10;
}

// Clear input buffer
void clearInput() {
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF);
}

// Validate card
void validateCard() {

    char category[20];
    char raw[128];
    char number[64];

    int network;
    int j = 0;

    printf("\nSELECT CARD CATEGORY\n");
    printf("1. Credit Card\n");
    printf("2. Debit Card\n");
    printf("3. Prepaid Card\n");
    printf("Enter choice: ");

    int type;

    if (scanf("%d", &type) != 1) {
        printf("Invalid choice!\n");
        clearInput();
        return;
    }

    clearInput();

    if (type == 1)
        strcpy(category, "Credit");
    else if (type == 2)
        strcpy(category, "Debit");
    else if (type == 3)
        strcpy(category, "Prepaid");
    else {
        printf("Invalid card category!\n");
        return;
    }

    printf("\nSELECT CARD NETWORK\n");
    printf("1. Visa\n");
    printf("2. Mastercard\n");
    printf("3. American Express\n");
    printf("4. Discover\n");
    printf("5. Other\n");
    printf("Enter choice: ");

    if (scanf("%d", &network) != 1) {
        printf("Invalid choice!\n");
        clearInput();
        return;
    }

    clearInput();

    if (network < 1 || network > 5) {
        printf("Invalid network!\n");
        return;
    }

    printf("\nEnter card number: ");

    if (fgets(raw, sizeof(raw), stdin) == NULL) {
        printf("Input error!\n");
        return;
    }

    // Remove spaces and hyphens
    for (int i = 0; raw[i] != '\0'; i++) {

        if (raw[i] == '\n')
            break;

        if (raw[i] == ' ' || raw[i] == '-')
            continue;

        if (!isdigit((unsigned char)raw[i])) {
            printf("Invalid input! Digits only.\n");
            return;
        }

        if (j >= 19) {
            printf("Card number is too long!\n");
            return;
        }

        number[j++] = raw[i];
    }

    number[j] = '\0';

    if (j < 12) {
        printf("Card number is too short!\n");
        return;
    }

    // Network names
    char *networkName[] = {
        "",
        "Visa",
        "Mastercard",
        "American Express",
        "Discover",
        "Other"
    };

    printf("\n========== CARD REPORT ==========\n");

    printf("Category: %s\n", category);
    printf("Network: %s\n", networkName[network]);
    printf("Card Length: %d\n", j);

    int lengthOK = validateLength(number, network);
    int prefixOK = validatePrefix(number, network);
    int luhnOK = validateLuhn(number);

    printf("\nLength Check: %s\n",
           lengthOK ? "PASS" : "FAIL");

    printf("Prefix Check: %s\n",
           prefixOK ? "PASS" : "FAIL");

    printf("Luhn Check: %s\n",
           luhnOK ? "PASS" : "FAIL");

    if (lengthOK && prefixOK && luhnOK) {
        printf("\nRESULT: NUMBER PASSES ALL CHECKS!\n");
    } else {
        printf("\nRESULT: NUMBER DOES NOT PASS ALL CHECKS.\n");
    }

    printf("=================================\n");
}

// Generate check digit
void generateCheckDigit() {

    char number[100];

    printf("\nEnter number without check digit: ");

    if (scanf("%99s", number) != 1) {
        printf("Input error!\n");
        return;
    }

    int len = strlen(number);

    if (len == 0) {
        printf("Empty input!\n");
        return;
    }

    for (int i = 0; i < len; i++) {
        if (!isdigit((unsigned char)number[i])) {
            printf("Digits only!\n");
            return;
        }
    }

    int digit = getCheckDigit(number);

    printf("\nRequired Check Digit: %d\n", digit);
    printf("Complete Number: %s%d\n", number, digit);
}

// Main function
int main() {

    int choice;

    do {

        printf("\n=================================\n");
        printf("       CARD VALIDATION SYSTEM\n");
        printf("=================================\n");

        printf("1. Validate Card\n");
        printf("2. Generate Check Digit\n");
        printf("3. Exit\n");

        printf("=================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input!\n");
            clearInput();
            continue;
        }

        clearInput();

        switch (choice) {

            case 1:
                validateCard();
                break;

            case 2:
                generateCheckDigit();
                break;

            case 3:
                printf("Thank you for using Card Validator!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 3);

    return 0;
}
