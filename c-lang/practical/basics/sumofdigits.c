#include<stdio.h>
int main()
{
    int n, sum=0, digit;
    printf("Enter a number: ");
    scanf("%d", &n);
    while(n>0)
    {
        digit = n%10;
        sum += digit;
        n /= 10;
    }
    printf("Sum of digits: %d\n", sum);
    return 0;
}
//digit = n%10;  // This line extracts the last digit of the number n by taking the remainder when n is divided by 10.
//sum += digit;  // This line adds the extracted digit to the sum variable, which keeps track of the total sum of digits.
//n /= 10;  // This line removes the last digit from the number n by performing integer division by 10, effectively shifting the digits to the right.