#include <stdio.h>

struct Student {
    char name[30];
    int roll;
    int age;
    float percentage;
};
int main() {
    struct Student s1;
    s1.name[0] = 'N';
    s1.name[1] = 'i';
    s1.name[2] = 'k';
    s1.name[3] = 'h';
    s1.name[4] = 'i';
    s1.name[5] = 'l';
    s1.name[6] = '\0';
    s1.roll = 101;
    s1.age = 22;    
    s1.percentage = 85.5;
    printf("Name: %s\n", s1.name);
    printf("Roll: %d\n", s1.roll);
    printf("Age: %d\n", s1.age);
    printf("Percentage: %.2f\n", s1.percentage);
    return 0;
}
// This program defines a structure named 'Student' with members for name, roll number, age, and percentage. 
// It then creates an instance of the structure, assigns values to its members, and prints them to the console.