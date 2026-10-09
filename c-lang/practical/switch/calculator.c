#include<stdio.h>
int main()
{
    double a, b;
    char op;
    printf("Enter value of a:");
    scanf("%lf", &a);
    printf("Enter value of b:");
    scanf("%lf", &b);
    printf("Enter operator (+, -, *, /):");
    scanf(" %c", &op);
switch(op){
    case '+': 
    printf("Result: %.2lf\n", a+b);
    break;
    case '-': 
    printf("Result: %.2lf\n", a-b);
    break;
    case '*':
    printf("Result: %.2lf\n", a*b);
    break;
    case '/':  
    if (b!=0)
    {
    printf("Cannot divide by zero\n");
    } 
    printf("Result: %.2lf\n", a/b);
    break;
    default:
    printf("Invalid Operator\n");
    break;
}
return 0;


}