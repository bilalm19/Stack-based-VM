/*
 * Test VM simulator
 */

#include "simulator.c"

#define RESET "\033[0m"
#define RED   "\033[31m"
#define GREEN "\033[32m" 

#define ARRAY_SIZE 5

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

int test_push()
{
    stack *my_stack = malloc(sizeof(stack));
    const int64_t numbs[ARRAY_SIZE] = {81, 15, -97, 1000, 59010};

    for (int i = 0; i < ARRAY_SIZE; i++)
        push(my_stack, numbs[i]);

    int test_status = 0;
    stack_element *traverser = my_stack->top;
    for (int i = ARRAY_SIZE-1; i > -1; i--) {
        if (traverser->number != numbs[i]) {
            test_status = 1;
            break;
        }
        traverser = traverser->next;
    }

    free_memory(my_stack);
    return test_status;
}

int main()
{
    stack *my_stack = malloc(sizeof(stack));

    printf("Test started\n");
    printf("-----------------\n");

    if (test_push() == 1) {
        printf(RED "Push test failed!\n" RESET);
        return 1;
    } else {
        printf(GREEN "Push test successful\n" RESET );
    }

    // dup(my_stack);

    // push(my_stack, (int64_t)81);
    // push(my_stack, (int64_t)15);
    // push(my_stack, (int64_t)-97);
    // push(my_stack, (int64_t)1000);
    // push(my_stack, (int64_t)59010);

    // dup(my_stack);
    // print_stack(my_stack);

    // for (int i = 0; i < 6; i++) {
    //     add(my_stack);
    //     printf("\n");
    //     print_stack(my_stack);
    // }

    // printf("\n");
    // dup(my_stack);
    // print_stack(my_stack);
}