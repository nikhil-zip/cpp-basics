#ifndef HISTORY_H
#define HISTORY_H
#include "card.h"
#define HISTORY_MAX 200
typedef struct
{
    char date[11], time[9], masked[32], status[8];
    CardNetwork network;
    CardCategory category;
} HistoryRecord;
typedef struct
{
    HistoryRecord records[HISTORY_MAX];
    size_t count;
} History;
void history_init(History *);
int history_load(History *, const char *);
int history_save(const History *, const char *);
int history_add(History *, const CardResult *, CardCategory);
void history_print(const History *);
int history_clear(History *, const char *);
#endif
