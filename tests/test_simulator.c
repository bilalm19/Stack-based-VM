/*
 * Test VM simulator
 */

#include "simulator.h"

#define RESET "\033[0m"
#define RED   "\033[31m"
#define GREEN "\033[32m" 

#define ARRAY_SIZE 5

const int64_t numbs[ARRAY_SIZE] = {81, 15, -97, 1000, 59010};

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

int test_push(stack *stk)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
        push(stk, numbs[i]);

    int test_status = 0;
    stack_element *traverser = stk->top;
    for (int i = ARRAY_SIZE-1; i > -1; i--) {
        if (traverser->number != numbs[i]) {
            test_status = 1;
            break;
        }
        traverser = traverser->next;
    }
    return test_status;
}

int test_pop(stack *stk)
{
    stack_element *temp = stk->top;

    int test_status = 0;
    int max_pop_index = ARRAY_SIZE-3;
    for (int i = ARRAY_SIZE-1; i > max_pop_index; i--)
        if (pop(stk) != numbs[i]) {
            test_status = 1;
            break;
        }

    stack_element *traverser = stk->top;
    for (int i = max_pop_index; i > -1; i--) {
        if (traverser->number != numbs[i]) {
            test_status = 1;
            break;
        }
        traverser = traverser->next;
    }

    return test_status;
}

int main()
{
    stack *stk = malloc(sizeof(stack));
    printf("Test started\n");
    printf("-----------------\n");

    if (test_push(stk) == 1) {
        printf(RED "Push test failed!\n" RESET);
        free_memory(stk);
        return 1;
    } else {
        printf(GREEN "Push test successful\n" RESET);
    }

    if (test_pop(stk) == 1) {
        printf(RED "Pop test failed!\n" RESET);
        free_memory(stk);
        return 1;
    } else {
        printf(GREEN "Push test successful\n" RESET);
    }

    

    // dup(stk);

    // push(stk, (int64_t)81);
    // push(stk, (int64_t)15);
    // push(stk, (int64_t)-97);
    // push(stk, (int64_t)1000);
    // push(stk, (int64_t)59010);

    // dup(stk);
    // print_stack(stk);

    // for (int i = 0; i < 6; i++) {
    //     add(stk);
    //     printf("\n");
    //     print_stack(stk);
    // }

    // printf("\n");
    // dup(stk);
    // print_stack(stk);

    free_memory(stk);
}