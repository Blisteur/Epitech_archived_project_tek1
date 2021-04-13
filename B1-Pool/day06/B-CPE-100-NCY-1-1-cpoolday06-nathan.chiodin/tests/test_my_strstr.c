/*
** EPITECH PROJECT, 2020
** test_my_strstr
** File description:
** task11
*/
#include <stdio.h>
#include <criterion/criterion.h>

char *my_strstr(char const *, char const *);

Test(my_strstr, test_my_strstr)
{
    char dest [100] = "je suis un test pour un admin";

    cr_assert_str_eq(my_strstr(dest, "test"), "test pour un admin");
    cr_assert_null(my_strstr(dest, "lol"));
}
