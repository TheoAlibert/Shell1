/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** transform all low cases to up cases
*/
char * my_strupcase ( char * str )
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 122 && str[i] >= 97) {
            str[i] -= 32;
        }
    }
    return str;
}
