/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** function that handle flag g & G
*/
#include "my.h"

int flag_g(flag_t flag, va_list list_args)
{
    double d = va_arg(list_args, double); int fp = flag.precision;
    int int_d = d; int nb = 0; int d_len = my_nbrlen(int_d);
    int prec = (fp <= d_len) ? fp - d_len : fp;
    int f_len = float_len(d, prec);
    int e_len = my_scilen(d, flag.precision);
    if (my_strstr(flag.flag, "+") != NULL && d >= 0.0) {
        my_putchar('+'); nb++;
    } else if (my_strstr(flag.flag, " ") != NULL && d >= 0.0) {
        my_putchar(' '); nb++;
    } if (e_len < f_len) {
        nb += e_len;
        nb += (my_strstr(flag.flag, "-") == NULL) ? justification(flag, nb) : 0;
        my_putsci(d, flag.precision, flag.specifier - 2);
        nb += (my_strstr(flag.flag, "-") != NULL) ? justification(flag, nb) : 0;
    } else {
        nb += f_len;
        nb += (my_strstr(flag.flag, "-") == NULL) ? justification(flag, nb) : 0;
        my_putfloat_prec(d, prec);
        nb += (my_strstr(flag.flag, "-") != NULL) ? justification(flag, nb) : 0;
    } return nb;
}
