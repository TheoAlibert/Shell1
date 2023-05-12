/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** function that convert a decimal number into another base
*/
#include "my.h"

static int get_base(char spe)
{
    int base = 0;
    switch (spe) {
        case 'b': base = 2; break;
        case 'o': base = 8; break;
        case 'u': base = 10; break;
        case 'x': case 'X': base = 16; break;
    }
    return base;
}

char * my_convert_base(unsigned int dec, char * converted, char spe)
{
    if (dec == 0) {
        converted[0] = '0'; converted[1] = '\0'; return converted;
    }
    int base = get_base(spe); int opt = (spe == 'X') ? 0 : 1;
    int pow = my_strlen(converted); int ret = 0; int i = 0;
    while (pow >= 0) {
        if (my_compute_power_rec(base, pow) * (ret + 1) <= dec) {
            ret++; continue;
        }
        converted[i] = (ret <= 9) ? '0' + ret : 'A' + (ret - 10) + (32 * opt);
        i++; dec -= my_compute_power_rec(base, pow) * ret; ret = 0; pow--;
    }
    return converted;
}

char * clear_padding_0(char * converted)
{
    if (my_strlen(converted) == 1) {
        return converted;
    }
    char * temp = malloc(sizeof(char) * my_strlen(converted));
    my_strcpy(temp, converted);
    while (1) {
        if (*temp != '0') {
            break;
        }
        temp++;
    }
    my_strcpy(converted, temp);
    return converted;
}
