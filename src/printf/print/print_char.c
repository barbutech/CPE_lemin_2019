/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** print_char.c
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

int print_char(va_list args, int format, int space, int zspace)
{
    char c = (char) va_arg(args, int);
    int size = 0;

    size += write_fmt_pad(format, space, 1);
    size += write(1, &c, 1);
    size += write_fmt_minus(format, space, 1);
    return (size);
}
