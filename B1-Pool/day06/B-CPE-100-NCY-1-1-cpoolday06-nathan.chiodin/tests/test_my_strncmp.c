/*
** EPITECH PROJECT, 2020
** test_my_strncmp
** File description:
** task11
*/
#include <stdio.h>
#include <criterion/criterion.h>

Test(my_strncmp, test_my_strncmp)
{
    char first[100] = "je suis un test pour un admin";
    char second[100] = "je suis un test pour un bamin";
    char third[100] = "juste un test";

    cr_assert_str_eq(my_strncmp(first, second, 100), -1);
    cr_assert_str_eq(my_strncmp(first, third, 5), 1);
    cr_assert_str_eq(my_strncmp(third, third, 34), 0);
}
