/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** function that handle flag b, o, u, x, X
*/
#include "my.h"

int flag_base(flag_t flag, va_list list_args)
{
    unsigned int d = va_arg(list_args, unsigned int);
    int nb = 0; char converted[33]; converted[32] = '\0';
    if (my_strstr(flag.flag, "+") != NULL && d >= 0) {
        my_putchar('+'); nb++;
    } else if (my_strstr(flag.flag, " ") != NULL && d >= 0) {
        my_putchar(' '); nb++;
    }
    my_convert_base(d, converted, flag.specifier);
    clear_padding_0(converted);
    nb += my_strlen(converted);
    nb += (my_strstr(flag.flag, "-") == NULL) ? justification(flag, nb) : 0;
    my_putstr(converted);
    nb += (my_strstr(flag.flag, "-") != NULL) ? justification(flag, nb) : 0;
    return nb;
}
