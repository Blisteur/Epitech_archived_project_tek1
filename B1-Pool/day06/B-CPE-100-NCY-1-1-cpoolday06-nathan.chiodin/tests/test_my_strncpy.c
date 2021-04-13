/*
** EPITECH PROJECT, 2020
** my_strncpy
** File description:
** task04
*/
#include <stdio.h>
#include <criterion/criterion.h>

Test(my_strncpy, copy_five_characters_in_empty_array)
{
    char dest [20] = {0};

    my_strncpy(dest, "Hello World", 5);
    cr_assert_str_eq(dest, "Hello");
    my_strncpy(dest, "Hello World", 10);
    cr_assert_str_eq(dest, "Hello Worl");
}
