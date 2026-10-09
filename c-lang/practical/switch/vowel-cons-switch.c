#include<stdio.h>
#include <ctype.h>
int main()
{
char ch;
printf("Enter a letter:");
scanf("%c", &ch);
switch (ch)
{
case 'a' :
case 'e' :
case 'i' :
case 'o' :
case 'u' :
case 'A' :
case 'E' :
case 'I' :
case 'O' :
case 'U' :
    printf("Vowel\n");
    break;

default:
if (isalpha(ch)){   
printf("Consonant\n");
}else{
    printf("Enter a valid alphabet...");
   }
    break;
}
return 0;
}