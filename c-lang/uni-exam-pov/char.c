#include <stdio.h>

int main(void)
{
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    if((ch >= 'A' && ch <= 'Z') ||
       (ch >= 'a' && ch <= 'z'))
    {
        if(ch == 'A' || ch == 'E' || ch == 'I' ||
           ch == 'O' || ch == 'U' ||
           ch == 'a' || ch == 'e' || ch == 'i' ||
           ch == 'o' || ch == 'u')
        {
            printf("Vowel");
        }
        else
        {
            printf("Consonant");
        }
    }
    else if(ch >= '0' && ch <= '9')
    {
        printf("Digit");
    }
    else
    {
        printf("Special Symbol");
    }

    return 0;
}