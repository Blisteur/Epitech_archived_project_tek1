/*
** EPITECH PROJECT, 2020
** my_evil_str
** File description:
** 
*/

char *my_evil_str(char *str)
{
    int count1 = 0;
    int countmax;
    int countmin = 0;
    char temp;

    while (str[count1 + 1] != '\0') {
        count1 ++;
    }
    countmax = count1;
    count1 = count1 / 2;
    while (count1 >= 0) {
        temp = str[countmin];
        str[countmin] = str[countmax];
        str[countmax] = temp;
        count1 --;
        countmax --;
        countmin ++;
    }
    return (str);
}
