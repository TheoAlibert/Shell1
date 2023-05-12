/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** function that handle flag c
*/
#include "my.h"

int flag_c(flag_t flag, va_list list_args)
{
    int nb = 1;
    nb += (my_strstr(flag.flag, "-") == NULL) ? justification(flag, nb) : 0;
    my_putchar(va_arg(list_args, int));
    nb += (my_strstr(flag.flag, "-") != NULL) ? justification(flag, nb) : 0;
    return nb;
}
