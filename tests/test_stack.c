#include <check.h>
#include "utility.h"


START_TEST(test_new_element)
{
    stack_element *stk_elm1;
    stack_element *stk_elm2;

    stk_elm1 = create_stack_element((long int) 37);
    stk_elm2 = create_stack_element((long int) 81);
    ck_assert_int_eq(stk_elm1->number, 37);
    ck_assert_int_eq(stk_elm2->number, 81);

    stk_elm1->next = stk_elm2;
    _ck_assert_ptr(stk_elm1->next, ==, stk_elm2);
    ck_assert_ptr_null(stk_elm2->next);

    free(stk_elm1);
    free(stk_elm2);
}
END_TEST

START_TEST(test_push)
{
    int64_t elms_count = 5;
    stack *stk = malloc(sizeof(stack));
    int64_t stk_elms[elms_count];


    for (int64_t i = 0; i < elms_count; i++) {
        push(stk, i);
        stk_elms[i] = i;
    }

    stack_element *trav = stk->top;
    while (trav != NULL) {
        ck_assert_int_eq(trav->number, stk_elms[elms_count - 1]);
        elms_count--;
        trav = trav->next;
    }
    free_memory(stk);
}
END_TEST

START_TEST(test_pop)
{
    int64_t elms_count = 5;
    stack *stk = malloc(sizeof(stack));
    int64_t stk_elms[elms_count];

    for (int64_t i = 0; i < elms_count; i++) {
        push(stk, i);
        stk_elms[i] = i;
    }

    while (stk->top != NULL) {
        ck_assert_int_eq(pop(stk), stk_elms[elms_count - 1]);
        elms_count--;
    }
    free_memory(stk);

}
END_TEST

Suite * money_suite(void)
{
    Suite *s;
    TCase *tc_core;
    TCase *tc_push;
    TCase *tc_pop;

    s = suite_create("Stack");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_new_element);
    suite_add_tcase(s, tc_core);

    tc_push = tcase_create("Push");

    tcase_add_test(tc_push, test_push);
    suite_add_tcase(s, tc_push);

    tc_pop = tcase_create("Pop");
    tcase_add_test(tc_push, test_pop);
    suite_add_tcase(s, tc_pop);

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
