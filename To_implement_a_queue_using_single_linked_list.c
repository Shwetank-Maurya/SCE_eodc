#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(struct Queue* q, int value) {
    struct Node* newNode = createNode(value);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        printf("Enqueued: %d\n", value);
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
    printf("Enqueued: %d\n", value);
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    struct Node* temp = q->front;
    int removedData = temp->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    printf("Dequeued: %d\n", removedData);
    return removedData;
}

int peek(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    printf("Front element: %d\n", q->front->data);
    return q->front->data;
}

int isEmpty(struct Queue* q) {
    return (q->front == NULL);
}

void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = q->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);
    dequeue(q);
    peek(q);
    display(q);
    return 0;
}
