#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, char item) {
    if (isFull(stack)) {
        printf("Stack Overflow!\n");
        return;
    }
    stack->array[++stack->top] = item;
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        return '\0';
    }
    return stack->array[stack->top--];
}

void reverseString(struct Stack* stack, char* input) {
    int length = strlen(input);
    for (int i = 0; i < length; i++) {
        push(stack, input[i]);
    }
    for (int i = 0; i < length; i++) {
        input[i] = pop(stack);
    }
}

int main() {
    struct Stack* stack = createStack(MAX_SIZE);
    char input[MAX_SIZE];
    int choice;

    do {
        printf("\n---- Menu ----\n");
        printf("1. Reverse a string\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                getchar(); // Clearing the input buffer
                fgets(input, MAX_SIZE, stdin);
                input[strcspn(input, "\n")] = '\0'; // Removing newline character

                reverseString(stack, input);
                printf("Reversed string: %s\n", input);
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 2);

    free(stack->array);
    free(stack);

    return 0;
}