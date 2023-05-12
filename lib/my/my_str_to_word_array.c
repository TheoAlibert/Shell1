/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** transform a string into a list of alphanumeric words
*/
#include "my.h"

static int is_alphabetic( char c )
{
    if ((c <= 90 && c >= 65) || (c <= 122 && c >= 97)) {
        return 1;
    }
    return 0;
}

static int anum( char c )
{
    if ((c <= 57 && c >= 48) || is_alphabetic(c)) {
        return 1;
    }
    return 0;
}

static int len_word(char const * str, int i)
{
    int len = 0;
    while (anum(str[i + len])) {
        len++;
    }
    return len;
}

static char * set_word(char * word, char const * sentence, int pos, int len)
{
    for (int e = 0; anum(sentence[pos + e]); e++) {
        word[e] = sentence[pos + e];
    }
    word[len] = '\0';
    return word;
}

char ** my_str_to_word_array ( char const * str )
{
    int nb_words = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((i == 0 && anum(str[i])) || (!anum(str[i - 1]) && anum(str[i]))) {
            nb_words++;
        }
    }
    char ** list_words;
    list_words = malloc(sizeof(char *) * (nb_words + 1));
    list_words[nb_words] = NULL;
    int nb = 0;
    for (int i = 0; str[i] != '\0' && nb < nb_words; i++) {
        if ((i == 0 && anum(str[i])) || (!anum(str[i - 1]) && anum(str[i]))) {
            int len = len_word(str, i);
            list_words[nb] = malloc(sizeof(char) * (len + 1));
            list_words[nb] = set_word(list_words[nb], str, i, len);
            nb++;
        }
    }
    return list_words;
}
