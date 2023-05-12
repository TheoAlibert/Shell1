/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** display a float
*/
#include "my.h"

//"precsion" : 6
void my_putfloat(float nb)
{
    if (nb < 0){
        my_putchar('-');
        nb *= -1;
    }
    int int_nb = nb;
    my_put_nbr(int_nb);
    my_putchar('.');
    for (int i = 0; i < 6; i++) {
        nb = (nb - int_nb) * 10;
        int_nb = nb;
        my_putchar(int_nb + '0');
    }
}
