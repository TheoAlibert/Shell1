/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** compare the ascii value of the n first caracters of the given strings
** if equal return 0
** if s1 < s2 return a negative number
** if s1 > s2 return a positive value
*/
#include "my.h"

int my_strncmp ( char const * s1, char const * s2, int n )
{
    for (int i = 0; i < biggest_len(s1, s2) && i < n; i++) {
        int d = s1[i] - s2[i];
        if (d != 0) {
            return d;
        }
    }
    return 0;
}
