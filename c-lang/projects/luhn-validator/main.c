#include "card.h"
#include "history.h"
#include "storage.h"
#include <stdio.h>
#include <string.h>
static void clear_input(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}
static int read_int(const char *p, int *v)
{
    printf("%s", p);
    if (scanf("%d", v) != 1)
    {
        clear_input();
        return 0;
    }
    clear_input();
    return 1;
}
static int choose_category(CardCategory *c)
{
    int n;
    if (!read_int("Category (1 Credit, 2 Debit, 3 Prepaid): ", &n) || n < 1 || n > 3)
        return 0;
    *c = (CardCategory)(n - 1);
    return 1;
}
static void validate_ui(History *h)
{
    char raw[CARD_MAX_INPUT], digits[CARD_MAX_DIGITS + 1], masked[32];
    CardCategory c;
    CardResult r;
    if (!choose_category(&c))
    {
        puts("Invalid category.");
        return;
    }
    printf("Card number (digits, spaces or hyphens): ");
    if (!fgets(raw, sizeof raw, stdin) || !normalize_card_number(raw, digits, sizeof digits))
    {
        puts("Invalid card number format (12-19 digits required).");
        return;
    }
    validate_card(digits, &r);
    mask_card_number(digits, masked, sizeof masked);
    puts("\n========== CARD REPORT ==========");
    printf("Category: %s\nNetwork: %s\nMasked number: %s\nCard length: %zu\nLength check: %s\nPrefix check: %s\nLuhn check: %s\nResult: %s\n", category_name(c), network_name(r.network), masked, r.length, r.length_ok ? "PASS" : "FAIL", r.prefix_ok ? "PASS" : "FAIL", r.luhn_ok ? "PASS" : "FAIL", r.valid ? "VALID (format/checksum pass)" : "INVALID");
    puts("=================================");
    if (!history_add(h, &r, c) || !history_save(h, "history.csv"))
        puts("Warning: could not save history safely.");
    if (!save_report(&r, c, "reports.txt"))
        puts("Warning: could not save report safely.");
}
static void generate_ui(void)
{
    char raw[CARD_MAX_INPUT], digits[CARD_MAX_DIGITS + 1], masked[32];
    size_t l;
    int d;
    printf("Number without check digit: ");
    if (!fgets(raw, sizeof raw, stdin) || !normalize_card_number(raw, digits, sizeof digits))
    {
        puts("Invalid digits.");
        return;
    }
    l = strlen(digits);
    if (l >= CARD_MAX_DIGITS)
    {
        puts("Too many digits.");
        return;
    }
    d = calculate_check_digit(digits);
    digits[l] = (char)('0' + d);
    digits[l + 1] = '\0';
    printf("Required check digit: %d\n", d);
    if (mask_card_number(digits, masked, sizeof masked))
        printf("Masked generated sequence: %s\n", masked);
}
int main(void)
{
    History h;
    int choice;
    history_init(&h);
    history_load(&h, "history.csv");
    do
    {
        puts("\n===== CARD VALIDATION SYSTEM =====\n1. Validate card\n2. Generate check digit\n3. View history\n4. Clear history\n5. Exit");
        if (!read_int("Choice: ", &choice))
        {
            puts("Invalid choice.");
            continue;
        }
        switch (choice)
        {
        case 1:
            validate_ui(&h);
            break;
        case 2:
            generate_ui();
            break;
        case 3:
            history_print(&h);
            break;
        case 4:
            if (history_clear(&h, "history.csv"))
                puts("History cleared.");
            else
                puts("Could not clear history.");
            break;
        case 5:
            puts("Educational validator closed.");
            break;
        default:
            puts("Choose 1-5.");
        }
    } while (choice != 5);
    return 0;
}
