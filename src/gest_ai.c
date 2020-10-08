/*
** EPITECH PROJECT, 2020
** gest_ai
** File description:
** gest_ai
*/

#include "my.h"

int *gen_val(basic *all)
{
    int *val = malloc(sizeof(int) * 1);

    while (1) {
        val[0] = random() %((all->rows)+1);
        if (check_empty(all, val[0]) == false)
            break;
    }
    while (2) {
        val[1] = random() %(all->rows*2-1);
        if (val[1] <= nb_stick(all, val[0])
            && val[1] != 0 && val[1] <= all->max)
            break;
    }
    return (val);
}

void ai(basic *all)
{
    int *val = my_intdup(gen_val(all), 2);

    my_putstr("\nAI's turn...");
    my_putstr("\nAI removed ");
    my_putnbr(val[1]);
    my_putstr(" match(es) from line ");
    my_putnbr(val[0]);
    my_putchar('\n');
    remove_stick(all, val[0], val[1]);
    if (win_check(all) == true) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        all->win = 1;
        return;
    }
    my_putstr("\nYour turn: \n");
}
