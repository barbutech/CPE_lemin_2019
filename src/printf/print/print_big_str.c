/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** print_big_str.c
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

static char *convert_in_octal(int nb)
{
    char *result = malloc(sizeof(char) * 3);
    int size = 0;

    for (int i = 1; i < 3; i++)
        result[i] = '\0';
    result[size++] = '\\';
    if (nb < 8)
        result[size++] = '0';
    if (nb < 64)
        result[size++] = '0';
    char *convert = malloc(sizeof(char));
    convert_base(nb, "01234567", 8, &convert);
    result = append_string(result, size, convert);
    return (result);
}

int print_big_str(va_list args, int format, int space, int zspace)
{
    char *str = va_arg(args, char *);
    char *result = malloc(sizeof(char));
    int length = 0;
    int size = 0;

    for (int i = 0; str[i] != '\0'; i++, length++) {
        if (my_char_isprintable(str[i])) {
            result = append_char(result, length, str[i]);
            continue;
        }
        result = append_string(result, length, convert_in_octal(str[i]));
        length += 3;
    }
    size += write_fmt_pad(format, space, length);
    size += write(1, result, length);
    size += write_fmt_minus(format, space, length);
    return (size);
}
