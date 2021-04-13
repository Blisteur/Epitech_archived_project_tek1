/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** task03
*/
#include <stdio.h>
#include <criterion/criterion.h>

Test(my_revstr, reverse)
{
    char dest [20] = "Hello World";

    my_revstr(dest);
    cr_assert_str_eq(dest, "dlroW olleH");
}
