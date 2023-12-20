#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->rear == MAX_SIZE - 1);
}

int isEmpty(struct Queue* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full, cannot enqueue\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
        queue->rear = 0;
    } else {
        queue->rear++;
    }
    queue->items[queue->rear] = value;
    printf("Enqueued: %d\n", value);
}

int dequeue(struct Queue* queue) {
    int dequeued;
    if (isEmpty(queue)) {
        printf("Queue is empty, cannot dequeue\n");
        return -1;
    }
    dequeued = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front++;
    }
    printf("Dequeued: %d\n", dequeued);
    return dequeued;
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue();

    int choice, value;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(queue, value);
                break;
            case 2:
                dequeue(queue);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice, please enter a valid option.\n");
        }
    }

    return 0;
}