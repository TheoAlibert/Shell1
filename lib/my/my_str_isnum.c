/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** check if the given string contain only numbers
*/
int my_str_isnum ( char const * str )
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] <= 57 && str[i] >= 48)) {
            return 0;
        }
    }
    return 1;
}
