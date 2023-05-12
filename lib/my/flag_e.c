/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** function that handle flag e & E
*/
#include "my.h"

int flag_e(flag_t flag, va_list list_args)
{
    double d = va_arg(list_args, double);
    int nb = 0;
    if (my_strstr(flag.flag, "+") != NULL && d >= 0) {
        my_putchar('+'); nb++;
    } else if (my_strstr(flag.flag, " ") != NULL && d >= 0) {
        my_putchar(' '); nb++;
    }
    nb += my_scilen(d, flag.precision);
    nb += (my_strstr(flag.flag, "-") == NULL) ? justification(flag, nb) : 0;
    my_putsci(d, flag.precision, flag.specifier);
    nb += (my_strstr(flag.flag, "-") != NULL) ? justification(flag, nb) : 0;
    return nb;
}
