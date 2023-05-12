/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** return the biggest lenght between two strings
*/
int biggest_len(char const * s1, char const * s2)
{
    int len1 = 0;
    for (int i = 0; s1[i] != '\0'; i++) {
        len1++;
    }
    int len2 = 0;
    for (int i = 0; s2[i] != '\0'; i++) {
        len2++;
    }
    if (len1 >= len2) {
        return len1;
    } else {
        return len2;
    }
}
