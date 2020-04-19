#include <check.h>
#include "../src/user_interface.c"

START_TEST(test_get_user_input)
{
    freopen("../tests/fake_input.txt", "r", stdin);
    char str[BUFFER] = "";
    
    get_user_input(str);
    ck_assert_str_eq(str, "short input");

    get_user_input(str);
    ck_assert_str_eq(str, "error");

    get_user_input(str);
    ck_assert_str_eq(str, "\"apostrophes\"");
 
    get_user_input(str);
    ck_assert_str_eq(str, "coe+20");
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
