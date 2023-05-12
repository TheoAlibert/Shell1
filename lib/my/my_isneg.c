/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** check if the given integer is negative or positive
** 0 is positive
*/
#include "my.h"

int my_isneg ( int n )
{
    if ( n < 0 ) {
        my_putchar(78);
    } else {
        my_putchar(80);
    }
    return 0;
}
