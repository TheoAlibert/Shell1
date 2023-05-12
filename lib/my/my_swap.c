/*
** EPITECH PROJECT, 2022
** library MY
** File description:
** exchange value between two integer
*/
void my_swap ( int *a , int *b )
{
    int value_a = *a;
    *a = *b;
    *b = value_a;
}
