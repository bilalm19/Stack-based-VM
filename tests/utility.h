#ifndef UTILITY_H
#define UTILITY_H

#include "../src/stack.h"

/*
 * Utility function which will free up the memory taken by stack.
 * The pop function in stack can replace this, but that function
 * can be assumed to be unstable relative to this.
 */
void free_memory(stack *stk)
{
    stack_element *traverser;
    
    while (stk->top) {
        traverser = stk->top;
        stk->top = stk->top->next;
        free(traverser);
    }
    
    free(stk);
}

#endif /* UTILITY_H */