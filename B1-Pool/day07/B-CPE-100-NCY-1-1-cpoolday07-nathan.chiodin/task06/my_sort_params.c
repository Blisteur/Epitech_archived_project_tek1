/*
** EPITECH PROJECT, 2020
** my_rev_params
** File description:
** task05
*/
#include <unistd.h>

int ascii_num(char *str, int nb)
{
    int code;

    code = str[nb];
    return (code);
}

int main(int argc, char **argv)
{
    int count;

    for (count = 0; count != argc; count++);
    for (int subcount = 0; subcount <= 127; subcount++) {
        for (int subsubcount = 0; subsubcount != count; subsubcount++){
            if (ascii_num(argv[subsubcount], 0) == subcount)
                my_putstr(argv[subsubcount]);
        }
    }
    return (0);
}
