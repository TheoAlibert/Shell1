/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** function that handle flag d & i
*/
#include "my.h"

int flag_i(flag_t flag, va_list list_args)
{
    int d = va_arg(list_args, int);
    int nb = my_nbrlen(d);
    if (my_strstr(flag.flag, "+") != NULL && d >= 0) {
        my_putchar('+');
    } else if (my_strstr(flag.flag, " ") != NULL && d >= 0) {
        my_putchar(' ');
    }
    nb += (my_strstr(flag.flag, "-") == NULL) ? justification(flag, nb) : 0;
    my_put_nbr(d);
    nb += (my_strstr(flag.flag, "-") != NULL) ? justification(flag, nb) : 0;
    return nb;
}
