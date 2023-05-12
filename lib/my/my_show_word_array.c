/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** display all string in a list of string
*/
#include "my.h"

int my_show_word_array ( char * const * tab )
{
    for (int i = 0; tab[i] != NULL; i++) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}
