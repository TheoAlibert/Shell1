/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** concatenate the source string at the following of the destination one
*/
#include "my.h"

char * my_strcat ( char * dest , char const * src )
{
    int lentt = my_strlen(dest) + my_strlen(src);
    int lend = my_strlen(dest);
    char * pointer;
    int i = 0;
    while (src[i] != '\0') {
        pointer = dest + lend + i;
        *pointer = src[i];
        i++;
    }
    pointer = dest + lentt;
    *pointer = '\0';
    return dest;
}
