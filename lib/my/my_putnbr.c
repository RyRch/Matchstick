/*
** EPITECH PROJECT, 2019
** CPOOL
** File description:
** DAY03
*/

#include "my.h"

int my_putnbr(int nb)
{
    if (nb >= 10) {
        my_putnbr(nb / 10);
        my_putchar(nb % 10 + 48);
    }
    if (nb >= 0 && nb < 10)
        my_putchar(nb + 48);
    if (nb < 0) {
        my_putchar('-');
        my_putnbr(-nb);
    }
    return (0);
}
