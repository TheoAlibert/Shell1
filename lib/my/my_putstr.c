/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** display a given string
*/
#include "my.h"

int my_putstr ( char const * str )
{
    int len = my_strlen(str);
    for (int i = 0; i < len; i++) {
        my_putchar(*str);
        str++;
    }
    return 0;
}
