#include "../src/stack.h"

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