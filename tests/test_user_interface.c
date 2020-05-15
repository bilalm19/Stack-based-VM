#include <check.h>
#include "user_interface.c"

START_TEST(test_get_user_input)
{
    freopen("../tests/fake_input.txt", "r", stdin);
    char str[BUFFER] = "";
    
    ck_assert_int_eq(get_user_input(str), 0);
    ck_assert_str_eq(str, "error");

    ck_assert_int_eq(get_user_input(str), 1);
    ck_assert_str_eq(str, "40");

    ck_assert_int_eq(get_user_input(str), 0);
    ck_assert_str_eq(str, "error");

    ck_assert_int_eq(get_user_input(str), 0);
    ck_assert_str_eq(str, "error");
 
    ck_assert_int_eq(get_user_input(str), 0);
    ck_assert_str_eq(str, "error");
}
END_TEST

START_TEST(test_user_interface)
{
    freopen("../tests/fake_user.txt", "r", stdin);
    interface();
}
END_TEST
Suite * interface_suite(void)
{
    Suite *s = suite_create("User Interface");
    TCase *tc_chain = tcase_create("userinterface");

    suite_add_tcase(s, tc_chain);
    tcase_add_test(tc_chain, test_get_user_input);
    tcase_add_test(tc_chain, test_user_interface);

    return s;
}
