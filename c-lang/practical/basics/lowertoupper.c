#include<stdio.h>
  int main()
  {
    char ch;
    printf("Enter a lowercase character:");
    scanf("%c",&ch);
    if (ch>='a' && ch<='z')
    {
        printf("Character in Uppercase is %c.",ch-32);
    }
    else
    {
        printf("Character is not a lowercase letter.");
    }
    return 0;
  }