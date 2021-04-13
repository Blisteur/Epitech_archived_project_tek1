/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** rush2 Nathan Thomas
*/
#include <unistd.h>

void my_putchar(char c);
int my_put_nbr(int n);
int my_strlen(const char *str);
int my_putstr(const char *str);
void prinLang(char **argv);

void my_put_error(char *c)
{
    int max = my_strlen(c);

    for (int i = 0; i < max; i++) {
        write(2, &c[i], 1);
    }
}

void print_res(char c, int count_c, int percent)
{
    int nb_beg = 0;
    int nb_end = 0;

    nb_beg = percent / 100;
    nb_end = percent % 100;
    my_putchar(c);
    my_putchar(':');
    my_put_nbr(count_c);
    my_putchar(' ');
    my_putchar('(');
    my_put_nbr(nb_beg);
    my_putchar('.');
    my_put_nbr(nb_end);
    if (nb_end == 0)
        my_putchar('0');
    my_putchar('%');
    my_putchar(')');
}

int argument_size(char *tab)
{
    int max = 0;

    for (int i = 0; tab[i] != '\0'; i++) {
        if (tab[i] >= 'a' && tab[i] <= 'z')
            max++;
        if (tab[i] >= 'A' && tab[i] <= 'Z')
            max++;
    }
    return (max);
}

int count_c(char **argv, char c, int lang)
{
    int count_c = 0;
    int percent = 0;

    for (int count = 0; argv[1][count] != '\0'; ++count) {
        if (argv[1][count] == c
            || (argv[1][count] == (c + 32)
                && (c + 32) >= 'a' && (c + 32) <= 'z')
            || (argv[1][count] == (c - 32)
                && (c - 32) >= 'A' && (c - 32) <= 'Z'))
            count_c++;
    }
    percent = (count_c * 10000) / argument_size(argv[1]);
    if (lang == 1)
        return percent;
    print_res(c, count_c, percent);
}

int main(int argc, char **argv)
{
    if (argc < 3 || argv[1][0] == '\0' || argv[1][0] < 'A'
        || argv[1][0] > 'z' || (argv[1][0] < 'a' && argv[1][0] > 'Z')) {
        my_put_error("/!\\ Error, Argument Missing, ");
        my_put_error("correct syntax : ./rush2 \"text\" \'char\' \n");
        return (84);
    }
    for (int i = 2; i < argc; i++) {
        if (argv[i][0] < 'A' || argv[i][0] > 'z' ||
            (argv[i][0] < 'a' && argv[i][0] > 'Z')) {
            my_put_error("/!\\ Error, Argument Missing, ");
            my_put_error("correct syntax : ./rush2 \"text\" \'char\' \n");
            return (84);
        }
        count_c(argv, argv[i][0], 0);
        my_putchar('\n');
    }
    prinLang(argv);
    my_putchar('\n');
    return (0);
}
