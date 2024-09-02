#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*)malloc(sizeof(int));

    if (ptr != NULL) {
        printf("Address obtained from malloc: %p\n", (void*)ptr);
        free(ptr);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
