#include<stdio.h>
#include<stdlib.h>

#define MAX 5

struct stack {
    int arr[MAX];
    int top;
};

void init_stack(struct stack *stack) {
    stack->top = -1;
}

int isFull(struct stack *stack) {
    return stack->top == MAX - 1;
}

int isEmpty(struct stack *stack) {
    return stack->top == -1;
}

void push(struct stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        stack->arr[++stack->top] = value;
        printf("%d pushed to stack\n", value);
    }
}

int pop(struct stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow! Cannot pop\n");
        return -1;
    } else {
        return stack->arr[stack->top--];
    }
}

int peek(struct stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty! Cannot peek\n");
        return -1;
    } else {
        return stack->arr[stack->top];
    }
}

int main() {
    struct stack stack;
    init_stack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element is: %d\n", peek(&stack));
    printf("Popped element: %d\n", pop(&stack));

    push(&stack, 60);
    printf("Top element is now: %d\n", peek(&stack));

    pop(&stack);

    return 0;
}
