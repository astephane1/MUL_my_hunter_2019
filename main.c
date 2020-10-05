/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** principal functions
*/
#include <SFML/Graphics.h>
#include <time.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return (0);
    } else
        play();
    return (0);
}
