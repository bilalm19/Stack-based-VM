/*
 * Test VM simulator
 */

#include "simulator.c"

#define ARRAY_SIZE 5

int test_failed()
{
    return 1;
}

int test_push()
{
    stack *my_stack = malloc(sizeof(stack));
    const int64_t numbs[ARRAY_SIZE] = {81, 15, -97, 1000, 59010};

    for (int i = 0; i < ARRAY_SIZE; i++)
        push(my_stack, numbs[i]);

    stack_element *traverser = my_stack->top;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (traverser->number != numbs[i]) {
            return test_failed();
        }
    }
}

int main()
{
    stack *my_stack = malloc(sizeof(stack));

    printf("Test started\n");
    printf("-----------------\n");

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