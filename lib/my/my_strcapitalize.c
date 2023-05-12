/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** transform all caracters to low cases except for the first of each word
*/
static int is_alphabetic( char c )
{
    if ((c <= 90 && c >= 65) || (c <= 122 && c >= 97)) {
        return 1;
    }
    return 0;
}

static int is_alphanumeric( char c )
{
    if ((c <= 97 && c >= 48) || is_alphabetic(c)) {
        return 1;
    }
    return 0;
}

static char change_char(char * str, int i)
{
    if ((str[i] <= 122 && str[i] >= 97) && !is_alphanumeric(str[i - 1])) {
        str[i] -= 32;
    }
    if ((str[i] <= 90 && str[i] >= 65) && is_alphanumeric(str[i - 1])) {
        str[i] += 32;
    }
    return str[i];
}

char * my_strcapitalize ( char * str )
{
    if (str[0] <= 122 && str[0] >= 97) {
        str[0] -= 32;
    }
    for (int i = 1; str[i] != '\0'; i++) {
        if (is_alphabetic(str[i])) {
            str[i] = change_char(str, i);
        }
    }
    return str;
}
