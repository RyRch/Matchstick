/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** my_strlen
*/

#include "my.h"

int my_strlen(char const *str)
{
    int len = 0;

    for ( ; str[len] != '\0'; len++);
    return (len);
}
