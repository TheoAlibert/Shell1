/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** function that show merged string with arguments
*/
#include "my.h"

int justification(flag_t flag, int len)
{
    int nb = 0;
    char c = (my_strstr(flag.flag, "0") != NULL) ? '0' : ' ';
    int dist = flag.width - len;
    for (int i = 0; i < dist; i++) {
        my_putchar(c); nb++;
    }
    return nb;
}

//in case of flag, print the corresponding arg and return its lenght
static int flag_handler(flag_t flag, va_list list_args, int nb_ext)
{
    int nb = 0; switch (flag.specifier) {
        case '%': my_putchar('%'); nb = 1; break;
        case 'n': int * ret = va_arg(list_args, int *); *ret = nb_ext; break;
        case 'd': case 'i': nb = flag_i(flag, list_args); break;
        case 'u': case 'b': case 'o': case 'x': case 'X':
            nb = flag_base(flag, list_args); break;
        case 'f': case 'F': nb = flag_f(flag, list_args); break;
        case 'e': case 'E': nb = flag_e(flag, list_args); break;
        case 'g': case 'G': nb = flag_g(flag, list_args); break;
        case 'a': case 'A': put_flag(flag); break;
        case 'c': nb = flag_c(flag, list_args); break;
        case 's': case 'S': nb = flag_s(flag, list_args); break;
        case 'p': nb = flag_p(flag, list_args); break;
    } return nb;
}

int my_printf ( const char * format, ...)
{
    int nb = 0; flag_t flag;
    va_list list_args;
    va_start(list_args, format);
    int len = my_strlen(format);
    for (int i = 0; i < len && *format != '\0'; i++) {
        flag = (*format == '%') ? get_flag(format + 1, list_args) : set_flag();
        if (flag.specifier != '\0') {
            nb += flag_handler(flag, list_args, nb);
            format += flag.f_len;
            continue;
        }
        my_putchar(*format);
        nb++; format++;
    }
    va_end(list_args);
    return nb;
}
