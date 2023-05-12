/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** return the square root of the given integer
*/
static int compute ( int nb )
{
    for (int i = 2; i < nb; i++) {
        if (i > 46340) {
            return 1;
        }
        if (i * i == nb) {
            return i;
        }
    }
    return 0;
}

int my_compute_square_root ( int nb )
{
    if (nb <= 0) {
        return 0;
    }
    if (nb == 1) {
        return 1;
    }
    int root = 0;
    root = compute(nb);
    if (root == 1 || root == nb) {
        root = 0;
    }
    return root;
}
