#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *buffer;
    int position;
    int size;
} Stack;

Stack* createStack(int size) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    stack->buffer = (int *)malloc(size * sizeof(int));
    if (stack->buffer == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    stack->position = -1; 
    stack->size = size;
    return stack;
}

void push(Stack *stack, int value) {
    if (stack->position == stack->size - 1) {
        printf("Stack overflow\n");
        return;
    }

    stack->buffer[++stack->position] = value;
}

int pop(Stack *stack) {
    if (stack->position == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }

    return stack->buffer[stack->position--];
}

void printStack(Stack *stack) {
    if (stack->position == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");
    for (int i = 0; i <= stack->position; i++) {
        printf("%d ", stack->buffer[i]);
    }
    printf("\n");
}

int main() {
    int size;
    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    Stack *stack = createStack(size);

    printf("Enter %d elements of the stack:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &stack->buffer[i]);
        stack->position = i;
    }

    while (1) {
        printf("\nOptions:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print Stack\n");
        printf("4. Exit\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                if (stack->position == size - 1) {
                    printf("Stack is full\n");
                    break;
                }
                int value;
                printf("Enter the element to push: ");
                scanf("%d", &value);
                push(stack, value);
                printf("Element pushed successfully\n");
                break;
            }
            case 2: {
                if (stack->position == -1) {
                    printf("Stack is empty\n");
                    break;
                }
                int popped = pop(stack);
                printf("Popped element: %d\n", popped);
                break;
            }
            case 3: {
                printStack(stack);
                break;
            }
            case 4: {
                free(stack->buffer);
                free(stack);
                exit(EXIT_SUCCESS);
            }
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

