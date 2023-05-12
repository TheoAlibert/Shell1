/*
** EPITECH PROJECT, 2022
** struct_my_printf
** File description:
** function needed to use flag_t
*/
#include "my.h"

flag_t set_flag(void)
{
    flag_t flag;
    flag.f_len = 0;
    flag.flag[0] = '\0';
    flag.flag[5] = '\0';
    flag.width = 0;
    flag.precision = -1;
    flag.lenght[0] = '\0';
    flag.lenght[2] = '\0';
    flag.specifier = '\0';
    return flag;
}

flag_t get_flag(const char * format, va_list list_args)
{
    flag_t flag = set_flag();
    flag = check_flag(format, flag);
    flag = check_width(format, flag, list_args);
    flag = check_prec(format, flag, list_args);
    flag = check_len(format, flag);
    flag.specifier = check_spe(format[flag.f_len]);
    flag.f_len += 2;
    return flag;
}

//just for tests
int put_flag(flag_t flag)
{
    my_putstr("%[");
    my_putstr(flag.flag);
    my_putstr("][");
    my_put_nbr(flag.width);
    my_putstr("][.");
    my_put_nbr(flag.precision);
    my_putstr("][");
    my_putstr(flag.lenght);
    my_putchar(']');
    my_putchar(flag.specifier);
    return 0;
}
