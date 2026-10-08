#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*
    Function 1:
    Convert one Roman character into its integer value.
*/
int value(char c)
{
    switch (c)
    {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;

        default:
            return 0;
    }
}


/*
    Function 2:
    Convert Roman numeral into an integer.

    Example:
    XIV

    X = 10
    I = 1
    V = 5

    10 + (-1) + 5 = 14
*/
int romanToInt(const char *s)
{
    int result = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        int current = value(s[i]);
        int next = value(s[i + 1]);

        if (current < next)
        {
            result -= current;
        }
        else
        {
            result += current;
        }
    }

    return result;
}


/*
    Function 3:
    Convert an integer into its STANDARD Roman numeral.

    Example:

    4    -> IV
    9    -> IX
    40   -> XL
    90   -> XC
    400  -> CD
    900  -> CM
    1994 -> MCMXCIV
*/
void intToRoman(int number, char *roman)
{
    int values[] = {
        1000, 900, 500, 400,
        100,  90,  50,  40,
        10,   9,   5,   4, 1
    };

    const char *symbols[] = {
        "M", "CM", "D", "CD",
        "C", "XC", "L", "XL",
        "X", "IX", "V", "IV", "I"
    };

    int position = 0;

    /*
        Go through all Roman values
        from largest to smallest.
    */
    for (int i = 0; i < 13; i++)
    {
        while (number >= values[i])
        {
            /*
                Copy the Roman symbol into the output.
            */
            int j = 0;

            while (symbols[i][j] != '\0')
            {
                roman[position] = symbols[i][j];
                position++;
                j++;
            }

            number -= values[i];
        }
    }

    /*
        End the string.
    */
    roman[position] = '\0';
}


/*
    Function 4:
    Validate the Roman numeral.

    Method:

    1. Convert Roman -> integer
    2. Convert integer -> standard Roman
    3. Compare both strings

    If they are identical:
        VALID

    Otherwise:
        INVALID
*/
int isValidRoman(const char *input)
{
    int number;
    char standardRoman[100];

    /*
        Convert input to integer.
    */
    number = romanToInt(input);

    /*
        Roman numerals in this program
        are limited to 1 - 3999.
    */
    if (number < 1 || number > 3999)
    {
        return 0;
    }

    /*
        Convert the number back into
        the standard Roman representation.
    */
    intToRoman(number, standardRoman);

    /*
        Compare user's input with the
        correct Roman representation.
    */
    if (strcmp(input, standardRoman) == 0)
    {
        return 1;
    }

    return 0;
}


int main()
{
    char userInput[100];

    printf("Enter a Roman numeral: ");

    /*
        Read maximum 99 characters.
    */
    scanf("%99s", userInput);


    /*
        Convert lowercase letters to uppercase.

        Example:

        xiv -> XIV
        xxl -> XXL
    */
    for (int i = 0; userInput[i] != '\0'; i++)
    {
        userInput[i] = toupper((unsigned char)userInput[i]);
    }


    /*
        Check whether the Roman numeral is valid.
    */
    if (!isValidRoman(userInput))
    {
        printf("\nInvalid Roman numeral: %s\n", userInput);
        return 1;
    }


    /*
        If valid, convert it to integer.
    */
    int result = romanToInt(userInput);


    printf("\nRoman numeral : %s\n", userInput);
    printf("Integer value  : %d\n", result);

    return 0;
}
