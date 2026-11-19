
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Structure declaration
struct Student {
    int roll;
    char name[50];
    int age;
    float marks;
};
// Function declarations
void addStudent();
void viewStudents();
void searchStudent();
void updateStudent();
void deleteStudent();
void countStudents();

void readLine(char *buffer, int size);
int readInt(const char *message);
float readFloat(const char *message);

// Read a line of user input
void readLine(char *buffer, int size) {
    if (fgets(buffer, size, stdin) != NULL) {
        buffer[strcspn(buffer, "\n")] = '\0';
    }
}

// Read an integer safely
int readInt(const char *message) {
    char input[100];
    char extra;
    int value;

    while (1) {
        printf("%s", message);
        readLine(input, sizeof(input));

        if (sscanf(input, " %d %c", &value, &extra) == 1) {
            return value;
        }

        printf("Invalid input! Please enter a number.\n");
    }
}

// Read a float safely
float readFloat(const char *message) {
    char input[100];
    char extra;
    float value;

    while (1) {
        printf("%s", message);
        readLine(input, sizeof(input));

        if (sscanf(input, " %f %c", &value, &extra) == 1) {
            return value;
        }

        printf("Invalid input! Please enter a valid number.\n");
    }
}

// 1. Add a new student
void addStudent() {
    FILE *fp;
    struct Student s;
    char name[50];

    printf("\n===== ADD STUDENT =====\n");

    s.roll = readInt("Enter Roll Number: ");

    fp = fopen("students.txt", "a+");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // Check whether roll number already exists
    rewind(fp);

    struct Student temp;

    while (fscanf(fp, "%d|%49[^|]|%d|%f\n",
                  &temp.roll, temp.name,
                  &temp.age, &temp.marks) == 4) {

        if (temp.roll == s.roll) {
            printf("This roll number already exists!\n");
            fclose(fp);
            return;
        }
    }

    printf("Enter Student Name: ");
    readLine(name, sizeof(name));

    // Prevent the file delimiter from corrupting records
    if (strchr(name, '|') != NULL || strlen(name) == 0) {
        printf("Invalid name! Name cannot be empty or contain |.\n");
        fclose(fp);
        return;
    }

    strcpy(s.name, name);

    s.age = readInt("Enter Age: ");
    s.marks = readFloat("Enter Marks: ");

    fprintf(fp, "%d|%s|%d|%.2f\n",
            s.roll, s.name, s.age, s.marks);

    fclose(fp);

    printf("\nStudent added successfully!\n");
}

// 2. View all students
void viewStudents() {
    FILE *fp;
    struct Student s;
    int count = 0;

    printf("\n===== ALL STUDENTS =====\n");

    fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("No student records found!\n");
        return;
    }

    printf("\n%-10s %-25s %-10s %-10s\n",
           "Roll", "Name", "Age", "Marks");

    printf("-------------------------------------------------------\n");

    while (fscanf(fp, "%d|%49[^|]|%d|%f\n",
                  &s.roll, s.name,
                  &s.age, &s.marks) == 4) {

        printf("%-10d %-25s %-10d %-10.2f\n",
               s.roll, s.name, s.age, s.marks);

        count++;
    }

    if (count == 0) {
        printf("No student records available.\n");
    }

    printf("\nTotal Students: %d\n", count);

    fclose(fp);
}

