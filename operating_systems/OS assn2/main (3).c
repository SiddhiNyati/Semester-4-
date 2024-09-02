#include "student.h"
#include <stdio.h>

int main() {
    FILE* fp = fopen("/home/siddhi04/assn2/data/students", "r");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    Student* head = NULL;
    char name[50];
    int roll_number;

    while (fscanf(fp, "%s %d", name, &roll_number) == 2) {
        Student* newStudent = createStudent(name, roll_number);
        addStudent(&head, newStudent);
    }

    fclose(fp);

    // Print the initial list of students
    printf("List of Students:\n");
    printStudents(head);

    int choice;
    do {
        printf("\n1. Delete a roll number\n");
        printf("2. Search for a student by roll number\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Delete a roll number
                printf("Enter the roll number to delete: ");
                scanf("%d", &roll_number);

                // Check if the roll number exists before deletion
                Student* foundStudent = searchStudent(head, roll_number);
                if (foundStudent != NULL) {
                    deleteStudent(&head, roll_number);
                    printf("Updated List of Students:\n");
                    printStudents(head);
                } else {
                    printf("Roll number %d does not exist.\n", roll_number);
                }
                break;
            }
            case 2: {
                // Search for a student by roll number
                printf("Enter the roll number to search: ");
                scanf("%d", &roll_number);
                Student* foundStudent = searchStudent(head, roll_number);
                if (foundStudent != NULL) {
                    printf("Student found - Name: %s, Roll Number: %d\n", foundStudent->name, foundStudent->roll_number);
                } else {
                    printf("Student not found\n");
                }
                break;
            }
            case 3:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

