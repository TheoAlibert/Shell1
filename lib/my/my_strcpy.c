/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** copy the source string into the destination one
*/
char * my_strcpy ( char * dest , char const * src )
{
    int len = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        dest[i] = src[i];
        len++;
    }
    dest[len] = '\0';
    return dest;
}
