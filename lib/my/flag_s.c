/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** function that handle flag s & S
*/
#include "my.h"

static char * dec_oct(char d, char * o)
{
    int pow = 2; int ret = 0; int i = 0;
    while (pow >= 0) {
        if (my_compute_power_rec(8, pow) * (ret + 1) <= d) {
            ret++; continue;
        }
        o[i] = '0' + ret; i++;
        d -= my_compute_power_rec(8, pow) * ret; ret = 0; pow--;
    }
    return o;
}

int flag_s(flag_t flag, va_list list_args)
{
    char * str = va_arg(list_args, char *); int len = my_strlen(str);
    int nb = 0; char o[4]; o[3] = '\0'; char c;
    int prec = flag.precision; char spe = flag.specifier;
    for (int i = 0; i < len && (i < prec || prec < 0); i++) {
        nb += ((str[i] < 32 || str[i] >= 127) && spe == 'S') ? 4 : 1;
    }
    nb += (my_strstr(flag.flag, "-") == NULL) ? justification(flag, nb) : 0;
    for (int i = 0; i < len && (i < prec || prec < 0); i++) {
        c = ((*str < 32 || *str >= 127) && spe == 'S') ? '\\' : *str;
        my_putchar(c); dec_oct(*str, o);
        ((*str < 32 || *str >= 127) && spe == 'S') ? my_putstr(o) : 0;
        str++;
    }
    nb += (my_strstr(flag.flag, "-") != NULL) ? justification(flag, nb) : 0;
    return nb;
}
