/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** concatenate the n first caracters of the source string
** at the following of the destination one
*/
#include "my.h"

char * my_strncat ( char * dest, char const * src, int nb )
{
    int lentt = my_strlen(dest) + nb;
    int lend = my_strlen(dest);
    char * pointer;
    int i = 0;
    while (src[i] != '\0' && i < nb) {
        pointer = dest + lend + i;
        *pointer = src[i];
        i++;
    }
    pointer = dest + lentt;
    *pointer = '\0';
    return dest;
}
