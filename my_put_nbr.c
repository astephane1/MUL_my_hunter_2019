/*
** EPITECH PROJECT, 2019
** my_put_nbr.c
** File description:
** display the number
*/
#include<unistd.h>

int my_put_nbr(int nbr1, int nbr2)
{
    int a;

    a = 1;
    if (nbr1 < 0) {
        my_putchar('-');
        nbr2 = -nbr1;
    }
    nbr2 = nbr1;
    while (nbr2 > 9) {
        a = a * 10;
        nbr2 = nbr2 / 10;
    }
    while (nbr1 > 9) {
        my_putchar((nbr1 / a) + 48);
        nbr1 = nbr1 % a;
        a = a / 10;
    }
    my_putchar(nbr1 + 48);
}
