#include <check.h>
#include "utility.h"


START_TEST(test_new_element)
{
    stack_element *stk_elm1;
    stack_element *stk_elm2;

    stk_elm1 = create_stack_element(37);
    stk_elm2 = create_stack_element(81);
    ck_assert_int_eq(stk_elm1->number, 37);
    ck_assert_int_eq(stk_elm2->number, 81);

    stk_elm1->next = stk_elm2;
    _ck_assert_ptr(stk_elm1->next, ==, stk_elm2);
    ck_assert_ptr_null(stk_elm2->next);

    free(stk_elm1);
    free(stk_elm2);
}
END_TEST

START_TEST(test_stack_initialization)
{
    stack *stk = initialize_stack();
    ck_assert_ptr_nonnull(stk);
    ck_assert_ptr_null(stk->top);
    ck_assert_uint_eq(stk->element_count, 0);
}
END_TEST

START_TEST(test_push)
{
    int64_t elms_count = 4;
    stack *stk = initialize_stack();
    
    for (int64_t i = 0; i < elms_count; i++)
        push(stk, i);

    ck_assert_uint_eq(stk->element_count, elms_count);
    stack_element *trav = stk->top;
    while (trav != NULL) {
        ck_assert_int_eq(trav->number, --elms_count);
        trav = trav->next;
    }
    free_memory(stk);
}
END_TEST

START_TEST(test_pop)
{
    int64_t elms_count = 4;
    stack *stk = initialize_stack();

    for (int64_t i = 0; i < elms_count; i++)
        push(stk, i);

    while (stk->top != NULL){
        ck_assert_uint_eq(stk->element_count, elms_count);
        ck_assert_int_eq(pop(stk), --elms_count);
    }

    ck_assert_uint_eq(stk->element_count, 0);

    /* Test popping NULL top */
    ck_assert_int_eq(pop(stk), 0);
    ck_assert_uint_eq(stk->element_count, 0);
    free_memory(stk);

}
END_TEST

START_TEST(test_add)
{
    int64_t elms_count = 4;
    stack *stk = initialize_stack();

    /* Test if add function does not crash if stack top is empty */
    add(stk);
    ck_assert_ptr_null(stk->top);
    ck_assert_uint_eq(stk->element_count, 0);

    for (int64_t i = 0; i <= elms_count; i++)
        push(stk, i);

    add(stk);
    ck_assert_int_eq(stk->top->number, elms_count + elms_count - 1);
    ck_assert_uint_eq(stk->element_count, 4);

    int64_t total = 0;
    /* 
     * Notice that there are unnecessary iterations here as well.
     * That is alright because `add` should not misbehave.
     */
    for (int64_t i = 0; i <= elms_count; i++) {
        add(stk);
        total += i;
    }
    
    ck_assert_uint_eq(stk->element_count, 1);
    ck_assert_int_eq(stk->top->number, total);
    free_memory(stk);
}
END_TEST

START_TEST(test_dup)
{
    int64_t numbs[4] = {90, 90, 88, 12};
    stack *stk = initialize_stack();
    dup(stk);

    ck_assert_ptr_null(stk->top);
    ck_assert_uint_eq(stk->element_count, 0);

    push(stk, numbs[0]);
    dup(stk);
    ck_assert_uint_eq(stk->element_count, 2);

    push(stk, numbs[2]);
    push(stk, numbs[3]);

    int64_t elms_count = 3;
    stack_element *trav = stk->top;
    while (trav != NULL) {
        ck_assert_int_eq(trav->number, numbs[elms_count--]);
        trav = trav->next;
    }
    
    ck_assert_uint_eq(stk->element_count, 4);

    free_memory(stk);
}
END_TEST

START_TEST(test_jump)
{
    int64_t elms_count = 7;
    stack *stk = initialize_stack();
    ck_assert_ptr_null(jump(stk, elms_count));

    for (int64_t i = 0; i < elms_count; i++)
        push(stk, i);

    stack_element *line;
    for (int64_t i = 0; i < elms_count + 2; i++) {
        line = jump(stk, i);
        
        if (i < elms_count + 1 && i > 0)
            ck_assert_int_eq(line->number, elms_count - i);
        else
            ck_assert_ptr_null(line);
    }

    free_memory(stk);
}
END_TEST

Suite * money_suite(void)
{
    Suite *s;
    TCase *tc_core;
    TCase *tc_ini_stack;
    TCase *tc_push;
    TCase *tc_pop;
    TCase *tc_add;
    TCase *tc_dup;
    TCase *tc_jump;

    s = suite_create("Stack");

    tc_core = tcase_create("Core");
    tcase_add_test(tc_core, test_new_element);
    suite_add_tcase(s, tc_core);

    tc_ini_stack = tcase_create("Initialization");
    tcase_add_test(tc_ini_stack, test_stack_initialization);
    suite_add_tcase(s, tc_ini_stack);

    tc_push = tcase_create("Push");
    tcase_add_test(tc_push, test_push);
    suite_add_tcase(s, tc_push);

    tc_pop = tcase_create("Pop");
    tcase_add_test(tc_push, test_pop);
    suite_add_tcase(s, tc_pop);

    tc_add = tcase_create("Add");
    tcase_add_test(tc_add, test_add);
    suite_add_tcase(s, tc_add);

    tc_dup = tcase_create("Dup");
    tcase_add_test(tc_dup, test_dup);
    suite_add_tcase(s, tc_dup);

    tc_jump = tcase_create("Jump");
    tcase_add_test(tc_jump, test_jump);
    suite_add_tcase(s, tc_jump);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = money_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
