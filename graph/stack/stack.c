#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

// Static functions

struct StackNode * createStackNode(struct Node * node) {
    struct StackNode * stackNode = (struct StackNode *)malloc(sizeof(struct StackNode));
    if (stackNode == NULL) {
        perror("Error while creating a new stack node");
        exit(EXIT_FAILURE);
    }
    stackNode->next = NULL;
    stackNode->node = node;
    return stackNode;
}

// Implementation function

Stack * createStack() {
    struct Stack * stack = (Stack *)malloc(sizeof(Stack));
    if (stack == NULL) {
        perror("Error while creating a stack");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

void deleteStack(Stack * stack) {
    struct StackNode * head = stack->top;
    while (head != NULL) {
        pop(stack);
        head = stack->top;
    }
}

void push(struct Stack * stack, struct Node * node) {
    struct StackNode * newTop = createStackNode(node);
    newTop->next = stack->top;
    stack->top = newTop;
}

struct Node * pop(struct Stack * stack) {
    struct  StackNode * oldTop = stack->top;
    stack->top = oldTop->next;
    struct Node * node = oldTop->node;
    free(oldTop);
    return node;
}
