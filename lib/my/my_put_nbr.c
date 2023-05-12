/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** display a given number
*/
#include "my.h"

static void my_recursive_function( int nb )
{
    if (nb != 0) {
        int digit = nb % 10;
        nb -= digit;
        nb /= 10;
        my_recursive_function( nb );
        my_putchar('0' + digit);
    }
}

static int neg_handle(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    return nb;
}

int my_put_nbr( int nb )
{
    if (nb == 0) {
        my_putchar('0');
        return 0;
    }
    if (nb == -2147483648) {
        nb += 8; nb /= 10; nb = neg_handle(nb);
        my_recursive_function( nb );
        my_putchar('8');
        return 0;
    }
    nb = neg_handle(nb);
    my_recursive_function( nb );
    return 0;
}
