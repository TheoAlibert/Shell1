/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** check if the given string contain only alphabetic characters
*/
static int is_low_case (char c)
{
    if (c <= 122 && c >= 97) {
        return 1;
    }
    return 0;
}

static int is_up_case (char c)
{
    if (c <= 90 && c >= 65) {
        return 1;
    }
    return 0;
}

int my_str_isalpha ( char const * str )
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(is_up_case (str[i]) || is_low_case (str[i]))) {
            return 0;
        }
    }
    return 1;
}
