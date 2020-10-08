/*
** EPITECH PROJECT, 2019
** intdup
** File description:
** intdup
*/

#include "my.h"

int *my_intdup(int *src, int len)
{
    int *dup = malloc(sizeof(int) * len);

    for (int i = 0; i < len; i++)
        dup[i] = src[i];
    return (dup);
}
