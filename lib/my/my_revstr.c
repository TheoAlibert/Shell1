/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** reverse the emplacement of all characters in the string
*/
char * my_revstr ( char * str )
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    int l = len - 1;
    if (len % 2 == 0) {
        len /= 2;
    } else {
        len--;
        len /= 2;
    }
    for (int i = 0; i < len; i++) {
        char value_str = str[i];
        str[i] = str[l - i];
        str[l - i] = value_str;
    }
    return str;
}
