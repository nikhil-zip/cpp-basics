# Username and Password Authentication in C

## Description

This is a simple beginner-level C program that checks whether the entered username and password are correct.

If both credentials match the predefined username and password, the program displays **"Access Granted!"**.

If either the username or password is incorrect, the program displays **"Access Denied!"**.

---

## Aim

To create a C program that verifies a user's username and password and provides access only when both credentials are correct.

---

## Correct Credentials

**Username:** `admin`

**Password:** `1234`

---

## Algorithm

1. Start the program.
2. Include the required header files:
   - `stdio.h` for input and output.
   - `string.h` for string comparison.
3. Declare character arrays for the username and password.
4. Store the correct username as `admin`.
5. Store the correct password as `1234`.
6. Ask the user to enter the username.
7. Read the username using `scanf()`.
8. Ask the user to enter the password.
9. Read the password using `scanf()`.
10. Compare the entered username with the correct username using `strcmp()`.
11. Compare the entered password with the correct password using `strcmp()`.
12. If both username and password are correct:
    - Display `Access Granted!`
13. Otherwise:
    - Display `Access Denied!`
14. Stop the program.

---

## Flow of the Program

```text
              START
                |
                v
        Enter Username
                |
                v
        Enter Password
                |
                v
     Compare Username
                |
                v
      Compare Password
                |
          Both Correct?
           /        \
         YES         NO
          |           |
          v           v
   Access Granted  Access Denied
          |           |
          +-----+-----+
                |
                v
               END
```

---

## Source Code

```c
#include <stdio.h>
#include <string.h>

int main() {

    char username[20];
    char password[20];

    char correctUsername[] = "admin";
    char correctPassword[] = "1234";

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (strcmp(username, correctUsername) == 0 &&
        strcmp(password, correctPassword) == 0) {

        printf("Access Granted!\n");

    } else {

        printf("Access Denied!\n");
    }

    return 0;
}
```

---

# Code Explanation

## 1. Header Files

```c
#include <stdio.h>
```

`stdio.h` is used for input and output functions such as:

- `printf()`
- `scanf()`

```c
#include <string.h>
```

`string.h` provides functions for working with strings.

In this program, it is required for:

```c
strcmp()
```

---

## 2. Username and Password Variables

```c
char username[20];
char password[20];
```

These character arrays store the username and password entered by the user.

For example:

```text
admin
```

is stored as a string in the `username` variable.

---

## 3. Correct Credentials

```c
char correctUsername[] = "admin";
char correctPassword[] = "1234";
```

These variables contain the predefined correct username and password.

The user's input will be compared with these values.

---

## 4. Taking Username Input

```c
printf("Enter username: ");
scanf("%s", username);
```

`printf()` displays a message asking the user for the username.

`scanf()` takes the username from the user.

The `%s` format specifier is used to read a string.

---

## 5. Taking Password Input

```c
printf("Enter password: ");
scanf("%s", password);
```

This takes the password entered by the user and stores it in the `password` variable.

---

## 6. Comparing Strings

```c
strcmp(username, correctUsername) == 0
```

`strcmp()` is used to compare two strings.

If both strings are exactly the same, `strcmp()` returns:

```text
0
```

For example:

```text
admin
admin
```

The result is:

```text
0
```

If the strings are different, `strcmp()` returns a non-zero value.

---

## 7. Checking Username and Password

```c
if (strcmp(username, correctUsername) == 0 &&
    strcmp(password, correctPassword) == 0)
```

There are two conditions:

```text
Username is correct
        AND
Password is correct
```

The `&&` operator means **AND**.

Both conditions must be true for access to be granted.

---

## 8. Access Granted

If both the username and password are correct:

```c
printf("Access Granted!\n");
```

The program displays:

```text
Access Granted!
```

---

## 9. Access Denied

If either the username or password is incorrect:

```c
printf("Access Denied!\n");
```

The program displays:

```text
Access Denied!
```

---

# Example Output

## Correct Login

```text
Enter username: admin
Enter password: 1234
Access Granted!
```

## Incorrect Password

```text
Enter username: admin
Enter password: 5678
Access Denied!
```

## Incorrect Username

```text
Enter username: user
Enter password: 1234
Access Denied!
```

---

# Concepts Used

This program demonstrates the following C programming concepts:

- Header files
- `stdio.h`
- `string.h`
- Character arrays
- Strings
- `printf()`
- `scanf()`
- `strcmp()`
- `if-else`
- Logical AND operator (`&&`)
- `return 0`
- Basic authentication logic

---

# Project Structure

```text
login-project/
│
├── login.c
└── README.md
```

---

# How to Compile and Run

## Using GCC

Compile the program:

```bash
gcc login.c -o login
```

Run the program:

### Windows

```bash
.\login.exe
```

### Linux / macOS

```bash
./login
```

---

# How the Program Works

The overall logic is:

```text
User enters username
        |
        v
User enters password
        |
        v
Compare username
        |
        v
Compare password
        |
        v
Are both correct?
      /     \
    YES      NO
     |        |
     v        v
  Grant     Deny
  Access    Access
```

---

# Learning Outcome

After completing this program, you should understand:

1. How to declare character arrays.
2. How strings are stored in C.
3. How to take string input.
4. How to compare two strings using `strcmp()`.
5. How to use `if-else`.
6. How to use the logical AND (`&&`) operator.
7. How simple authentication logic works.

---

## Important Note

This program is designed for **learning C programming**.

It is not a secure real-world authentication system because the username and password are stored directly in the source code.

Real authentication systems should use secure password hashing, proper input validation, and other security measures.

---

## Author

**Nikhil**

Beginner C Programming Practice