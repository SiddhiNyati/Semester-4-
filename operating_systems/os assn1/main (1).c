#include "student.h"
#include <stdio.h>

int main() {
	FILE* fp = fopen("/home/siddhi04/assn1/data/students", "r");
   
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

    printf("List of Students:\n");
    printStudents(head);

    return 0;
}
