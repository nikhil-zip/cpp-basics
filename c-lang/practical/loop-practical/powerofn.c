#include <stdio.h>
#include <math.h>

int main() {
    double x, n, power; 
    printf("Enter the value of x: ");
    scanf("%lf", &x); 
    printf("Enter the value of n: ");
    scanf("%lf", &n); 
    power = pow(x, n);
    printf("Result: %f\n", power);
    return 0;
}