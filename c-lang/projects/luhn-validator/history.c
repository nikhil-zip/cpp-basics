#include "history.h"
#include <stdio.h>
#include <string.h>
#include <time.h>
void history_init(History *h) { h->count = 0; }
static CardNetwork parse_network(const char *s)
{
    if (strcmp(s, "Visa") == 0)
        return NETWORK_VISA;
    if (strcmp(s, "Mastercard") == 0)
        return NETWORK_MASTERCARD;
    if (strcmp(s, "American Express") == 0)
        return NETWORK_AMEX;
    if (strcmp(s, "Discover") == 0)
        return NETWORK_DISCOVER;
    return NETWORK_UNKNOWN;
}
static CardCategory parse_category(const char *s) { return strcmp(s, "Debit") == 0 ? CATEGORY_DEBIT : (strcmp(s, "Prepaid") == 0 ? CATEGORY_PREPAID : CATEGORY_CREDIT); }
int history_load(History *h, const char *path)
{
    FILE *f = fopen(path, "r");
    char line[256], date[11], tim[9], net[32], cat[16], masked[32], status[8];
    if (!f)
        return 1;
    fgets(line, sizeof line, f);
    while (h->count < HISTORY_MAX && fgets(line, sizeof line, f))
    {
        if (sscanf(line, "%10[^,],%8[^,],%31[^,],%15[^,],%31[^,],%7[^\n]", date, tim, net, cat, masked, status) == 6)
        {
            HistoryRecord *r = &h->records[h->count++];
            strcpy(r->date, date);
            strcpy(r->time, tim);
            strcpy(r->masked, masked);
            strcpy(r->status, status);
            r->network = parse_network(net);
            r->category = parse_category(cat);
        }
    }
    fclose(f);
    return 1;
}
int history_save(const History *h, const char *path)
{
    FILE *f = fopen(path, "w");
    size_t i;
    if (!f)
        return 0;
    fputs("date,time,network,category,masked_number,status\n", f);
    for (i = 0; i < h->count; ++i)
    {
        const HistoryRecord *r = &h->records[i];
        if (fprintf(f, "%s,%s,%s,%s,%s,%s\n", r->date, r->time, network_name(r->network), category_name(r->category), r->masked, r->status) < 0)
        {
            fclose(f);
            return 0;
        }
    }
    return fclose(f) == 0;
}
int history_add(History *h, const CardResult *result, CardCategory category)
{
    time_t now;
    struct tm *tmv;
    HistoryRecord *r;
    if (h->count >= HISTORY_MAX)
        return 0;
    r = &h->records[h->count++];
    now = time(NULL);
    tmv = localtime(&now);
    if (!tmv || !mask_card_number(result->digits, r->masked, sizeof r->masked))
    {
        h->count--;
        return 0;
    }
    strftime(r->date, sizeof r->date, "%Y-%m-%d", tmv);
    strftime(r->time, sizeof r->time, "%H:%M:%S", tmv);
    r->network = result->network;
    r->category = category;
    strcpy(r->status, result->valid ? "VALID" : "INVALID");
    return 1;
}
void history_print(const History *h)
{
    size_t i;
    if (!h->count)
    {
        puts("No validation history.");
        return;
    }
    puts("\nDate       Time     Network          Category  Masked number              Status");
    for (i = 0; i < h->count; ++i)
        printf("%-10s %-8s %-16s %-9s %-26s %s\n", h->records[i].date, h->records[i].time, network_name(h->records[i].network), category_name(h->records[i].category), h->records[i].masked, h->records[i].status);
}
int history_clear(History *h, const char *path)
{
    FILE *f;
    h->count = 0;
    f = fopen(path, "w");
    if (!f)
        return 0;
    fputs("date,time,network,category,masked_number,status\n", f);
    return fclose(f) == 0;
}
