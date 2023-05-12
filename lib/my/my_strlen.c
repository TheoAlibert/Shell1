/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** mesure the lenght of the given string
*/
int my_strlen ( char const * str )
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}
