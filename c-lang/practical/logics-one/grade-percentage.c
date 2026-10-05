#include <stdio.h>

int main()
{
    float m1, m2, m3, m4, m5;
    float total, percentage;

    printf("Enter marks of English: ");
    scanf("%f", &m1);
    printf("Enter marks of Mathematics: ");
    scanf("%f", &m2);
    printf("Enter marks of Physics: ");
    scanf("%f", &m3);
    printf("Enter marks of Chemistry: ");
    scanf("%f", &m4);
    printf("Enter marks of Hindi: ");
    scanf("%f", &m5);

    total = m1 + m2 + m3 + m4 + m5;
    percentage = total / 5;

    printf("Total marks = %.2f\n", total);
    printf("Percentage = %.2f%%\n", percentage);

    if (percentage >= 91)
    {
        printf("Grade = A+");
    }
    else if (percentage >= 81)
    {
        printf("Grade = A");
    }
    else if (percentage >= 71)
    {
        printf("Grade = B+");
    }
    else if (percentage >= 61)
    {
        printf("Grade = B");
    }
    else if (percentage >= 51)
    {
        printf("Grade = C+");
    }
    else if (percentage >= 41)
    {
        printf("Grade = D");
    }
    else
    {
        printf("Grade = Fail");
    }

    return 0;
}