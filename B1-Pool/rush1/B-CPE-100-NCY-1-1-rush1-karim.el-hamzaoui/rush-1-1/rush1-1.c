/*
** EPITECH PROJECT, 2019
** rush1-1
** File description:
** rush1-1
*/

#include <unistd.h>

void line(int a, int x)
{
    if (a == 0 || a == x -1)
        my_putchar('o');
    else
        my_putchar('-');
}

void column(int a , int x)
{
    if (a == 0 || a == x - 1)
        my_putchar('|');
    else
        my_putchar(' ');
}

void rush(int x, int y)
{
    if ( x < 0 || y < 0)
        write(2, "Invalid size\n", 13);
    else {
        for (int count_l = 0; count_l < y; count_l++){
            for (int count_c = 0; count_c < x; count_c++) {
                if (x == 1 || y == 1)
                    my_putchar('o');
                if (count_l == 0 || count_l == x -1)
                    line(count_c , x);
                else
                    column(count_c, x);
            }
            my_putchar('\n');
        }
    }
}