/*
** EPITECH PROJECT, 2019
** rush1-5
** File description:
** 
*/

#include <unistd.h>

void line_d(int a, int x)
{
    if (a == 0)
        my_putchar('A');
    else if (a == x - 1)
        my_putchar('C');
    else
        my_putchar('B');
}

void line_f(int a, int x)
{   
    if (a == 0)
        my_putchar('C');
    else if (a == x - 1)
        my_putchar('A');
    else
        my_putchar('B');
    
}

void column(int a, int x)
{
    if (a == 0 || a == x - 1)
        my_putchar('B');
    else
        my_putchar(' ');
}

void rush(int x, int y)
{
    if (x <= 0 || y <= 0)
        write(2, "Invalid size\n", 13);
    else {
        for (int count_l = 0; count_l < y; count_l++) { 
            for (int count_c = 0; count_c < x; count_c++) {
                if (x == 1 || y == 1)
                    my_putchar('B');
                else {
                    if (count_l == 0)
                        line_d(count_c, x);
                    else if (count_l == y - 1)
                        line_f(count_c, x);
                    else
                        column(count_c, x);
                }
            }
            my_putchar('\n');
        }
    }
}
