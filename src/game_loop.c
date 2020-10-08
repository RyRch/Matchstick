/*
** EPITECH PROJECT, 2020
** game_loop
** File description:
** game_loop
*/

#include "my.h"

int game_loop(basic *all, char **av)
{
    fill_mstick(all, av);
    print_map(all);
    my_putstr("\nYour turn: \n");
    while (all->win == 0) {
        if (recup_line(all) == true) {
            if (recup_match(all) == true)
                ai(all);
        } else
            break;
    }
    return (all->win);
}

cases recup_line(basic *all)
{
    if (all->stop == 0)
        my_putstr("Line: ");
    if (getline(&all->ptr, &all->rd, stdin) == -1)
        return (false);
    all->line = my_strdup(all->ptr);
    if (all->line == NULL)
        return (false);
    if (check_line(all) == false)
        recup_line(all);
    else
        return (true);
}

void print_rm(basic *all)
{
    my_putstr("Player removed ");
    my_putnbr(my_getnbr(all->match));
    my_putstr(" match(es) from line ");
    my_putnbr(my_getnbr(all->line));
    my_putchar('\n');
    remove_stick(all, my_getnbr(all->line), my_getnbr(all->match));
}

cases recup_match(basic *all)
{
    all->stop = 1;
    my_putstr("Matches: ");
    if (getline(&all->ptr, &all->rd, stdin) == -1)
        return (false);
    all->match = my_strdup(all->ptr);
    if (all->match == NULL)
        return (false);
    if (gest_match(all) == false)
        recup_match(all);
    else {
        print_rm(all);
        if (win_check(all) == true) {
            my_putstr("You lost, too bad...\n");
            all->win = 2;
            return (false);
        }
        all->stop = 0;
        return (true);
    }
}

cases remove_stick(basic *all, int line, int match)
{
    int check = -1;

    for (int x = (all->rows*2+1); x > 0; x--) {
        if (all->map[line][x] == '|')
            check++;
        if (check < match
            && all->map[line][x] == '|')
            all->map[line][x] = ' ';
    }
    print_map(all);
}
