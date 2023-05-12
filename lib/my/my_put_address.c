/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** Test file
*/
#include "my.h"

static char hex_to_char(int digit)
{
    if (digit >= 0 && digit <= 9) {
        return 48 + digit;
    }
    return 'a' + digit - 10;
}

int addresslen(void * address)
{
    uintptr_t a = (uintptr_t)address;
    int len = 2;
    for (int i = (sizeof(a) << 3) - 20; i >= 0; i -= 4) {
        len++;
    }
    return len;
}

int my_put_address(void * address)
{
    uintptr_t a = (uintptr_t)address;
    my_putchar('0');
    my_putchar('x');
    int len = 2;
    for (int i = (sizeof(a) << 3) - 20; i >= 0; i -= 4) {
        my_putchar(hex_to_char((a >> i) & 0xf)); len++;
    }
    return len;
}
