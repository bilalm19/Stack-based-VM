/*
 * Test VM simulator
 */

#include "simulator.c"



int main()
{
    stack *my_stack = malloc(sizeof(stack));

    printf("Simulator started\n");
    printf("-----------------\n");

    dup(my_stack);

    push(my_stack, (int64_t)81);
    push(my_stack, (int64_t)15);
    push(my_stack, (int64_t)-97);
    push(my_stack, (int64_t)1000);
    push(my_stack, (int64_t)59010);

    dup(my_stack);
    print_stack(my_stack);

    for (int i = 0; i < 6; i++) {
        add(my_stack);
        printf("\n");
        print_stack(my_stack);
    }

    printf("\n");
    dup(my_stack);
    print_stack(my_stack);
}