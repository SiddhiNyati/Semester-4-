// Task 12
#include <stdio.h>

struct MyStruct {
    int x;
    int arr[5];
};

int main() {
    struct MyStruct myObj;
    struct MyStruct *ptr = &myObj;

    printf("Original address: %p\n", (void*)ptr);
    ptr += 1;
    printf("New address after increment: %p\n", (void*)ptr);

    return 0;
}
