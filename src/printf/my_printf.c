/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf.c
*/

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "printf/printf.h"
#include "printf/flag.h"
#include "printf/print.h"
#include "printf/util.h"

int my_strlen(char const *str)
{
    int length = 0;
    for (; str[length] != '\0'; length++);

    return (length);
}

char *my_strdup(char const *str)
{
    int length = my_strlen(str);
    char *tmp = malloc(sizeof(char) * (length + 1));

    for (int i = 0; i < length; i++)
        tmp[i] = str[i];

    tmp[length] = '\0';

    return (tmp);
}

void register_all_flags(void)
{
    register_flag('b', *print_binary);
    register_flag('o', *print_octal);
    register_flag('c', *print_char);
    register_flag('x', *print_hex_low);
    register_flag('X', *print_hex_up);
    register_flag('i', *print_int);
    register_flag('d', *print_int);
    register_flag('p', *print_ptr);
    register_flag('s', *print_str);
    register_flag('S', *print_big_str);
    register_flag('u', *print_unsigned);
    register_flag('%', *print_escapement);
}

int my_printf(char const *fmt, ...)
{
    char *message = my_strdup(fmt);
    va_list ap;
    int size = 0;

    register_all_flags();
    va_start(ap, fmt);
    while (*message != '\0') {
        if (*message == '%') {
            size += call_flag(&message, ap);
        } else {
            write(1, message, 1);
            size++;
        }
        message++;
    }
    va_end(ap);
    return (size);
}
