/*
** EPITECH PROJECT, 2019
** CPOOL
** File description:
** DAY04
*/

#include "my.h"

int my_getnbr(char const *str)
{
    int min = -2147483647;
    int y = 0;
    int i = 0;
    int t = 0;
    int x = 1;

    while (str[i] != '\0' && str[i] == 45 || str[i] == 43) {
        if (str[i] == 45)
            x = -x;
        i++;
    }
    for ( ;str[i] >= 48 && str[i] <= 57; i++) {
        y = y * 10;
        y = y + str[i] - 48;
        if (y < 0 && (y < min || x == 1))
            return (0);
    }
    return (y * x);
}
