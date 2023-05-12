/*
** EPITECH PROJECT, 2022
** ressources for struct_my_printf
** File description:
** function needed to use flag_t
*/
#include "my.h"

flag_t check_flag(const char * format, flag_t flag)
{
    int stop = 0;
    int count = 0;
    for (int i = 0; !stop && format[i] != '\0'; i++) {
        switch (format[i]) {
            case '-': case '+': case ' ': case '#': case '0':
                char to_find[2];
                to_find[0] = format[i]; to_find[1] = '\0';
                if (my_strstr (flag.flag, to_find) == NULL) {
                    flag.flag[count] = format[i];
                    count++;
                }
                flag.f_len++;
                break;
            case '\'': flag.f_len++; break;
            default:
                stop = 1;
        }
    }
    return flag;
}

flag_t check_width(const char * format, flag_t flag, va_list list_args)
{
    int stop = 0;
    for (int i = flag.f_len; !stop && format[i] != '\0'; i++) {
        if (format[i] == '*' && flag.width == 0) {
            int arg = va_arg(list_args, int);
            flag.width = ABS(arg);
            flag.f_len++;
            stop = 1;
        }
        if (format[i] >= '0' && format[i] <= '9') {
            flag.width *= 10;
            flag.width += format[i] - 48;
            flag.f_len++;
            continue;
        }
        stop = 1;
    }
    return flag;
}

flag_t check_prec(const char * format, flag_t flag, va_list list_args)
{
    int stop = 0;
    for (int i = flag.f_len; !stop && format[i] != '\0'; i++) {
        if (format[i] == '.' && flag.precision < 0) {
            flag.precision = 0;
            flag.f_len++; continue;
        }
        if (format[i] == '*' && flag.precision == 0) {
            int arg = va_arg(list_args, int);
            flag.precision = ABS(arg);
            flag.f_len++;
            stop = 1;
        }
        if (format[i] >= '0' && format[i] <= '9' && flag.precision >= 0) {
            flag.precision *= 10;
            flag.precision += format[i] - 48;
            flag.f_len++; continue;
        }
        stop = 1;
    }
    return flag;
}

flag_t check_len(const char * format, flag_t flag)
{
    switch (format[flag.f_len]) {
        case 'h':
            flag.lenght[0] = 'h';
            if (format[flag.f_len + 1] == 'h') {
                flag.lenght[1] = 'h'; flag.f_len++;
            }
            flag.f_len++; break;
        case 'l':
            flag.lenght[0] = 'l';
            if (format[flag.f_len + 1] == 'l') {
                flag.lenght[1] = 'l'; flag.f_len++;
            }
            flag.f_len++; break;
        case 'j': case 'z': case 't': case 'L':
            flag.lenght[0] = format[flag.f_len];
            flag.lenght[1] = '\0';
            flag.f_len++; break;
    }
    return flag;
}

char check_spe(const char c)
{
    switch (c) {
        case 'd': case 'i':
        case 'b': case 'o':
        case 'u': case 'x':
        case 'X':
        case 'f': case 'F':
        case 'e': case 'E':
        case 'g': case 'G':
        case 'a': case 'A':
        case 'c': case 's':
        case 'S':
        case 'p': case 'n':
        case '%':
            return c;
        break;
    }
    return '\0';
}
