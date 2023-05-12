/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** copy the n first caracters of the source string in the destination string
*/
char * my_strncpy ( char * dest , char const * src , int n )
{
    int len = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (i < n) {
            dest[i] = src[i];
        }
        len++;
    }
    if (n > len) {
        dest[len] = '\0';
    }
    return dest;
}
