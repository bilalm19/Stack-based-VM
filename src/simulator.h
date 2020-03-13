/* 
 * A simple machine simulator with a simple language that contains
 * a stack and 7 instructions. Borrowed from a stack overflow 
 * answer.
 */

// TODO:
// user interface to interact with the simulator
// following two instructions depend on interface:
//      -> ifeq function
//      -> jump function
// Will need to create buffer?
// Will have to maintain a list of instruction entered by user

#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct stack stack;
typedef struct stack_element stack_element;

struct stack_element
{
    int64_t            number;
    stack_element      *next;
};

/* 
 * A stack is basically a singly linked list with a pointer pointing
 * at the top most element. 
 */
struct stack {
    stack_element      *top;

};

stack_element *create_stack_element(int64_t numb)
{
    stack_element *new_element = malloc(sizeof(stack_element));
    new_element->number = numb;
    return new_element;
}

void push(stack *stk, int64_t numb)
{
    stack_element *new_element = create_stack_element(numb);
    
    if (stk->top != NULL) 
        new_element->next = stk->top;
    
    stk->top = new_element;
}

int64_t pop(stack *stk)
{
    int64_t save_numb = 0;

    if (stk->top != NULL) {
        stack_element *marked_for_deletion = stk->top; /* Avoid memory leak */
        save_numb = marked_for_deletion->number; /* Save marked's number */

        stk->top = stk->top->next;
        free(marked_for_deletion);    
    }
    
    return save_numb;
}

/*
 * Add and pop top two elements of stack and push the sum.
 */
void add(stack *stk)
{
    if (stk->top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    push(stk, pop(stk) + pop(stk));
}

/*
 * Push a copy of what's at the top of the stack back onto the stack
 */
void dup(stack *stk)
{
    if (stk->top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    push(stk, stk->top->number);    
}

/* 
 * Print starts from top of stack
 */
void print_stack(stack *stk)
{
    stack_element *traverser = stk->top;

    while (traverser != NULL) {
        printf("%lld\n", traverser->number);
        traverser = traverser->next;
    }
}

/*
 * Print the top most element of the stack
 */
void print_top(stack *stk)
{
    if (stk->top == NULL) {
        printf("Stack is empty\n");
        return;
    }

    printf("%lld\n", stk->top->number);
}

#endif /* SIMULATOR_H */
