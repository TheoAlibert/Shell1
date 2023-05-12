/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** check if the given integer is a prime number
*/
static int is_obvious (int nb)
{
    if (nb > 5 && (nb % 2 == 0 || nb % 3 == 0 || nb % 5 == 0)) {
        return 1;
    }
    if (nb > 13 && (nb % 7 == 0 || nb % 11 == 0 || nb % 13 == 0)) {
        return 1;
    }
    if (nb > 23 && (nb % 17 == 0 || nb % 19 == 0 || nb % 23 == 0)) {
        return 1;
    }
    return 0;
}

static int is_it_prime (int nb)
{
    int is_prime = 1;
    for (int i = 3; i < nb / 2; i += 2) {
        if (nb % i == 0) {
            is_prime = 0;
        }
    }
    return is_prime;
}

int my_is_prime ( int nb )
{
    int is_prime;
    if (nb <= 1 || is_obvious(nb)) {
        return 0;
    }
    if (nb == 2 || nb == 3) {
        return 1;
    }
    is_prime = is_it_prime (nb);
    return is_prime;
}
