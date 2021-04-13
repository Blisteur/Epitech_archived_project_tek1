/*
** EPITECH PROJECT, 2020
** test_my_strncmp
** File description:
** task11
*/
#include <stdio.h>
#include <criterion/criterion.h>

char *my_strcapitalize( char *str);

Test(my_strcapitalize, test_my_strcapitalize1)
{
    char first[100] = "je suis un test";

    cr_assert_str_eq(my_strcapitalize(first), "Je Suis Un Test");
}

Test(my_strcapitalize, test_my_strcapitalize2)
{
    char second[100] = "je suis un TEST";

    cr_assert_str_eq(my_strcapitalize(second), "Je Suis Un Test");
}

Test(my_strcapitalize, test_my_strcapitalize3)
{
    char third[100] = "juste 42un teSt";

    cr_assert_str_eq(my_strcapitalize(third), "Juste 42un Test");
}
