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
int checkfr(char **argv);
int checken(char **argv);
int checkge(char **argv);
int checksp(char **argv);

void database(int nb, int *origin)
{
    int fr[] = {763, 90, 326, 366, 1471, 106, 86, 73, 752, 61, 7, 545, 296, 709
        , 579, 251, 136, 669, 794, 724, 631, 183, 4, 42, 12, 32, 0};
    int en[] = {816, 149, 278, 425, 1270, 222, 201, 609, 696, 15, 77, 402, 240,
        674, 750, 192, 9, 598, 632, 905, 275, 97, 236, 15, 197, 7, 0};
    int sp[] = {1152, 221, 401, 501, 1218, 69, 176, 70, 624, 49, 1, 496, 315,
        671, 868, 251, 87, 687, 797, 463, 292, 113, 1, 21, 100, 46, 0};
    int ge[] = {651, 188, 273, 507, 1639, 165, 300, 457, 655, 26, 141, 343, 253
        , 977, 259, 67, 1, 700, 727, 615, 416, 84, 192, 3, 3, 113, 0};

    for (int i = 0; i < 27; i++) {
    	if (nb == 1)
            origin[i] = fr[i];
    	if (nb == 2)
            origin[i] = en[i];
    	if (nb == 3)
            origin[i] = sp[i];
    	if (nb == 4)
            origin[i] = ge[i];
    }
}

void put_language(int french, int english, int spanish, int german)
{
    if (french > english && french > spanish && french > german) {
        my_putstr("=> French");
        return;
    }
    if (english > french && english > spanish && english > german) {
        my_putstr("=> English");
        return;
    }
    if (spanish > french && spanish > english && spanish > german) {
        my_putstr("=> Spanish");
        return;
    }
    if (german > french && german > spanish && german > english) {
        my_putstr("=> German");
        return;
    }
    my_putstr("=> Unknown");
}

void prinLang(char **argv)
{
    int french = checkfr(argv);
    int english = checken(argv);
    int spanish = checksp(argv);
    int german = checkge(argv);

    put_language(french, english, spanish, german);
}
