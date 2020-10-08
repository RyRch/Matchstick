/*
** EPITECH PROJECT, 2020
** map
** File description:
** map
*/

#include "my.h"

void malloc_map(basic *all, char **av)
{
    all->rows = my_getnbr(av[1]);
    all->max = my_getnbr(av[2]);
    all->map = malloc(sizeof(char *) * (all->rows+2));
    for (int y = 0; y < (all->rows+2); y++) {
        all->map[y] = malloc(sizeof(char) * (all->rows*2+2));
        all->map[y][all->rows*2+1] = '\0';
    }
}

void fill_mcage(basic *all, char **av)
{
    malloc_map(all, av);
    all->size = (all->rows*2+1);
    all->half = all->size/2;
    for (int y = 0; y < (all->rows+2); y++) {
        for (int x = 0; x < all->size; x++) {
            all->map[y][x] = ' ';
            if (y == 0 || x == 0
                || y+1 == (all->rows+2)
                || x+1 == all->size)
                all->map[y][x] = '*';
            if (all->map[y][x] == ' ' && x == all->half)
                all->map[y][x] = '|';
        }
    }
}

void fill_mstick(basic *all, char **av)
{
    int count = 0;

    fill_mcage(all, av);
    count = all->half-1;
    for (int y = 2; y < (all->rows+2); y++) {
        for (int x = 0+count; x < all->half; x++) {
            if (all->map[y][x] == ' ')
                all->map[y][x] = '|';
        }
        for (int w = (all->size-1)-count; w != all->half; w--) {
            if (all->map[y][w] == ' ')
                all->map[y][w] = '|';
        }
        count--;
    }
}

void print_map(basic *all)
{
    for (int y = 0; y < (all->rows+2); y++) {
        my_putstr(all->map[y]);
        my_putchar('\n');
    }
}

cases isnot(char *str)
{
    for (int i = 0; str[i] != '\n'; i++) {
        if (str[i] < '0' || str[i] > '9' || str[0] == '-')
            return (false);
    }
    return (true);
}
