/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** print_int_format.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "printf/print.h"
#include "printf/parser.h"
#include "printf/util.h"

int write_int_fmt_plus(int format, int n)
{
    if (n < 0) {
        return (write(1, "-", 1));
    }
    if ((format & PLUS_FORMAT_MASK) == 0) {
        return (0);
    }
    return (write(1, "+", 1));
}

int write_int_fmt_pad(int format, int space, int zspace, int length)
{
    if ((format & MINUS_FORMAT_MASK) != 0) {
        return (0);
    }
    if ((format & ZPADDED_FORMAT_MASK) != 0) {
        space = (zspace <= length ? space : space - zspace + length);
    }
    if ((format & PLUS_FORMAT_MASK) != 0) {
        space--;
    }
    int size = 0;
    for (int i = 0; i < space - length; i++) {
        size += write(1, " ", 1);
    }
    return (size);
}

int write_int_fmt_zpad(int format, int zspace, int length)
{
    int size = 0;
    for (int i = 0; i < zspace - length; i++) {
        size += write(1, "0", 1);
    }
    return (size);
}

int write_int_fmt_minus(int format, int space, int zspace, int length)
{
    if ((format & MINUS_FORMAT_MASK) == 0) {
        return (0);
    }
    if ((format & ZPADDED_FORMAT_MASK) != 0) {
        space = (zspace <= length ? space : space - zspace + length);
    }
    if ((format & PLUS_FORMAT_MASK) != 0) {
        space--;
    }
    int size = 0;
    for (int i = 0; i < space - length; i++) {
        size += write(1, " ", 1);
    }
    return (size);
}

int write_int_fmt_blank(int format)
{
    if ((format & BLANK_FORMAT_MASK) == 0 ||
    (format & PADDED_FORMAT_MASK) != 0 ||
    (format & PLUS_FORMAT_MASK) != 0) {
        return (0);
    }
    return (write(1, " ", 1));
}
