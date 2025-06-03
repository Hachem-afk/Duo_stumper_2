/*
** EPITECH PROJECT, 2024
** test_my_printf
** File description:
** test the function my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my.h"

int main(int argc, char const *argv[]);
void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(main, simple_string, .init = redirect_all_std)
{
    char *argv[] = {"./text_count", "abcdef"};
    main(2, argv);
    cr_assert_stdout_eq_str("a:1\nb:1\nc:1\nd:1\ne:1\nf:1");
}

Test(main, simple_string, .init = redirect_all_std)
{
    char *argv[] = {"./text_count", "\!\!\!\!\!\!\!\!"};
    main(2, argv);
    cr_assert_stdout_eq_str("!:8");
}

Test(main, double_string, .init = redirect_all_std)
{
    char *argv[] = {"./text_count", "aaffbcdef", "abdfg"};
    main(3, argv);
    cr_assert_stdout_eq_str("a:2\nf:3\nb:1\nd:1\ng:0");
}

Test(main, double_string, .init = redirect_all_std)
{
    char *argv[] = {"./text_count", "ffaabcdef", "aaa"};
    main(3, argv);
    cr_assert_stdout_eq_str("a:2");
}

Test(main, double_string, .init = redirect_all_std)
{
    char *argv[] = {"./text_count", "ffaabcdef", ""};
    main(3, argv);
    cr_assert_stdout_eq_str("");
}

Test(main, double_string, .init = redirect_all_std)
{
    char *argv[] = {"./text_count", "-t", "aaffbcdef", "abdfg"};
    main(4, argv);
    cr_assert_stdout_eq_str("f:3\na:2\nb:1\nd:1\ng:0");
}

Test(main, simple_string, .init = redirect_all_std)
{
    char *argv[] = {"./text_count", "-r", "ffbaacdef"};
    main(3, argv);
    cr_assert_stdout_eq_str("f:3\nb,c,d,e:1\na:2");
}

Test(main, simple_string, .init = redirect_all_std)
{
    char *argv[] = {"./text_count", "-r", "-t", "aaffbcdef"};
    main(4, argv);
    cr_assert_stdout_eq_str("f:3\na:3\nb,c,d,e:1");
}
