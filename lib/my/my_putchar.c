/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** display a given character
*/
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
