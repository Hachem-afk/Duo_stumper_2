#include <criterion/criterion.h>
#include <criterion/internal/test.h>
#include <criterion/redirect.h>
#include "my.h"

Test(error_handling, correct_no_str)
{
    int argc = 3;
    const char *argv[3];
    argv[0] = "./crocus";
    argv[1] = "-n";
    argv[2] = "0123456789";
    int res = error_handling(argc, argv);

    cr_assert_eq(res, 0);
}

Test(error_handling, correct_with_str)
{
    int argc = 5;
    const char *argv[5];
    argv[0] = "./crocus";
    argv[1] = "-s";
    argv[2] = "astek";
    argv[3] = "-n";
    argv[4] = "0453";
    int res = error_handling(argc, argv);

    cr_assert_eq(res, 0);
}
