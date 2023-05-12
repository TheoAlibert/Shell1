/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** find a string in a source string
** return the found string and the following rest or else NULL
*/
#include "my.h"

//function that test if the proposition is the string to find
static int test_word(char const * str, char const * to_find, int i)
{
    int e = 0;
    while (to_find[e] != '\0') {
        if (to_find[e] != str[i + e]) {
            return 0;
        }
        e++;
    }
    return my_strlen(to_find);
}

char * my_strstr ( char * str, char const * to_find )
{
    int i = 0;
    int e = 0;
    while (str[i] != '\0') {
        if (str[i] == to_find[e]) {
            e = test_word(str, to_find, i);
        }
        if (e == my_strlen(to_find)) {
            return str + i;
        }
        i++;
    }
    return NULL;
}
