#include "test_user_interface.c"
#include "test_stack.c"

int run_tests_for_stack(void)
{
    int number_failed;
    Suite *s = stack_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int run_tests_for_user_interface(void)
{
    int number_failed;
    Suite *s = interface_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

int main(void)
{
    if (run_tests_for_stack())
        return EXIT_FAILURE;

    if (run_tests_for_user_interface())
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
