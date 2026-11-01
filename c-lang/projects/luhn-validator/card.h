#ifndef CARD_H
#define CARD_H
#include <stddef.h>
#define CARD_MAX_DIGITS 19
#define CARD_MAX_INPUT 128
typedef enum
{
    NETWORK_UNKNOWN,
    NETWORK_VISA,
    NETWORK_MASTERCARD,
    NETWORK_AMEX,
    NETWORK_DISCOVER
} CardNetwork;
typedef enum
{
    CATEGORY_CREDIT,
    CATEGORY_DEBIT,
    CATEGORY_PREPAID
} CardCategory;
typedef struct
{
    char digits[CARD_MAX_DIGITS + 1];
    size_t length;
    CardNetwork network;
    int length_ok, prefix_ok, luhn_ok, valid;
} CardResult;
const char *network_name(CardNetwork n);
const char *category_name(CardCategory c);
int normalize_card_number(const char *input, char *output, size_t size);
CardNetwork detect_network(const char *digits);
int validate_card(const char *digits, CardResult *result);
int calculate_check_digit(const char *digits_without_check);
int mask_card_number(const char *digits, char *masked, size_t size);
#endif
