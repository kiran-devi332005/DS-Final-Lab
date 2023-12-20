#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Change this value to set the maximum size of the queue

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int *array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (!queue) return NULL;
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;  // This is important for the circularity
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    if (!queue->array) return NULL;
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d enqueued to the queue\n", item);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int front(struct Queue* queue) {
    if (isEmpty(queue)) return -1;
    return queue->array[queue->front];
}

int rear(struct Queue* queue) {
    if (isEmpty(queue)) return -1;
    return queue->array[queue->rear];
}

void display(struct Queue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    for (i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

int main() {
    struct Queue* queue = createQueue(MAX_SIZE);
    int choice, item;

    while (1) {
        printf("\n------ Queue Menu ------\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display front element\n");
        printf("4. Display rear element\n");
        printf("5. Display all elements\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &item);
                enqueue(queue, item);
                break;
            case 2:
                printf("Dequeued element: %d\n", dequeue(queue));
                break;
            case 3:
                printf("Front element is: %d\n", front(queue));
                break;
            case 4:
                printf("Rear element is: %d\n", rear(queue));
                break;
            case 5:
                display(queue);
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }

    return 0;
}