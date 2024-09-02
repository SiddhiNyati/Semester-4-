// Task 10
#include <stdio.h>

int main() {
    char *s1 = "John";
    char s2[] = "John";

    printf("Address of s1: %p\n", (void*)s1);
    printf("Address of s2: %p\n", (void*)s2);

    return 0;
}
