/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** display a float in scientific notation
** in fact only display the float part of the notation
** return the exposant
*/
#include "my.h"

int my_scilen(double nb, int prec)
{
    int len = 0;
    if (nb < 0) {
        nb *= -1; len++;
    }
    int e = 0;
    while (nb >= 10) {
        nb /= 10;
        e++;
    }
    len += float_len(nb, prec);
    if (my_nbrlen(e) < 2) {
        len++;
    }
    len += my_nbrlen(e) + 2;
    return len;
}

// default precsion : 6
int my_putsci(double nb, int prec, char opt)
{
    int len = 0;
    if (nb < 0) {
        my_putchar('-');
        nb *= -1; len++;
    }
    int e = 0;
    while (nb >= 10) {
        nb /= 10;
        e++;
    }
    len += my_putfloat_prec(nb, prec);
    my_putchar(opt); my_putchar('+');
    if (my_nbrlen(e) < 2) {
        my_putchar('0'); len++;
    }
    my_put_nbr(e); len = my_nbrlen(e) + 2;
    return len;
}
