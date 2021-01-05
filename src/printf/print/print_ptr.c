/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** print_char.c
*/

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
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

int print_ptr(va_list args, int format, int space, int zspace)
{
    unsigned int ptr = va_arg(args, unsigned int);
    char *result = malloc(sizeof(char));
    char *convert = malloc(sizeof(char));
    int length = 0;
    int size = 0;

    result = append_char(result, 0, '0');
    result = append_char(result, 1, 'x');
    length += convert_base(ptr, "0123456789abcdef", 16, &convert);
    result = append_string(result, 2, convert);
    length += 2;
    size += write_fmt_pad(format, space, length);
    size += write(1, result, length);
    size += write_fmt_minus(format, space, length);
    return (size);
}
