/*
** EPITECH PROJECT, 2020
** gest_err
** File description:
** gest_err
*/

#include "my.h"

cases check_line(basic *all)
{
    int value = my_getnbr(all->line);

    if (value > all->rows || value == 0) {
        my_putstr("Error: this line is out of range\n");
        return (false);
    } else if (isnot(all->line) == false) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (false);
    } else if (value > 0 && value <= all->rows)
        return (true);
}

cases check_match(basic *all)
{
    int value = my_getnbr(all->match);

    if (value > all->max) {
        my_putstr("Error: you cannot remove more than ");
        my_putnbr(all->max);
        my_putstr(" matches per turn\n");
        return (false);
    }
    if (value == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (false);
    }
    return (true);
}

cases gest_match(basic *all)
{
    int value = my_getnbr(all->match);

    if (check_match(all) == false)
        return (false);
    if (check_empty(all, my_getnbr(all->line)) == true) {
        my_putstr("Error: not enough matches on this line\n");
        all->stop = 0;
        recup_line(all);
        return (false);
    }
    if (isnot(all->match) == false) {
        my_putstr("Error: invalid input (positive number expected)\n");
        return (false);
    }
    if (value > count_stick(all)) {
        my_putstr("Error: not enough matches on this line\n");
        return (false);
    }
    return (true);
}

int count_stick(basic *all)
{
    int stick = 0;
    int line = my_getnbr(all->line);

    for (int x = 0; x < (all->rows*2+1); x++) {
        if (all->map[line][x] == '|')
            stick++;
    }
    return (stick);
}
