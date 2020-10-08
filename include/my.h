/*
** EPITECH PROJECT, 2019
** include
** File description:
** my.h
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "struct.h"

void my_putchar(char c);

int my_putstr(char const *str);

int my_getnbr(char const *str);

int *my_intdup(int *src, int len);

int my_putnbr(int nb);

char *my_strcpy(char *dest, char const *src);

char *my_strdup(char const *src);

int my_strlen(char const *str);

void malloc_map(basic *all, char **av);

void fill_mcage(basic *all, char **av);

void fill_mstick(basic *all, char **av);

void print_map(basic *all);

cases recup_line(basic *all);

int game_loop(basic *all, char **av);

void ai(basic *all);

cases recup_match(basic *all);

cases remove_stick(basic *all, int line, int match);

cases isnot(char *str);

cases check_line(basic *all);

cases check_match(basic *all);

int count_stick(basic *all);

cases check_empty(basic *all, int line);

int nb_stick(basic *all, int line);

cases win_check(basic *all);

int *gen_val(basic *all);

void print_rm(basic *all);

cases gest_match(basic *all);
