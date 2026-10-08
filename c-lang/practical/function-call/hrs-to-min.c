#include <stdio.h>
int HoursToMinutes(int hrs, int min) {
    return hrs * 60 + min;
}
int main()
{
    int hrs, min, result;
    printf("Enter hours: ");
    scanf("%d", &hrs);
    printf("Enter minutes: ");
    scanf("%d", &min);
    result = HoursToMinutes(hrs, min);
    printf("%d hours and %d minutes is equal to %d minutes\n", hrs, min, result);
    return 0;
}

/* function call is a process of passing control to a function and 
returning back to the calling function after the execution of the called function.
In this program, we have defined a function called HoursToMinutes that takes 
two integer parameters (hrs and min) and returns the total number of minutes. 
The main function prompts the user to enter hours and minutes, calls the HoursToMinutes 
function to convert the input into total minutes, and then prints the result.*/