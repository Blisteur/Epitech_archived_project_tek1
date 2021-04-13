/*
** EPITECH PROJECT, 2020
** my_show_word_array
** File description:
** task03
*/

int my_show_word_array(char * const *tab)
{
    for (int count = 0; tab[count] != 0; count++) {
        my_putstr(tab[count]);
        my_putchar('\n');
    }
}
