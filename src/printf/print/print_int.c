/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** print_int.c
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "printf/print.h"
#include "printf/parser.h"
#include "printf/util.h"

int write_int_fmt_plus(int format, int n);
int write_int_fmt_pad(int format, int space, int zspace, int length);
int write_int_fmt_zpad(int format, int zspace, int length);
int write_int_fmt_minus(int format, int space, int zspace, int length);
int write_int_fmt_blank(int format);

static int my_put_nbr(int n, int shift, char **result)
{
    int size = 0;

    if (n >= 10) {
        size += my_put_nbr(n / 10, shift, result);
    }
    *result = append_char(*result, shift + size, (n % 10) + '0');
    return (size + 1);
}

static int make_pos(int n, char **result, int *length, int *is_neg)
{
    if (n >= 0) {
        return (n);
    }
    *is_neg = 1;
    if (n == -2147483648) {
        *result = append_char(*result, *length, '2');
        n = -147483648;
        (*length)++;
    }
    return (n * -1);
}

int print_int(va_list args, int format, int space, int zspace)
{
    int length = 0;
    int size = 0;
    int nb = va_arg(args, int);
    int is_neg = 0;
    int n = nb;
    char *result = malloc(sizeof(char));
    n = make_pos(nb, &result, &length, &is_neg);
    length += my_put_nbr(n, length, &result);
    int space2 = (is_neg ? space + 1 : space);
    int zspace2 = (is_neg ? zspace + 1 : zspace);
    int length2 = (is_neg ? length + 1 : length);
    size += write_int_fmt_blank(format);
    size += write_int_fmt_pad(format, space, zspace2, length2);
    size += write_int_fmt_plus(format, nb);
    size += write_int_fmt_zpad(format, zspace, length);
    size += write(1, result, length);
    size += write_int_fmt_minus(format, space2, zspace2, length2);
    return (size);
}
