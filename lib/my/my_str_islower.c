/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** check if the given string contain only low cases
*/
int my_str_islower ( char const * str )
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(str[i] <= 122 && str[i] >= 97)) {
            return 0;
        }
    }
    return 1;
}
