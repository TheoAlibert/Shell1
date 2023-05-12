/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** search the first number in the given string
** if there is no number, 0 is returned
*/
static int check_if_is_number(char c)
{
    if (c >= 0 && c <= 9) {
        return 1;
    } else {
        return 0;
    }
}

static int is_my_number_too_long(long nb, char c, int opt)
{
    if (check_if_is_number(c) && opt == -1 && (nb * 10 + c) > 2147483648) {
        return 0;
    }
    if (check_if_is_number(c) && opt == 1 && (nb * 10 + c) > 2147483647) {
        return 0;
    }
    return 1;
}

static int is_my_number_negative(char c1, char c2, long nb, int opt)
{
    if (nb) {
        return opt;
    }
    int sign_1 = (c1 + 48 == 45);
    int sign_2 = (c2 + 48 == 45 || c2 + 48 == 43);
    if ( sign_1 && (check_if_is_number(c2) || sign_2) ) {
        return opt * -1;
    }
    if ((sign_1 || c1 + 48 == 43) && !(check_if_is_number(c2) || sign_2)) {
        return 1;
    }
    return opt;
}

static int write_in_nb(char c, long nb)
{
    if (check_if_is_number(c)) {
        nb *= 10;
        nb += c;
    }
    return nb;
}

int my_getnbr ( char const * str )
{
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    long nb = 0;
    int no_error = 1;
    int opt = 1;
    for (int i = 0; str[i] != '\0' && no_error; i++) {
        char c = str[i] - 48;
        if (check_if_is_number(c) || !nb) {
            opt = is_my_number_negative(c, str[i + 1] - 48, nb, opt);
            no_error = is_my_number_too_long(nb, c, opt);
            nb = write_in_nb(c, nb);
        } else {
            break;
        }
    }
    return nb * opt * no_error;
}
