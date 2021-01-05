/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** escapement.c
*/

#include <unistd.h>
#include <stdarg.h>
#include "printf/print.h"
#include "printf/util.h"

int print_escapement(va_list args, int format, int space, int zspace)
{
    char c = '%';

    return (write(1, &c, 1));
}
