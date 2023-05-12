/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** display a float with a specified precision
*/
#include "my.h"

double my_round(double nb, int prec)
{
    double rounded_nb = 0.0; double ret;
    int int_nb_temp = nb; rounded_nb += int_nb_temp;
    for (int i = 0; i <= prec; i++) {
        nb -= int_nb_temp; nb *= 10.0;
        int_nb_temp = nb;
        rounded_nb *= 10; rounded_nb += int_nb_temp;
        (i == prec) ? ret = int_nb_temp : 0;
    }
    if (ret > 5.0) {
        rounded_nb += 1.0;
    }
    for (int i = 0; i <= prec; i++) {
        rounded_nb *= 0.1;
    }
    return rounded_nb;
}

static char * round_correction(char * str)
{
    int len = my_strlen(str);
    int last = str[len - 1] - '0'; int ret = 1; int c;
    str[len - 1] = '\0';
    for (int i = len - 2; i >= 0 && last >= 5 && ret; i--) {
        c = str[i] - '0';
        if (c + ret == 10) {
            str[i] = '0'; ret = 1;
        } else {
            str[i] += 1; ret = 0;
        }
    }
    return str;
}

static char * strfloat(double nb, int prec, int * int_nb, char * str)
{
    if (prec < 0) {
        prec = 6;
    }
    nb = my_round(nb, prec); int len = 0;
    if (nb < 0){
        nb *= -1.0;
    }
    *int_nb = nb; *int_nb += (prec == 0 && (nb - *int_nb) >= 0.5) ? 1 : 0;
    int int_nb_temp = nb;
    if (prec > 0) {
        str[len] = '.'; len++;
    }
    for (int i = 0; i <= prec; i++) {
        nb -= int_nb_temp; nb *= 10.0;
        int_nb_temp = nb;
        str[len] = '0' + int_nb_temp; len++;
    }
    str[len] = '\0'; round_correction(str);
    return str;
}

int float_len(double nb, int prec)
{
    char str[75]; str[74] = '\0';
    int int_nb;
    strfloat(nb, prec, &int_nb, str);
    return my_nbrlen(int_nb) + my_strlen(str);
}

//default precision : 6
int my_putfloat_prec(double nb, int prec)
{
    char str[75]; str[74] = '\0';
    int int_nb;
    strfloat(nb, prec, &int_nb, str);
    (nb < 0) ? my_putchar('-') : 0;
    my_put_nbr(int_nb);
    my_putstr(str);
    return float_len(nb, prec);
}
