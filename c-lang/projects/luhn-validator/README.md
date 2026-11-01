# Modular C Card Validation System

An educational Luhn and card-format validator. It does not prove that a card is genuine, active, or usable.

## Features

- Luhn validation and check-digit generation.
- Automatic Visa, Mastercard, American Express, and Discover detection using length and prefix rules; unmatched input is `Unknown`.
- Credit, Debit, or Prepaid category chosen by the user (the number cannot reliably identify the category).
- Reports and history show only a masked number, such as `**** **** **** 1096`.
- CSV validation history (`history.csv`) with date, time, network, category, masked number, and status.
- Text reports (`reports.txt`) and safe file-error handling.
- Terminal code calls reusable business functions so a future GUI can use `card.c`, `history.c`, and `storage.c` directly.

## Structure

| File | Purpose |
|---|---|
| `card.h/.c` | Input normalization, network detection, masking, Luhn and check-digit logic |
| `history.h/.c` | In-memory records, CSV load/save, display, and clear operations |
| `storage.h/.c` | Masked text report persistence |
| `main.c` | Small terminal interface only |

## Build and run with GCC on Windows

From this directory in PowerShell or the VS Code terminal:

```text
gcc -std=c11 -Wall -Wextra -Wpedantic -Wconversion -Wshadow main.c card.c history.c storage.c -o luhn.exe
.\luhn.exe
```

The program creates `history.csv` and `reports.txt` beside the executable. They contain masked numbers only. Use menu option 4 to clear history.

## Safe test cases

Use synthetic values only. `4000000000000002` is a commonly used test value, not proof of a real account:

1. Select Credit and enter `4000 0000 0000 0002`: Visa, length PASS, Luhn PASS, VALID.
2. Select Debit and enter `4000-0000-0000-0003`: Visa format detected, Luhn FAIL, INVALID.
3. Enter `1234abcd`: rejected as malformed input and not saved.
4. Enter `5555555555554444`: Mastercard format and Luhn PASS (synthetic test value).
5. Use menu 2 with `7992739871`: the check digit is `3`; only a masked generated sequence is displayed.
6. Use menu 3 to view records and menu 4 to clear them.

## Sample output

```text
========== CARD REPORT ==========
Category: Credit
Network: Visa
Masked number: **** **** **** 0002
Card length: 16
Length check: PASS
Prefix check: PASS
Luhn check: PASS
Result: VALID (format/checksum pass)
=================================
```
