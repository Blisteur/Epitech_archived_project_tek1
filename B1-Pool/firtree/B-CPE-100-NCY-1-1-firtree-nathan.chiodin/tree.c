/*
** EPITECH PROJECT, 2020
** tree
** File description:
** fir tree
*/

void char_tree(int char_space, int char_star)
{
    while (char_space != 0) {
        my_putchar(' ');
        char_space --;
    }
    while (char_star != 0) {
        my_putchar('*');
        char_star --;
    }
}

int between_size(int tree_count, int *space, int *star, int temp)
{
    int how_many_space = 2;
    int how_many_star = 4;

    for (int count_st = 0; count_st < tree_count; count_st ++) {
        temp ++;
        if (temp == 2) {
            how_many_star += 2;
            temp = 0;
        }
    }
    *star = *star - how_many_star;
    temp = 0;
    for (int count_sp = 0; count_sp < tree_count; count_sp ++) {
        temp ++;
        if (temp == 2) {
            how_many_space ++;
            temp = 0;
        }
    }
    *space = *space + how_many_space;
}

int space_count(int size)
{
    int nb = 6;
    int increment = 4;
    int temp = 0;

    if (size == 1)
        return (3);
    for (int nb_count = 0; nb_count < (size - 2); nb_count ++) {
        nb = nb + increment;
        temp ++;
        if (temp == 2) {
            increment ++;
            temp = 0;
        }
    }
    return (nb);
}

void trunk(int size)
{
    int temp;
    int h_m_space = space_count(size);

    temp = size / 2;
    temp = temp * 2;
    temp += 1;
    for (int  line_trunk = 0; line_trunk != size; line_trunk ++) {
        for (int space = 0; space != (h_m_space - (size / 2)); space ++)
            my_putchar(' ');
        for (int column = 0; column != temp; column ++)
            my_putchar('|');
        my_putchar('\n');
    }
}

void tree(int size)
{
    int space = space_count(size);
    int star = 1;
    int line = 4;
    int count_temp = 0;

    if (size <= 0)
        return;
    for (int tree_count = 0; tree_count < size; tree_count ++) {
        for (int count = 0; count < line; count ++) {
            char_tree(space, star);
            space --;
            star = star + 2;
            my_putchar('\n');
        }
        line ++;
        between_size(tree_count, &space, &star, count_temp);
    }
    trunk(size);
}
