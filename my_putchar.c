/*
** EPITECH PROJECT, 2019
** My_putchar
** File description:
** My_putchar fonction
*/
#include<unistd.h>
#include<stdio.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}
