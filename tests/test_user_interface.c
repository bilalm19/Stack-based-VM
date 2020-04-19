#include <check.h>
#include "../src/user_interface.c"

START_TEST(test_get_user_input)
{
    ck_assert_int_eq(0, 1);
}
END_TEST

Suite * interface_suite(void)
{
    Suite *s = suite_create("User Interface");
    TCase *tc_chain = tcase_create("userinterface");

    suite_add_tcase(s, tc_chain);
    tcase_add_test(tc_chain, test_get_user_input);

    return s;
}
