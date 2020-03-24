#include <check.h>
#include "../src/stack.h"

START_TEST(test_new_element)
{
    stack_element *stk_elm1;
    stack_element *stk_elm2;

    stk_elm1 = create_stack_element(37);
    stk_elm2 = create_stack_element(81);
    ck_assert_uint_eq(stk_elm1->number, 37);
    ck_assert_uint_eq(stk_elm2->number, 81);

    stk_elm1->next = stk_elm2;
    _ck_assert_ptr(stk_elm1->next, ==, stk_elm2);
    ck_assert_ptr_null(stk_elm2->next);

    free(stk_elm1);
    free(stk_elm2);
}
END_TEST

START_TEST(test_push)
{
    stack *stk = malloc(sizeof(stack));

}
END_TEST

Suite * money_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Stack");

    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_new_element);
    suite_add_tcase(s, tc_core);

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
