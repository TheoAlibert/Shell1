/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** function that handle flag f & F
*/
#include "my.h"

int flag_f(flag_t flag, va_list list_args)
{
    double d = va_arg(list_args, double);
    int nb = 0;
    if (my_strstr(flag.flag, "+") != NULL && d >= 0.0) {
        my_putchar('+'); nb++;
    } else if (my_strstr(flag.flag, " ") != NULL && d >= 0.0) {
        my_putchar(' '); nb++;
    }
    nb += float_len(d, flag.precision);
    nb += (my_strstr(flag.flag, "-") == NULL) ? justification(flag, nb) : 0;
    my_putfloat_prec(d, flag.precision);
    nb += (my_strstr(flag.flag, "-") != NULL) ? justification(flag, nb) : 0;
    return nb;
}
