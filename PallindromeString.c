#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

struct Stack {
    int top;
    char array[MAX_SIZE];
};

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
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

int isPalindromeString(char* str) {
    int len = strlen(str);
    struct Stack* stack = createStack();

    // Push half of the characters into the stack
    for (int i = 0; i < len / 2; i++) {
        push(stack, str[i]);
    }

    // Check if the string is of odd length
    if (len % 2 != 0) {
        // Skip the middle character for odd-length strings
        len++;
    }

    // Compare the remaining characters with the stack
    for (int i = len / 2; i < len; i++) {
        if (pop(stack) != str[i]) {
            free(stack);
            return 0; // Not a palindrome
        }
    }

    free(stack);
    return 1; // Palindrome
}

int main() {
    char input[MAX_SIZE];
    int choice;

    do {
        printf("\n---- Menu ----\n");
        printf("1. Check palindrome for string:\n");
        printf("2. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a string: ");
                scanf("%s", input);

                // Convert input to lowercase for case-insensitive comparison
                for (int i = 0; input[i] != '\0'; i++) {
                    input[i] = tolower(input[i]);
                }

                if (isPalindromeString(input)) {
                    printf("The string is a palindrome!\n");
                } else {
                    printf("The string is not a palindrome!\n");
                }
                break;
            case 2:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 2);

    return 0;
}