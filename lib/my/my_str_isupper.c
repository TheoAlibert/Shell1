/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** check if the given string contain only up cases
*/
int my_str_isupper ( char const * str )
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] <= 90 && str[i] >= 65)) {
            return 0;
        }
    }
    return 1;
}
