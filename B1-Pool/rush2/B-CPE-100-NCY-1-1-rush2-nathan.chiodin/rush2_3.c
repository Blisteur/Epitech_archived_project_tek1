/*
** EPITECH PROJECT, 2020
** rush2
** File description:
** rush2 Nathan Thomas
*/

void my_putchar(char c);
int my_put_nbr(int n);
int my_strlen(const char *str);
int my_putstr(const char *str);
int database(int nb, int *origin);
int count_c(char **argv, char c, int lang);

int setupLangVariable(int *fr, int *en, int *ge, int *sp)
{
    database(1, fr);
    database(2, en);
    database(3, ge);
    database(4, sp);
}

int checkfr(char **argv)
{
    int french = 0;
    int percent = 0;
    int casing = 0;
    int fr[27];
    int en[27];
    int ge[27];
    int sp[27];

    setupLangVariable(fr, en, ge, sp);
    for (int c = 0; c < 26; c++) {
        percent = count_c(argv, c + 'a', 1);
        if (percent >= fr[c])
            if (fr[c] > en[c] && fr[c] > sp[c] && fr[c] > ge[c])
                french += 3;
            else
                french += 1;
    }
    return french;
}

int checken(char **argv)
{
    int english = 0;
    int percent = 0;
    int casing = 0;
    int fr[27];
    int en[27];
    int ge[27];
    int sp[27];

    setupLangVariable(fr, en, ge, sp);
    for (int c = 0; c < 26; c++) {
        percent = count_c(argv, c + 'a', 1);
        if (percent >= en[c])
            if (en[c] > fr[c] && en[c] > sp[c] && en[c] > ge[c])
                english += 3;
            else
                english += 1;
    }
    return english;
}

int checkge(char **argv)
{
    int german = 0;
    int percent = 0;
    int casing = 0;
    int fr[27];
    int en[27];
    int ge[27];
    int sp[27];

    setupLangVariable(fr, en, ge, sp);
    for (int c = 0; c < 26; c++) {
        percent = count_c(argv, c + 'a', 1);
        if (percent >= ge[c])
            if (ge[c] > en[c] && ge[c] > sp[c] && ge[c] > fr[c])
                german += 3;
            else
                german += 1;
    }
    return german;
}

int checksp(char **argv)
{
    int spanish = 0;
    int percent = 0;
    int casing = 0;
    int fr[27];
    int en[27];
    int ge[27];
    int sp[27];

    setupLangVariable(fr, en, ge, sp);
    for (int c = 0; c < 26; c++) {
        percent = count_c(argv, c + 'a', 1);
        if (percent >= sp[c])
            if (sp[c] > en[c] && sp[c] > fr[c] && sp[c] > ge[c])
                spanish += 3;
            else
                spanish += 1;
    }
    return spanish;
}
