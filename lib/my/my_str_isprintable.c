/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** check if the given string contain only printable characters
*/
int my_str_isprintable ( char const * str )
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            return 0;
        }
    }
    return 1;
}
