#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

struct person {
    char name[50];
    int age;
};

int main() {
    struct person *ptr = (struct person *)malloc(sizeof(struct person));
    strcpy(ptr->name, "Siddhi Nyati"); 
    ptr->age = 19;

    int pid = fork();

    if (pid == 0) {
        ptr->age = 20;
        printf("Child process:\n");
        printf("Name: %s, Age: %d, Address: %p\n", ptr->name, ptr->age, (void*)ptr);
    } else if (pid > 0) {
        printf("Parent process:\n");
        printf("Name: %s, Age: %d, Address: %p\n", ptr->name, ptr->age, (void*)ptr);
    } else {
        printf("Fork failed!\n");
        return 1;
    }

    free(ptr);
    return 0;
}

