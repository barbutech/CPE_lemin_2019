/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** print_byte.c
*/

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "printf/print.h"
#include "printf/parser.h"
#include "printf/util.h"

static int write_fmt_alternate(int format)
{
    if ((format & ALTERNATE_FORMAT_MASK) == 0) {
        return (0);
    }
    return (write(1, "0", 1));
}

static int write_fmt_pad(int format, int space, int zspace, int length)
{
    if ((format & MINUS_FORMAT_MASK) != 0) {
        return (0);
    }
    if ((format & ALTERNATE_FORMAT_MASK) != 0
    && (format & ZPADDED_FORMAT_MASK) == 0) {
        space--;
    }
    if ((format & ZPADDED_FORMAT_MASK) != 0) {
        space = (zspace <= length ? space : space - zspace + length);
    }
    int size = 0;
    for (int i = 0; i < space - length; i++) {
        size += write(1, " ", 1);
    }
    return (size);
}

static int write_fmt_zpad(int format, int zspace, int length)
{
    if ((format & ALTERNATE_FORMAT_MASK) != 0) {
        zspace--;
    }
    int size = 0;
    for (int i = 0; i < zspace - length; i++) {
        size += write(1, "0", 1);
    }
    return (size);
}

static int write_fmt_minus(int format, int space, int zspace, int length)
{
    if ((format & MINUS_FORMAT_MASK) == 0) {
        return (0);
    }
    if ((format & ALTERNATE_FORMAT_MASK) != 0
    && (format & ZPADDED_FORMAT_MASK) == 0) {
        space--;
    }
    if ((format & ZPADDED_FORMAT_MASK) != 0) {
        space = (zspace <= length ? space : space - zspace + length);
    }
    int size = 0;
    for (int i = 0; i < space - length; i++) {
        size += write(1, " ", 1);
    }
    return (size);
}

int print_octal(va_list args, int format, int space, int zspace)
{
    unsigned int nb = va_arg(args, unsigned int);
    char *result = malloc(sizeof(char));
    int length = 0;
    int size = 0;

    length = convert_base(nb, "01234567", 8, &result);
    size += write_fmt_pad(format, space, zspace, length);
    size += write_fmt_zpad(format, zspace, length);
    size += write_fmt_alternate(format);
    size += write(1, result, length);
    size += write_fmt_minus(format, space, zspace, length);
    return (size);
}
