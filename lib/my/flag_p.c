/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** function that handle flag p
*/
#include "my.h"

int flag_p(flag_t flag, va_list list_args)
{
    void * d = va_arg(list_args, void *);
    int nb = addresslen(d);
    nb += (my_strstr(flag.flag, "-") == NULL) ? justification(flag, nb) : 0;
    my_put_address(d);
    nb += (my_strstr(flag.flag, "-") != NULL) ? justification(flag, nb) : 0;
    return nb;
}
