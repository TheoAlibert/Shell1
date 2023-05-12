/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** mesure the number of char in a number
*/

#include "my.h"

int my_nbrlen(int nb)
{
    int len = 0;
    if (nb < 0) {
        nb *= -1;
        len++;
    }
    while (nb != 0) {
        nb -= nb % 10;
        nb /= 10;
        len++;
    }
    if (len == 0) {
        return 1;
    }
    return len;
}