// 3. Search student by roll number
void searchStudent() {
    FILE *fp;
    struct Student s;
    int roll, found = 0;

    printf("\n===== SEARCH STUDENT =====\n");

    roll = readInt("Enter Roll Number to Search: ");

    fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    while (fscanf(fp, "%d|%49[^|]|%d|%f\n",
                  &s.roll, s.name,
                  &s.age, &s.marks) == 4) {

        if (s.roll == roll) {

            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", s.roll);
            printf("Name        : %s\n", s.name);
            printf("Age         : %d\n", s.age);
            printf("Marks       : %.2f\n", s.marks);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found!\n");
    }

    fclose(fp);
}

// 4. Update student details
void updateStudent() {
    FILE *fp, *temp;
    struct Student s;
    int roll, found = 0;

    printf("\n===== UPDATE STUDENT =====\n");

    roll = readInt("Enter Roll Number to Update: ");

    fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    temp = fopen("temp.txt", "w");

    if (temp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    while (fscanf(fp, "%d|%49[^|]|%d|%f\n",
                  &s.roll, s.name,
                  &s.age, &s.marks) == 4) {

        if (s.roll == roll) {

            printf("\nCurrent Student Details:\n");
            printf("Name: %s\n", s.name);
            printf("Age: %d\n", s.age);
            printf("Marks: %.2f\n", s.marks);

            printf("\nEnter New Details:\n");

            char newName[50];

            printf("Enter New Name: ");
            readLine(newName, sizeof(newName));

            if (strlen(newName) == 0 ||
                strchr(newName, '|') != NULL) {
                printf("Invalid name. Keeping old name.\n");
            } else {
                strcpy(s.name, newName);
            }

            s.age = readInt("Enter New Age: ");
            s.marks = readFloat("Enter New Marks: ");

            found = 1;
        }

        fprintf(temp, "%d|%s|%d|%.2f\n",
                s.roll, s.name, s.age, s.marks);
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        if (remove("students.txt") != 0 ||
            rename("temp.txt", "students.txt") != 0) {
            printf("Error replacing the student file!\n");
        } else {
            printf("\nStudent updated successfully!\n");
        }
    } else {
        remove("temp.txt");
        printf("Student not found!\n");
    }
}

// 5. Delete student
void deleteStudent() {
    FILE *fp, *temp;
    struct Student s;
    int roll, found = 0;

    printf("\n===== DELETE STUDENT =====\n");

    roll = readInt("Enter Roll Number to Delete: ");

    fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("No records found!\n");
        return;
    }

    temp = fopen("temp.txt", "w");

    if (temp == NULL) {
        printf("Error creating temporary file!\n");
        fclose(fp);
        return;
    }

    while (fscanf(fp, "%d|%49[^|]|%d|%f\n",
                  &s.roll, s.name,
                  &s.age, &s.marks) == 4) {

        if (s.roll == roll) {
            found = 1;
            continue;
        }

        fprintf(temp, "%d|%s|%d|%.2f\n",
                s.roll, s.name, s.age, s.marks);
    }

    fclose(fp);
    fclose(temp);

    if (found) {
        if (remove("students.txt") != 0 ||
            rename("temp.txt", "students.txt") != 0) {
            printf("Error replacing the student file!\n");
        } else {
            printf("\nStudent deleted successfully!\n");
        }
    } else {
        remove("temp.txt");
        printf("Student not found!\n");
    }
}

// 6. Count total students
void countStudents() {
    FILE *fp;
    struct Student s;
    int count = 0;

    fp = fopen("students.txt", "r");

    if (fp == NULL) {
        printf("\nTotal Students: 0\n");
        return;
    }

    while (fscanf(fp, "%d|%49[^|]|%d|%f\n",
                  &s.roll, s.name,
                  &s.age, &s.marks) == 4) {
        count++;
    }

    fclose(fp);

    printf("\nTotal Registered Students: %d\n", count);
}

// Main function
int main() {
    int choice;

    printf("\n====================================\n");
    printf("   STUDENT RECORD MANAGEMENT SYSTEM\n");
    printf("====================================\n");

    do {
        printf("\n========== MAIN MENU ==========\n");
        printf("1. Add Student\n");
        printf("2. View All Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Count Total Students\n");
        printf("0. Exit\n");
        printf("===============================\n");

        choice = readInt("Enter Your Choice: ");

        switch (choice) {

            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                updateStudent();
                break;

            case 5:
                deleteStudent();
                break;

            case 6:
                countStudents();
                break;

            case 0:
                printf("\nThank you for using the system!\n");
                break;

            default:
                printf("\nInvalid choice! Try again.\n");
        }

    } while (choice != 0);

    return 0;
}
