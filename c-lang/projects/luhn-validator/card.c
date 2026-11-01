#include "card.h"
#include <ctype.h>
#include <string.h>
const char *network_name(CardNetwork n)
{
    switch (n)
    {
    case NETWORK_VISA:
        return "Visa";
    case NETWORK_MASTERCARD:
        return "Mastercard";
    case NETWORK_AMEX:
        return "American Express";
    case NETWORK_DISCOVER:
        return "Discover";
    default:
        return "Unknown";
    }
}
const char *category_name(CardCategory c)
{
    switch (c)
    {
    case CATEGORY_CREDIT:
        return "Credit";
    case CATEGORY_DEBIT:
        return "Debit";
    default:
        return "Prepaid";
    }
}
int normalize_card_number(const char *in, char *out, size_t size)
{
    size_t i, u = 0;
    if (!in || !out || size < 2)
        return 0;
    for (i = 0; in[i] && in[i] != '\n' && in[i] != '\r'; ++i)
    {
        if (in[i] == ' ' || in[i] == '-')
            continue;
        if (!isdigit((unsigned char)in[i]) || u + 1 >= size)
            return 0;
        out[u++] = in[i];
    }
    out[u] = '\0';
    return u >= 1 && u <= CARD_MAX_DIGITS;
}
static int range_number(const char *s, size_t n, int lo, int hi)
{
    int v = 0;
    size_t i;
    for (i = 0; i < n; ++i)
        v = v * 10 + s[i] - '0';
    return v >= lo && v <= hi;
}
CardNetwork detect_network(const char *s)
{
    size_t l = strlen(s);
    if ((l == 13 || l == 16 || l == 19) && s[0] == '4')
        return NETWORK_VISA;
    if (l == 16 && (range_number(s, 2, 51, 55) || range_number(s, 4, 2221, 2720)))
        return NETWORK_MASTERCARD;
    if (l == 15 && (strncmp(s, "34", 2) == 0 || strncmp(s, "37", 2) == 0))
        return NETWORK_AMEX;
    if (l >= 16 && l <= 19 && (strncmp(s, "6011", 4) == 0 || strncmp(s, "65", 2) == 0 || range_number(s, 6, 644000, 649999) || range_number(s, 6, 622126, 622925)))
        return NETWORK_DISCOVER;
    return NETWORK_UNKNOWN;
}
static int luhn_sum(const char *s, int first)
{
    int sum = 0, dbl = first;
    size_t i = strlen(s);
    while (i--)
    {
        int d = s[i] - '0';
        if (dbl)
        {
            d *= 2;
            if (d > 9)
                d -= 9;
        }
        sum += d;
        dbl = !dbl;
    }
    return sum;
}
int calculate_check_digit(const char *s) { return (10 - (luhn_sum(s, 1) % 10)) % 10; }
int validate_card(const char *s, CardResult *r)
{
    size_t l;
    CardNetwork n;
    if (!s || !r)
        return 0;
    l = strlen(s);
    n = detect_network(s);
    r->length = l;
    r->network = n;
    r->length_ok = l >= 12 && l <= CARD_MAX_DIGITS;
    r->prefix_ok = n != NETWORK_UNKNOWN;
    if (n == NETWORK_VISA)
        r->length_ok = l == 13 || l == 16 || l == 19;
    if (n == NETWORK_MASTERCARD)
        r->length_ok = l == 16;
    if (n == NETWORK_AMEX)
        r->length_ok = l == 15;
    if (n == NETWORK_DISCOVER)
        r->length_ok = l >= 16 && l <= 19;
    r->luhn_ok = r->length_ok && luhn_sum(s, 0) % 10 == 0;
    r->valid = r->length_ok && r->prefix_ok && r->luhn_ok;
    strncpy(r->digits, s, CARD_MAX_DIGITS);
    r->digits[CARD_MAX_DIGITS] = '\0';
    return 1;
}
int mask_card_number(const char *s, char *out, size_t size)
{
    size_t l, i, p = 0;
    if (!s || !out || size < 6)
        return 0;
    l = strlen(s);
    if (l < 4)
        return 0;
    for (i = 0; i < l - 4; ++i)
    {
        if (i && i % 4 == 0)
        {
            if (p + 1 >= size)
                return 0;
            out[p++] = ' ';
        }
        if (p + 1 >= size)
            return 0;
        out[p++] = '*';
    }
    if (p && p % 5 != 0)
        out[p++] = ' ';
    for (i = l - 4; i < l; ++i)
    {
        if (p + 1 >= size)
            return 0;
        out[p++] = s[i];
    }
    out[p] = '\0';
    return 1;
}
