#include<stdio.h>
    int main()
    {
        char ch;
        printf("Enter one Alphabet:");
        scanf("%c", &ch);
        if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
        printf("It is a Vowel.");
        else 
        printf("It is a Consonant.");
        return 0;
    }