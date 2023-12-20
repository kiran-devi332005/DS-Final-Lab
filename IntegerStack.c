#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Stack {
    int top;
    unsigned capacity;
    int* array;
};

struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack overflow!\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    return stack->array[stack->top--];
}

int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->array[stack->top];
}

void displayMenu() {
    printf("\nStack Operations Menu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Check if Empty\n");
    printf("5. Check if Full\n");
    printf("6. Exit\n");
}

int main() {
    struct Stack* stack = createStack(MAX_SIZE);
    int choice, item;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &item);
                push(stack, item);
                break;
            case 2:
                printf("Popped element: %d\n", pop(stack));
                break;
            case 3:
                printf("Top element: %d\n", peek(stack));
                break;
            case 4:
                printf("Stack is %s\n", isEmpty(stack) ? "empty" : "not empty");
                break;
            case 5:
                printf("Stack is %s\n", isFull(stack) ? "full" : "not full");
                break;
            case 6:
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}1