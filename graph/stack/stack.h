#ifndef GRANDELIA_STACK_H
#define GRANDELIA_STACK_H

#include "../graph.h"

typedef struct Stack {
    struct StackNode * top;
} Stack;

struct StackNode {
    struct Node * node;
    struct StackNode * next;
};

Stack * createStack();

void deleteStack(Stack * stack);

void push(struct Stack * stack, struct Node * node);

struct Node * pop(struct Stack * stack);

#endif //GRANDELIA_STACK_H
