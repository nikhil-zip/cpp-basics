
# Luhn Algorithm Validator

A beginner-friendly C programming project that
implements the Luhn Algorithm (Modulus 10 Algorithm)
to validate numeric sequences.

## Features

- Validate numbers using the Luhn algorithm.
- Generate missing check digits.
- Display checksum and remainder.
- Menu-driven command-line interface.
- Modular code using functions.

## Technologies Used

- C Programming
- GCC Compiler
- VS Code

## How to Run

Compile:

    gcc main.c -o luhn

Run:

    ./luhn

On Windows:

    .\luhn.exe

## Algorithm

1. Start from the rightmost digit.
2. Double every second digit moving right to left.
3. Subtract 9 if the doubled digit exceeds 9.
4. Calculate the total sum.
5. Check whether the sum is divisible by 10.

## Learning Outcomes

- Conditional statements
- Loops
- Functions
- Strings
- Modulus operator
- Logical problem solving

## Disclaimer

This project checks mathematical checksums only.
It does not verify whether a financial card or
account exists.
