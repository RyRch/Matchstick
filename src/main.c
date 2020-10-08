/*
** EPITECH PROJECT, 2020
** main
** File description:
** main
*/

#include "my.h"

void fill_struct(basic *all)
{
    all->map = NULL;
    all->ptr = NULL;
    all->line = malloc(sizeof(char) * 1000000);
    all->match = malloc(sizeof(char) * 1000000);
    all->max = 0;
    all->rows = 0;
    all->half = 0;
    all->size = 0;
    all->rd = 0;
    all->sd = 0;
    all->win = 0;
    all->stop = 0;
}

cases check_empty(basic *all, int line)
{
    for (int x = 0; all->map[line][x] != '\0'; x++) {
        if (all->map[line][x] == '|')
            return (false);
    }
    return (true);
}

int nb_stick(basic *all, int line)
{
    int nb = 0;

    for (int x = 0; all->map[line][x] != '\0'; x++) {
        if (all->map[line][x] == '|')
            nb++;
    }
    return (nb);
}

cases win_check(basic *all)
{
    for (int y = 0; y < all->rows+2; y++) {
        if (check_empty(all, y) == false)
            return (false);
    }
    return (true);
}

int main(int ac, char **av)
{
    basic all;
    int res = 0;

    if (ac != 3)
        return (84);
    fill_struct(&all);
    res = game_loop(&all, av);
    return (res);
}
