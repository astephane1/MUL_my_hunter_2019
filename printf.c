/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/
#include <stdarg.h>
#include <stdlib.h>
#include<unistd.h>

char my_printf(char *string, ...)
{
    int strf = my_strlen(string);
    va_list type;
    va_start(type, string);
    for (int i = 0; i < strf; i++) {
        if ( string[i] == '%') {
            i++;
            while (string[i] == ' ')
                i++;
            switch (string[i]) {
            case '+' :
                my_putchar('+');
                my_put_nbr(va_arg(type, int));
                break;
            case 'c' :
                my_putchar(va_arg(type, int));
                break;
            case 's' :
            case 'S' :
                my_putstr( va_arg(type, char * ));
                break;
            case 'i' :
            case 'd' :
                my_put_nbr(va_arg(type, int));
                break;
            default :
                my_putchar('%');
                my_putchar(string[i]);
            }
        } else
            my_putchar(string[i]);
    }
    va_end(type);
}
