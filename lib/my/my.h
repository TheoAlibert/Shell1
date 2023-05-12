/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** header for libmy.a
*/
#ifndef MY
    #define MY
    #include <stdio.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #define ABS(x)  (((x) < 0) ? (x) * -1 : (x))
    #define MAX_PATH_LEN 1024
    void my_putchar(char c);
    int my_isneg(int nb);
    int my_put_nbr(int nb);
    void my_swap(int *a, int *b);
    int my_putstr(char const *str);
    int my_strlen(char const *str);
    int my_getnbr(char const *str);
    void my_putfloat(float nb);
    int my_putfloat_prec(double nb, int prec);
    int my_putsci(double nb, int prec, char opt);
    int my_put_address(void * address);
    int my_compute_power_rec(int nb, int power);
    int my_compute_square_root(int nb);
    int my_is_prime(int nb);
    int my_find_prime_sup(int nb);
    int biggest_len(char const * s1, char const * s2);
    char *my_strcpy(char *dest, char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_revstr(char *str);
    char *my_strstr(char *str, char const *to_find);
    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);
    char *my_strupcase(char *str);
    char *my_strlowcase(char *str);
    char *my_strcapitalize(char *str);
    int my_str_isalpha(char const *str);
    int my_str_isnum(char const *str);
    int my_str_islower(char const *str);
    int my_str_isupper(char const *str);
    int my_str_isprintable(char const *str);
    char *my_strcat(char *dest, char const *src);
    char *my_strncat(char *dest, char const *src, int nb);
    char ** my_str_to_word_array ( char const * str );
    int my_show_word_array ( char * const * tab );
    int my_nbrlen(int nb);
    int my_scilen(double nb, int prec);
    int float_len(double nb, int prec);
    double my_round(double nb, int prec);
    int addresslen(void * address);
    char * my_convert_base(unsigned int dec, char * converted, char spe);
    char * clear_padding_0(char * converted);
    int my_printf ( const char * format, ...);

    typedef struct my_flag {
        int f_len;
        char flag[6];
        int width;
        int precision;
        char lenght[3];
        char specifier;
    } flag_t;

    flag_t set_flag(void);
    flag_t check_flag(const char * format, flag_t flag);
    flag_t check_width(const char * format, flag_t flag, va_list list_args);
    flag_t check_prec(const char * format, flag_t flag, va_list list_args);
    flag_t check_len(const char * format, flag_t flag);
    char check_spe(const char c);
    flag_t get_flag(const char * format, va_list list_args);
    int put_flag(flag_t flag);
    int justification(flag_t flag, int len);
    int flag_i(flag_t flag, va_list list_args);
    int flag_f(flag_t flag, va_list list_args);
    int flag_base(flag_t flag, va_list list_args);
    int flag_e(flag_t flag, va_list list_args);
    int flag_g(flag_t flag, va_list list_args);
    int flag_c(flag_t flag, va_list list_args);
    int flag_s(flag_t flag, va_list list_args);
    int flag_p(flag_t flag, va_list list_args);
#endif
