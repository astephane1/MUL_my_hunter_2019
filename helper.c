/*
** EPITECH PROJECT, 2019
** helper.c
** File description:
** help for the execution of program
*/
#include <SFML/Graphics.h>
#include <time.h>
#include <stdlib.h>

void help(void)
{
    my_putstr("**************************\n");
    my_putstr("ANGRY BIRD's HELPER\n");
    my_putstr("**************************\n");
    my_putstr("\n");
    my_putstr("HOW DOES IT PLAY ?\n");
    my_putstr("The goal of the game is to kill as many birds as possible.");
    my_putstr("\nFor this you just have to left-click on the birds.\n");
    my_putstr("Every time you hit the bird, the score increases by 100");
    my_putstr("\n");
}
