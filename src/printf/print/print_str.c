/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** print_str.c
*/

#include <unistd.h>
#include <stdarg.h>
#include "printf/print.h"
#include "printf/parser.h"
#include "printf/util.h"

static int write_fmt_pad(int format, int space, int length)
{
    if ((format & MINUS_FORMAT_MASK) != 0) {
        return (0);
    }
    int size = 0;
    for (int i = 0; i < space - length; i++) {
        size += write(1, " ", 1);
    }
    return (size);
}

static int write_fmt_minus(int format, int space, int length)
{
    if ((format & MINUS_FORMAT_MASK) == 0) {
        return (0);
    }
    int size = 0;
    for (int i = 0; i < space - length; i++) {
        size += write(1, " ", 1);
    }
    return (size);
}

int print_str(va_list args, int format, int space, int zspace)
{
    char *str = va_arg(args, char *);
    int length = my_strlen(str);
    int size = 0;

    size += write_fmt_pad(format, space, length);
    size += write(1, str, length);
    size += write_fmt_minus(format, space, length);
    return (size);
}
