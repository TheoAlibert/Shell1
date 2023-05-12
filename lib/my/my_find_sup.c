/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** search the next prime number following the given number
*/
#include "my.h"

int my_find_prime_sup ( int nb )
{
    if (nb <= 1) {
        return 0;
    }
    int one = nb % 2;
    for (int i = nb + 1 + one; i <= 2147483647; i += 2) {
        if (my_is_prime(i)) {
            return i;
        }
    }
    return 0;
}
