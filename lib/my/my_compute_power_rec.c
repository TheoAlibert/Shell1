/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** return the result of n^p
*/
static int no_compute_p (int p)
{
    if (p == 0) {
        return 1;
    }
    return 0;
}

static int no_compute_nb (int nb)
{
    if (nb == 0) {
        return 0;
    }
    if (nb == 1) {
        return 1;
    }
    return 0;
}

static int no_compute ( int nb, int p , int opt)
{
    if (p <= 0 && !opt) {
        return no_compute_p (p);
    }
    if ((nb == 0 || nb == 1) && !opt) {
        return no_compute_nb (nb);
    }
    long product = nb * p;
    if ((product < -2147483648 || product > 2147483647) && opt) {
        return 0;
    }
    return 1;
}

static int compute ( int nb , int p )
{
    int product = 1;
    int no_overflow = 1;
    if (p > 1) {
        no_overflow = no_compute(product, nb, 1);
        product = compute ( nb, p - 1 );
    }
    return product * nb * no_overflow;
}

int my_compute_power_rec ( int nb, int p )
{
    int result;
    if (nb == 0 || nb == 1 || p <= 0 ) {
        return no_compute(nb, p, 0);
    }
    result = compute ( nb, p );
    return result;
}
