#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at the beginning\n", value);
}

void insertAtEnd(int value) {
    struct Node* newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Inserted %d at the end\n", value);
}

void insertAtPosition(int value, int position) {
    if (position <= 1) {
        insertAtBeginning(value);
        return;
    }

    struct Node* temp = head;
    int i = 1;
    while (i < position - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL || temp->next == NULL) {
        insertAtEnd(value);
    } else {
        struct Node* newNode = createNode(value);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        printf("Inserted %d at position %d\n", value, position);
    }
}

void deleteAtPosition(int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;

    if (position == 1) {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        printf("Deleted node at position 1: %d\n", temp->data);
        free(temp);
        return;
    }

    int i = 1;
    while (i < position && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position.\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("Deleted node at position %d: %d\n", position, temp->data);
    free(temp);
}

void displayForward() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Forward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        if (temp->next == NULL) break;
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayBackward() {
    struct Node* temp = head;
    if (temp == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Backward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

void sortList() {
    if (head == NULL) return;

    struct Node* i = head;
    while (i != NULL) {
        struct Node* j = i->next;
        while (j != NULL) {
            if (i->data > j->data) {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
    printf("List sorted in ascending order.\n");
}

int main() {
    insertAtBeginning(30);
    insertAtBeginning(20);
    insertAtEnd(40);
    insertAtEnd(60);
    insertAtPosition(50, 3);
    displayForward();
    displayBackward();

    deleteAtPosition(2);
    displayForward();
    displayBackward();

    sortList();
    displayForward();
    displayBackward();

    return 0;
}
