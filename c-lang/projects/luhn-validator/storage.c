#include "storage.h"
#include <stdio.h>
int save_report(const CardResult *r, CardCategory c, const char *path)
{
    FILE *f = fopen(path, "a");
    char masked[32];
    if (!f || !mask_card_number(r->digits, masked, sizeof masked))
    {
        if (f)
            fclose(f);
        return 0;
    }
    if (fprintf(f, "Network: %s\nCategory: %s\nMasked number: %s\nLength: %s\nPrefix: %s\nLuhn: %s\nResult: %s\n\n", network_name(r->network), category_name(c), masked, r->length_ok ? "PASS" : "FAIL", r->prefix_ok ? "PASS" : "FAIL", r->luhn_ok ? "PASS" : "FAIL", r->valid ? "VALID" : "INVALID") < 0)
    {
        fclose(f);
        return 0;
    }
    return fclose(f) == 0;
}
